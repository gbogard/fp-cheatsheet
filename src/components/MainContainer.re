let style = Css.(
  style([
    maxWidth(`px(Theme.tabletBreakpoint + 100)),
    margin2(~v=`zero, ~h=`auto),
    padding4(~top=`rem(2.), ~left=`px(8), ~right=`px(8), ~bottom=`rem(1.))
  ])
);

[@react.component]
let make = (~children) =>
  <div className={style}> {children} </div>