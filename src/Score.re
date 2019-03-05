let calculateFromRatio = ratio =>
  switch (ratio) {
  | r when r >= 7.0 => "AAA"
  | r when r >= 4.5 => "AA"
  | r when r >= 3.0 => "AA Large"
  | _ => "Fail"
  };

let calculate = (foreground, background) =>
  Ratio.calculate(foreground, background) |> calculateFromRatio;
