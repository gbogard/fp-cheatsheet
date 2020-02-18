let veryDarkBrown = Css.hex("282828");
let elementBackground = Css.hex("bdae93");
let titleBackground = Css.hex("504945");
let yellow = Css.hex("d79921");
let orange = Css.hex("d65d0e");
let green = Css.hex("98971a");
let grey = Css.hex("928374");

let globalRules = () =>
  Css.(
    global("html body", [backgroundColor(veryDarkBrown), margin(`zero)])
  );

let tabletBreakpoint = 768;
let tablet = Css.media({j|(min-width: $(tabletBreakpoint)px)|j});

let desktopBreakpoint = 1200;
let desktop = Css.media({j|(min-width: $(desktopBreakpoint)px)|j});

type font = [ | `luckiestGuy | `mukta | `lobster];

let font = font =>
  switch (font) {
  | `luckiestGuy => "'Luckiest Guy', cursive"
  | `mukta => "'Mukta', sans-serif"
  | `lobster => "'Lobster', cursive"
  };