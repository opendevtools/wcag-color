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
  expect(Color.score(fg, bg)) |> toEqual(1.0)
);

describe("#score", () => {
  test("handles white on black", () =>
    expect(Color.score("#ffffff", "#000000")) |> toEqual(21.0)
  );

  test("handles white on grayish", () =>
    expect(Color.score("#ffffff", "#777777")) |> toEqual(4.48)
  );

  test("handles random colors (blue on pink)", () =>
    expect(Color.score("#0088FF", "#C611AB")) |> toEqual(1.47)
  );

  test("handles hex without hash", () =>
    expect(Color.score("ffffff", "777777")) |> toEqual(4.48)
  );

  test("handles hex with shorthand", () =>
    expect(Color.score("fff", "777")) |> toEqual(4.48)
  );

  test("handles hex with non-uniform shorthand", () =>
    expect(Color.score("08f", "fff")) |> toEqual(3.52)
  );

  test("handles rgb colors", () =>
    expect(Color.score("rgb(255,255,255)", "#777777")) |> toEqual(4.48)
  );

  test("handles two rgb colors", () =>
    expect(Color.score("rgb(255,255,255)", "rgb(77,77,77)"))
    |> toEqual(8.45)
  );

  test("handles hsl colors without saturation", () =>
    expect(Color.score("hsl(0, 0%, 20%)", "#ffffff")) |> toEqual(12.63)
  );

  test("handles hsl colors with lightness lower than 50", () =>
    expect(Color.score("hsl(210, 30%, 48%)", "#ffffff")) |> toEqual(4.47)
  );

  test("handles hsl colors with lightness higher than 50", () =>
    expect(Color.score("hsl(210, 30%, 68%)", "#ffffff")) |> toEqual(2.31)
  );

  test("handles two hsl colors", () =>
    expect(Color.score("hsl(0, 0%, 20%)", "hsl(0, 0%, 100%)"))
    |> toEqual(12.63)
  );
});
