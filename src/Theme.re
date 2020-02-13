let pageBackground = Css.hex("282828");
let elementBackground = Css.hex("bdae93");
let titleBackground = Css.hex("504945");
let listBackground = Css.hex("7c6f64");

let globalRules = () =>
  Css.(global("html body", [backgroundColor(pageBackground)]));

let tabletBreakpoint = 768;
let tablet = Css.media({j|(min-width: $(tabletBreakpoint)px)|j});

let desktopBreakpoint = 1200;
let desktop = Css.media({j|(min-width: $(desktopBreakpoint)px)|j});

type font = [ | `luckiestGuy | `mukta | `lobster];

let font = font => switch(font) {
  | `luckiestGuy => "'Luckiest Guy', cursive"
  | `mukta => "'Mukta', sans-serif"
  | `lobster => "'Lobster', cursive"
};