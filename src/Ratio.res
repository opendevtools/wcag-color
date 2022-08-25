type t =
  | HSL
  | RGB
  | HEX

let typeOfColor = color =>
  switch color->Js.String2.substring(~from=0, ~to_=3) {
  | "rgb" => RGB
  | "hsl" => HSL
  | _ => HEX
  }

let parseNumbers = rgb => {
  switch rgb->Js.String2.match_(%re("/\d+/g")) {
  | Some(colors) => colors->Js.Array2.map(x => x->Belt.Option.getWithDefault("")->float_of_string)
  | None => []
  }
}

let parseColor = color =>
  switch color->typeOfColor {
  | HEX => color->HEX.convert
  | HSL => color->parseNumbers->HSL.convert
  | RGB => color->parseNumbers
  }
  ->Luminance.convert
  ->(v => v +. 0.05)

let calculate = (foreground, background) => {
  switch (Utils.removeHash(foreground), Utils.removeHash(background)) {
  | (fg, bg) if fg === bg => 1.0
  | (fg, bg) =>
    switch (parseColor(fg), parseColor(bg)) {
    | (f, b) if f > b => f /. b
    | (f, b) => b /. f
    }
    |> Js.Float.toFixedWithPrecision(~digits=2)
    |> Js.Float.fromString
  }
}
