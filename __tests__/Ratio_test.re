open Jest;
open Expect;

testAll(
  "colors are equal",
  [
    ("#ffffff", "#ffffff"),
    ("ffffff", "ffffff"),
    ("rgb(255, 255, 255)", "rgb(255, 255, 255)"),
    ("rgb(255,255,255)", "rgb(255, 255, 255)"),
    ("hsl(255, 30%, 40%)", "hsl(255, 30%, 40%)"),
    ("hsl(255,30,40)", "hsl(255, 30%, 40%)"),
    ("#ffffff", "rgb(255, 255, 255)"),
  ],
  ((fg, bg)) =>
  expect(Ratio.calculate(fg, bg)) |> toEqual(1.0)
);

describe("#calculate", () => {
  test("handles white on black", () =>
    expect(Ratio.calculate("#ffffff", "#000000")) |> toEqual(21.0)
  );

  test("handles white on grayish", () =>
    expect(Ratio.calculate("#ffffff", "#777777")) |> toEqual(4.48)
  );

  test("handles random colors (blue on pink)", () =>
    expect(Ratio.calculate("#0088FF", "#C611AB")) |> toEqual(1.47)
  );

  test("handles hex without hash", () =>
    expect(Ratio.calculate("ffffff", "777777")) |> toEqual(4.48)
  );

  test("handles hex with shorthand", () =>
    expect(Ratio.calculate("fff", "777")) |> toEqual(4.48)
  );

  test("handles hex with non-uniform shorthand", () =>
    expect(Ratio.calculate("08f", "fff")) |> toEqual(3.52)
  );

  test("handles rgb colors", () =>
    expect(Ratio.calculate("rgb(255,255,255)", "#777777")) |> toEqual(4.48)
  );

  test("handles two rgb colors", () =>
    expect(Ratio.calculate("rgb(255,255,255)", "rgb(77,77,77)"))
    |> toEqual(8.45)
  );

  test("handles hsl colors without saturation", () =>
    expect(Ratio.calculate("hsl(0, 0%, 20%)", "#ffffff")) |> toEqual(12.63)
  );

  test("handles hsl colors with lightness lower than 50", () =>
    expect(Ratio.calculate("hsl(210, 30%, 48%)", "#ffffff"))
    |> toEqual(4.47)
  );

  test("handles hsl colors with lightness higher than 50", () =>
    expect(Ratio.calculate("hsl(210, 30%, 68%)", "#ffffff"))
    |> toEqual(2.35)
  );

  test("handles two hsl colors", () =>
    expect(Ratio.calculate("hsl(0, 0%, 20%)", "hsl(0, 0%, 100%)"))
    |> toEqual(12.63)
  );
});
