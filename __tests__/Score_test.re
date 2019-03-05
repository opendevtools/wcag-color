open Jest;
open Expect;

describe("#calculateFromRatio", () => {
  test("handles AAA", () =>
    expect(Score.calculateFromRatio(7.1)) |> toEqual("AAA")
  );

  test("handles AA", () =>
    expect(Score.calculateFromRatio(4.6)) |> toEqual("AA")
  );

  test("handles AA Large", () =>
    expect(Score.calculateFromRatio(3.9)) |> toEqual("AA Large")
  );

  test("handles white on grayish", () =>
    expect(Score.calculateFromRatio(2.9)) |> toEqual("Fail")
  );
});

describe("#calculate", () => {
  test("handles AAA", () =>
    expect(Score.calculate("#ffffff", "#000000")) |> toEqual("AAA")
  );

  test("handles AA", () =>
    expect(Score.calculate("#ffffff", "#666666")) |> toEqual("AA")
  );

  test("handles AA Large", () =>
    expect(Score.calculate("#ffffff", "#888888")) |> toEqual("AA Large")
  );

  test("handles white on grayish", () =>
    expect(Score.calculate("#ffffff", "#cccccc")) |> toEqual("Fail")
  );
});
