type t =
  | HSL
  | RGB
  | HEX;
let typeOfColor: Js.String.t => t;
let parseNumbers: Js.String.t => Js.Array.t(float);
let parseColor: Js.String.t => float;
let calculate: (Js.String.t, Js.String.t) => float;
