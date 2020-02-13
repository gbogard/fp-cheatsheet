let style = Css.(
  style([
    maxWidth(`px(Theme.tabletBreakpoint + 50)),
    margin2(~v=`zero, ~h=auto),
    paddingTop(`rem(2.))
  ])
);

[@react.component]
let make = (~children) =>
  <div className={style}> {children} </div>