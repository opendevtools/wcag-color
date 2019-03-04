open Jest;
open Expect;

describe("#contrast", () => {
  test("handles white on black", () =>
    expect(Color.contrast("#ffffff", "#000000")) |> toEqual(21.0)
  );

  test("handles white on grayish", () =>
    expect(Color.contrast("#ffffff", "#777777")) |> toEqual(4.48)
  );

  test("handles rgb colors", () =>
    expect(Color.contrast("rgb(255,255,255)", "#777777")) |> toEqual(4.48)
  );

  test("handles two rgb colors", () =>
    expect(Color.contrast("rgb(255,255,255)", "rgb(77,77,77)"))
    |> toEqual(8.45)
  );

  test("handles hsl colors without saturation", () =>
    expect(Color.contrast("hsl(0, 0%, 20%)", "#ffffff")) |> toEqual(12.63)
  );

  test("handles hsl colors with lightness lower than 50", () =>
    expect(Color.contrast("hsl(210, 30%, 48%)", "#ffffff")) |> toEqual(4.47)
  );

  test("handles hsl colors with lightness higher than 50", () =>
    expect(Color.contrast("hsl(210, 30%, 68%)", "#ffffff")) |> toEqual(2.31)
  );

  test("handles two hsl colors", () =>
    expect(Color.contrast("hsl(0, 0%, 20%)", "hsl(0, 0%, 100%)"))
    |> toEqual(12.63)
  );
});
