type t =
  | HSL
  | RGB
  | HEX;

let typeOfColor = color =>
  switch (color |> Js.String.substring(~from=0, ~to_=3)) {
  | "rgb" => RGB
  | "hsl" => HSL
  | _ => HEX
  };

let hexToRgb = hex => {
  hex
  |> Js.String.replace("#", "")
  |> (
    t => Js.String.match([%re "/.{2}/g"], t)->Belt.Option.getWithDefault([||])
  )
  |> Js.Array.map(x => ("0x" ++ x)->int_of_string->float_of_int);
};

let relativeLuminance = rgb => {
  Belt.Array.(
    rgb
    ->map(c => c /. 255.0)
    ->map(c =>
        c <= 0.03928
          ? c /. 12.92
          : Js.Math.pow_float(~base=(c +. 0.055) /. 1.055, ~exp=2.4)
      )
    /* TODO: same value when 51,51,51? */
    ->reduceWithIndex(0.0, (acc, c, i) =>
        acc
        +. c
        *. (
          switch (i) {
          | 0 => 0.2126
          | 1 => 0.7152
          | _ => 0.0722
          }
        )
      )
  );
};

let hueToRgb = (p, q, t) => {
  switch (t) {
  | x when x < 1.0 /. 6.0 => p +. (q -. p) *. 6.0 *. x
  | x when x < 0.5 => q
  | x when x < 2.0 /. 3.0 => p +. (q -. p) *. (2.0 /. 3.0 -. x) *. 6.0
  | _ => p
  };
};

let createRgbFromHsl = (h, q, p) => {
  let hue = h /. 360.0;
  let tempR = hue +. 1.0 /. 3.0;
  let tempB = hue -. 1.0 /. 3.0;

  let r = hueToRgb(p, q, tempR) *. 255.0;
  let g = hueToRgb(p, q, hue) *. 255.0;
  let b = hueToRgb(p, q, tempB) *. 255.0;

  [|r, g, b|];
};

let hslToRgb = hsl => {
  switch (hsl) {
  | [|_, 0.0, l|] =>
    let hex = l /. 100.0 *. 255.0;
    [|hex, hex, hex|];
  | [|h, s, l|] when l < 50.0 =>
    let q = l /. 100.0 *. (1.0 +. s /. 100.0);
    let p = 2.0 *. (l /. 100.0) -. q;

    createRgbFromHsl(h, q, p);
  | [|h, s, l|] =>
    let q = l /. 100.0 +. s /. 100.0 -. l /. 100.0 *. s /. 100.0;
    let p = 2.0 *. (l /. 100.0) -. q;

    createRgbFromHsl(h, q, p);
  | _ => [||]
  };
};

let splitRgb = rgb => {
  switch (rgb |> Js.String.match([%re "/\\d+/g"])) {
  | Some(colors) => colors->Belt.Array.map(x => x->float_of_string)
  | None => [||]
  };
};

let contrast = (fg, bg) => {
  let foreground =
    switch (fg |> typeOfColor) {
    | HEX => fg |> hexToRgb |> relativeLuminance
    | HSL => fg |> splitRgb |> hslToRgb |> relativeLuminance
    | RGB => fg |> splitRgb |> relativeLuminance
    };

  let background =
    switch (bg |> typeOfColor) {
    | HEX => bg |> hexToRgb |> relativeLuminance
    | RGB => bg |> splitRgb |> relativeLuminance
    | HSL => bg |> splitRgb |> hslToRgb |> relativeLuminance
    };

  (
    switch (foreground, background) {
    | (f, b) when f > b => (foreground +. 0.05) /. (background +. 0.05)
    | _ => (background +. 0.05) /. (foreground +. 0.05)
    }
  )
  |> Js.Float.toFixedWithPrecision(~digits=2)
  |> Js.Float.fromString;
};
