type scrollPosition = {
  x: int,
  y: int
};

[@bs.module]
external useScrollPosition: unit => scrollPosition = "@rehooks/window-scroll-position";