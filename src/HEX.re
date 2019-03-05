let defaultArray = str => str->Belt.Option.getWithDefault([||]);

let hexParts = t => {
  switch (t->Js.String.length) {
  | 3 =>
    Js.String.match([%re "/.{1}/g"], t)
    |> defaultArray
    |> Js.Array.map(x => x ++ x)
  | _ => Js.String.match([%re "/.{2}/g"], t) |> defaultArray
  };
};

let convert = hex => {
  hex |> hexParts |> Js.Array.map(x => "0x" ++ x |> float_of_string);
};
