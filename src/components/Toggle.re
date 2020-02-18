let containerStyle = Css.(
  style([
    display(`inlineBlock),
    backgroundColor(Theme.grey),
    height(`rem(2.)),
    width(`rem(3.5)),
    margin2(~v=`zero, ~h=`rem(1.)),
    borderRadius(`rem(1.)),
    position(`relative),
    transition(~duration=250, "all")
  ])
);

let containerCheckedStyle = Css.(
  style([
    backgroundColor(Theme.green)
  ])
);

let ballStyle = Css.(
  style([
    display(`inlineBlock),
    height(`rem(2.1)),
    width(`rem(2.1)),
    backgroundColor(white),
    borderRadius(`rem(2.1)),
    position(absolute),
    left(`zero),
    transition(~duration=250, "all")
  ])
);

let ballCheckedStyle = Css.(
  style([
    left(`rem(1.5)),
  ])
);

[@react.component]
let make = (~checked: bool, ~onChange: bool => unit) => {
  let toggle = () => onChange(!checked);

  <div className=Cn.make([containerStyle, containerCheckedStyle->Cn.ifTrue(checked)]) onClick={_ => toggle()}>
    <span className=Cn.make([ballStyle, ballCheckedStyle->Cn.ifTrue(checked)])></span> 
  </div>
}