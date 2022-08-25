// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Belt_Array = require("rescript/lib/js/belt_Array.js");
var Belt_Option = require("rescript/lib/js/belt_Option.js");
var Caml_format = require("rescript/lib/js/caml_format.js");
var Caml_option = require("rescript/lib/js/caml_option.js");

function defaultArray(str) {
  return Belt_Option.getWithDefault(str, []);
}

function defaultText(str) {
  return Belt_Option.getWithDefault(str, "");
}

function hexParts(t) {
  var match = t.length;
  if (match !== 3) {
    var str = t.match(/.{2}/g);
    return Belt_Array.map(Belt_Option.getWithDefault(str === null ? undefined : Caml_option.some(str), []), (function (x) {
                  return Belt_Option.getWithDefault(x, "");
                }));
  }
  var str$1 = t.match(/.{1}/g);
  return Belt_Array.map(Belt_Option.getWithDefault(str$1 === null ? undefined : Caml_option.some(str$1), []), (function (x) {
                return Belt_Option.getWithDefault(x, "") + Belt_Option.getWithDefault(x, "");
              }));
}

function convert(hex) {
  return hexParts(hex).map(function (x) {
              return Caml_format.float_of_string("0x" + x);
            });
}

exports.defaultArray = defaultArray;
exports.defaultText = defaultText;
exports.hexParts = hexParts;
exports.convert = convert;
/* No side effect */
