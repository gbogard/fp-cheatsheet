let containerStyle =
  Css.(
    style([
      backgroundColor(Theme.orange),
      display(`flex),
      padding(`rem(0.5)),
      borderRadius(`px(5)),
      marginBottom(`rem(1.)),
    ])
  );

let stickyContainerStyle =
  Css.(
    style([
      position(`sticky),
      top(`zero),
      backgroundColor(Theme.orange),
    ])
  );

let inputStyle =
  Css.(
    style([
      border(`px(1), `solid, white),
      fontSize(`rem(1.)),
      padding(`rem(0.5)),
      flex(`num(1.)),
      borderRadius(`rem(0.5)),
      color(white),
      background(`none),
    ])
  );

[@react.component]
let make = (~query, ~onQueryChange, ~concrete, ~onConcreteChange) => {
  let content =
    <>
      <input
        className=inputStyle
        type_="text"
        value=query
        placeholder="Search ..."
        onChange={e => e->ReactEvent.Form.target##value->onQueryChange}
      />
      <label htmlFor="concrete-ch"> "Concrete Types"->React.string </label>
      <input
        id="concrete-ch"
        type_="checkbox"
        name="concrete"
        checked=concrete
        onChange={e => e->ReactEvent.Form.target##checked->onConcreteChange}
      />
    </>;

  <>
    <div className=containerStyle> content </div>
  </>;
};