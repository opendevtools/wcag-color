let toNumbers = rgb => {
  switch rgb->Js.String2.match_(%re("/\\d+\\.?\\d?/g")) {
  | Some(colors) => colors->Js.Array2.map(x => x->float_of_string)
  | None => []
  }
}

let fromRgba = (fg, bg) => {
  switch (fg, bg) {
  | ([r, g, b, a], [r2, g2, b2, _])
  | ([r, g, b, a], [r2, g2, b2]) => {
      let alpha = if a > 1. {
        a /. 255.
      } else {
        a
      }

      let r3 = Js.Math.round((1. -. alpha) *. r2 +. alpha *. r)
      let g3 = Js.Math.round((1. -. alpha) *. g2 +. alpha *. g)
      let b3 = Js.Math.round((1. -. alpha) *. b2 +. alpha *. b)

      [r3, g3, b3]
    }
  | _ => []
  }
}

let make = (fg, bg) => {
  let updatedFg = fg->toNumbers

  switch Js.Array.length(updatedFg) {
  | 4 => updatedFg->fromRgba(bg->toNumbers)
  | _ => updatedFg
  }
}
