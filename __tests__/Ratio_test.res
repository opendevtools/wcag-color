open Jest;
open Expect;

testAll(
  "color contrasts",
  list{
    ("#ffffff", "#ffffff", 1.0),
    ("ffffff", "ffffff", 1.0),
    ("rgb(255, 255, 255)", "rgb(255, 255, 255)", 1.0),
    ("rgb(255,255,255)", "rgb(255, 255, 255)", 1.0),
    ("hsl(255, 30%, 40%)", "hsl(255, 30%, 40%)", 1.0),
    ("hsl(255,30,40)", "hsl(255, 30%, 40%)", 1.0),
    ("#ffffff", "rgb(255, 255, 255)", 1.0),
    ("#ffffff", "#000000", 21.0),
    ("#ffffff", "#777777", 4.48),
    ("#0088FF", "#C611AB", 1.47),
    ("ffffff", "777777", 4.48),
    ("fff", "777", 4.48),
    ("08f", "fff", 3.52),
    ("rgb(255,255,255)", "#777777", 4.48),
    ("rgb(255,255,255)", "rgb(77,77,77)", 8.45),
    ("hsl(0, 0%, 20%)", "#ffffff", 12.63),
    ("hsl(210, 30%, 48%)", "#ffffff", 4.47),
    ("hsl(210, 30%, 68%)", "#ffffff", 2.31),
    ("hsl(0, 0%, 20%)", "hsl(0, 0%, 100%)", 12.63),
    ("hsl(0, 100%, 40%)", "#fff", 5.89),
    ("hsl(360, 100%, 40%)", "#fff", 5.89),
  },
  ((fg, bg, expected)) =>
  expect(Ratio.calculate(fg, bg)) |> toEqual(expected)
);