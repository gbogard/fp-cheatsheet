open Types;
Theme.globalRules();

let list =
  Css.(
    style([
      background(Theme.listBackground),
      padding(`px(25)),
      boxShadow(
        Shadow.box(
          ~x=px(18),
          ~y=px(18),
          ~blur=px(32),
          rgba(0, 0, 0, 0.3),
        ),
      ),
      borderRadius(`px(5)),
    ])
  );

let filter = (query, item) => {
  query == ""
  || query
     ->String.lowercase_ascii
     ->Js.String.includes(item.title->String.lowercase_ascii);
};

[@react.component]
let make = () => {
  let (searchQuery, setSearchQuery) = React.useState(() => "");
  let (concrete, setConcrete) = React.useState(() => false);

  let items =
    Scala.all
    ->List.keep(filter(searchQuery))
    ->List.map(t => <Transformation key={t.title} transformation=t concrete />)
    ->Belt.List.toArray
    ->ReasonReact.array;

  <MainContainer>
    <Title />
    <div className=list>
      <Search
        query=searchQuery
        onQueryChange=setSearchQuery
        concrete
        onConcreteChange=setConcrete
      />
      items
    </div>
  </MainContainer>;
};