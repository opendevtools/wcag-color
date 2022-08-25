let hueToRgb = (p, q, t) => {
  switch t {
  | x if x < 1.0 /. 6.0 => p +. (q -. p) *. 6.0 *. x
  | x if x < 0.5 => q
  | x if x < 2.0 /. 3.0 => p +. (q -. p) *. 6.0 *. (2.0 /. 3.0 -. x)
  | _ => p
  }
}

let createRgbFromHsl = (h, s, l) => {
  /* Get hue by rotation (360deg) */
  let hue = h /. 3.6
  let tempR = hue +. 1.0 /. 3.0
  let tempB = hue -. 1.0 /. 3.0

  let q = switch l {
  | l if l < 0.5 => l *. (1.0 +. s)
  | _ => l +. s -. l *. s
  }
  let p = 2.0 *. l -. q
  let rgb = hueToRgb(p, q)

  let b = switch tempB {
  | x if x < 0. => 0.
  | x => x
  }

  [rgb(tempR), rgb(hue), rgb(b)]
}

/*
 * http://www.niwa.nu/2013/05/math-behind-colorspace-conversions-rgb-hsl/
 * https://gist.github.com/mjackson/5311256
 */
let convert = hsl => {
  hsl
  ->Js.Array2.map(x => x /. 100.0)
  ->(hsl =>
    switch hsl {
    | [_, 0.0, l] => [l, l, l]
    | [h, s, l] if h === 3.6 => createRgbFromHsl(0., s, l)
    | [h, s, l] => createRgbFromHsl(h, s, l)
    | _ => []
    })
  ->Js.Array2.map(x => x *. 255.0)
}
