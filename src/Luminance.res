let toSRGB = color => color /. 255.0
let toRGB = color =>
  color <= 0.03928 ? color /. 12.92 : Js.Math.pow_float(~base=(color +. 0.055) /. 1.055, ~exp=2.4)

let relative = rgb =>
  switch rgb {
  | [r, g, b] => r *. 0.2126 +. g *. 0.7152 +. b *. 0.0722
  | _ => 0.0
  }

/*
 * https://www.w3.org/WAI/GL/wiki/Relative_luminance
 */
let convert = color => {
  open Js.Array

  color |> map(toSRGB) |> map(toRGB) |> relative
}
