let defaultArray = str => str->Belt.Option.getWithDefault([])
let defaultText = str => str->Belt.Option.getWithDefault("")

let hexParts = t => {
  switch t->Js.String2.length {
  | 3 =>
    t
    ->Js.String2.match_(%re("/.{1}/g"))
    ->defaultArray
    ->Belt.Array.map(x => x->defaultText ++ x->defaultText)
  | _ => t->Js.String2.match_(%re("/.{2}/g"))->defaultArray->Belt.Array.map(x => x->defaultText)
  }
}

let convert = hex => hex->hexParts->Js.Array2.map(x => "0x" ++ x |> float_of_string)
