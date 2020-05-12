# WCAG Color

[![npm version](https://badge.fury.io/js/wcag-color.svg)](https://badge.fury.io/js/wcag-color)
[![](https://github.com/believer/wcag-color/workflows/Release/badge.svg)](https://github.com/believer/wcag-color/actions?workflow=Release)

According to the WHO an [estimated 1.3 billion](https://www.who.int/en/news-room/fact-sheets/detail/blindness-and-visual-impairment)
people live with some form of visual impairment. This includes people who are legally blind and people with less than 20/20 vision.

This library helps you achieve the accessibility standards for **color contrast** outlined in the [WCAG 2.0](https://www.w3.org/WAI/standards-guidelines/wcag/) specification.

## Installation

```
npm install wcag-color
```

## API

### Ratio

`ratio` takes two colors, a foreground color, and background color, and returns a contrast ratio. `ratio` accepts most color formats:

- **HEX** - normal (`#0088ff`), shorthand (`#08f`) and without hash (`08f`)
- **RGB** - `rgb(255, 255, 255)`
- **HSL** - `hsl(210, 100%, 40%)`

```js
ratio(foreground: string, background: string) => number
```

#### Example

```js
import { ratio } from 'wcag-color'

ratio('hsl(210, 100%, 40%)', '#ffffff') // 5.57
```

### Score

`score` takes two colors and returns a score value. Read more below.

```js
score(foreground: string, background: string) => 'Fail' | 'AA Large' | 'AA' | 'AAA'
```

#### Example

```js
import { score } from 'wcag-color'

score('hsl(210, 100%, 40%)', '#ffffff') // AA
```

### Score from ratio

`scoreFromRatio` takes a ratio and returns a score value.

```js
scoreFromRatio(ratio: number) => 'Fail' | 'AA Large' | 'AA' | 'AAA'
```

#### Example

```js
import { scoreFromRatio } from 'wcag-color'

scoreFromRatio(7.5) // AAA
```

### Best color out of two

`best` takes two colors and a background color and returns the color which is
best suited, from a contrast perspective, for that background color.

```js
best(firstColor: string, secondColor: string, background: string) => string
```

#### Example

```js
import { best } from 'wcag-color'

best('#ffffff', '#000000', '#ffffff') // #000000
```

## Score and ratio

- **Fail** - Your text has a contrast ratio of less than `3.0`
- **AA Large** - Least amount of contrast for font size 18px and larger. The ratio is above `3.0`.
- **AA** - What you should aim for with text sizes below 18px. The ratio is at least `4.5`.
- **AAA** - Enhanced contrast with a ratio of at least `7.0`. Valuable for texts that will be read for a longer period of time.
