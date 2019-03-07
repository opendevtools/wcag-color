open Jest;
open Expect;

testAll(
  "#calculateFromRatio",
  [(7.1, "AAA"), (4.6, "AA"), (3.9, "AA Large"), (2.9, "Fail")],
  ((ratio, score)) =>
  expect(Score.calculateFromRatio(ratio)) |> toEqual(score)
);

testAll(
  "#calculate",
  [
    ("#ffffff", "#000000", "AAA"),
    ("#ffffff", "#666666", "AA"),
    ("#ffffff", "#888888", "AA Large"),
    ("#ffffff", "#cccccc", "Fail"),
  ],
  ((foreground, background, score)) =>
  expect(Score.calculate(foreground, background)) |> toEqual(score)
);
