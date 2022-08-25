let calculateFromRatio = ratio =>
  switch ratio {
  | r if r >= 7.0 => "AAA"
  | r if r >= 4.5 => "AA"
  | r if r >= 3.0 => "AA Large"
  | _ => "Fail"
  }

let calculate = (foreground, background) =>
  Ratio.calculate(foreground, background) |> calculateFromRatio
