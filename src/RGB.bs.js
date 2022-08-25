// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Belt_Option = require("rescript/lib/js/belt_Option.js");
var Caml_format = require("rescript/lib/js/caml_format.js");

function toNumbers(rgb) {
  var colors = rgb.match(/\\d+\\.?\\d?/g);
  if (colors !== null) {
    return colors.map(function (x) {
                return Caml_format.float_of_string(Belt_Option.getWithDefault(x, ""));
              });
  } else {
    return [];
  }
}

function fromRgba(fg, bg) {
  var r;
  var g;
  var b;
  var a;
  var r2;
  var g2;
  var b2;
  if (fg.length !== 4) {
    return [];
  }
  var r$1 = fg[0];
  var g$1 = fg[1];
  var b$1 = fg[2];
  var a$1 = fg[3];
  var len = bg.length;
  if (len !== 3) {
    if (len !== 4) {
      return [];
    }
    var r2$1 = bg[0];
    var g2$1 = bg[1];
    var b2$1 = bg[2];
    r = r$1;
    g = g$1;
    b = b$1;
    a = a$1;
    r2 = r2$1;
    g2 = g2$1;
    b2 = b2$1;
  } else {
    var r2$2 = bg[0];
    var g2$2 = bg[1];
    var b2$2 = bg[2];
    r = r$1;
    g = g$1;
    b = b$1;
    a = a$1;
    r2 = r2$2;
    g2 = g2$2;
    b2 = b2$2;
  }
  var alpha = a > 1 ? a / 255 : a;
  var r3 = Math.round((1 - alpha) * r2 + alpha * r);
  var g3 = Math.round((1 - alpha) * g2 + alpha * g);
  var b3 = Math.round((1 - alpha) * b2 + alpha * b);
  return [
          r3,
          g3,
          b3
        ];
}

function make(fg, bg) {
  var updatedFg = toNumbers(fg);
  var match = updatedFg.length;
  if (match !== 4) {
    return updatedFg;
  } else {
    return fromRgba(updatedFg, toNumbers(bg));
  }
}

exports.toNumbers = toNumbers;
exports.fromRgba = fromRgba;
exports.make = make;
/* No side effect */
