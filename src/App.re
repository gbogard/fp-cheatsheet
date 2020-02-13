Theme.globalRules();

let list =
  Css.(style([
    background(Theme.listBackground), 
    padding(`px(25)),
    boxShadow(
      Shadow.box(~x=px(18), ~y=px(18), ~blur=px(32), rgba(0,0,0,0.3))
    ),
    borderRadius(`px(5))
    ]));

[@react.component]
let make = () => {
  let items =
    Scala.all
    ->List.map(t => <Transformation key=t.title transformation=t />)
    ->Belt.List.toArray
    ->ReasonReact.array;

  <MainContainer>
    <Title />
    <div className=list> items </div>
  </MainContainer>;
};