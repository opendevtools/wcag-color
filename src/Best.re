let calculate = (first, second, background) => {
  let firstRatio = Ratio.calculate(first, background);
  let secondRatio = Ratio.calculate(second, background);

  firstRatio > secondRatio ? first : second;
};
