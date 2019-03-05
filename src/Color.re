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

let parseNumbers = rgb => {
  switch (rgb |> Js.String.match([%re "/\\d+/g"])) {
  | Some(colors) => colors |> Js.Array.map(x => x->float_of_string)
  | None => [||]
  };
};

let parseColor = color =>
  (
    switch (color |> typeOfColor) {
    | HEX => color |> HEX.convert
    | HSL => color |> parseNumbers |> HSL.convert
    | RGB => color |> parseNumbers
    }
  )
  |> Luminance.convert
  |> (v => v +. 0.05);

let score = (foreground, background) => {
  switch (foreground |> Utils.removeHash, background |> Utils.removeHash) {
  | (fg, bg) when fg === bg => 1.0
  | (fg, bg) =>
    (
      switch (fg |> parseColor, bg |> parseColor) {
      | (f, b) when f > b => f /. b
      | (f, b) => b /. f
      }
    )
    |> Js.Float.toFixedWithPrecision(~digits=2)
    |> Js.Float.fromString
  };
};
