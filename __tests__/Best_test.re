open Jest;
open Expect;

testAll(
  "color contrasts",
  [
    ("#ffffff", "#000000", "#ffffff", "#000000"),
    ("#ffffff", "#000000", "#000000", "#ffffff"),
    ("rgb(255,255,255)", "#000000", "#979798", "#000000"),
    ("rgb(255,255,255)", "#000000", "#fd8b56", "#000000"),
    ("hsl(0,0,100%)", "#000000", "#3e74b1", "hsl(0,0,100%)"),
  ],
  ((one, two, bg, expected)) =>
  expect(Best.calculate(one, two, bg)) |> toEqual(expected)
);
