export type Score = 'Fail' | 'AA Large' | 'AA' | 'AAA'
export declare const ratio: (foreground: string, background: string) => number
export declare const score: (foreground: string, background: string) => Score
export declare const scoreFromRatio: (ratio: number) => Score
