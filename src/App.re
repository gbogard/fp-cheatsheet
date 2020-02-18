open Types;
Theme.globalRules();

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
      <Search
        query=searchQuery
        onQueryChange={value => setSearchQuery(_ => value)}
        concrete
        onConcreteChange={value => setConcrete(_ => value)}
      />
      items
  </MainContainer>;
};