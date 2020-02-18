let containerStyle =
  Css.(
    style([
      backgroundColor(Theme.orange),
      display(`flex),
      padding(`rem(0.5)),
      borderRadius(`px(5)),
      marginBottom(`rem(1.)),
      alignItems(`center),
      selector(
        "label",
        [
          color(white),
          textAlign(`center),
          marginLeft(`rem(1.)),
          fontFamily(Theme.font(`mukta)),
          fontSize(`rem(0.75)),
          lineHeight(`rem(0.75)),
        ],
      ),
    ])
  );

let stickyContainerStyle =
  Css.(
    style([position(`sticky), top(`zero), backgroundColor(Theme.orange)])
  );

let inputContainerStyle = Css.(style([
  position(`relative),
  flexGrow(1.),
  selector("i", [
    position(`absolute),
    top(`rem(0.7)),
    left(`rem(0.7)),
    color(white),
    opacity(0.8)
  ])
]));

let inputStyle =
  Css.(
    style([
      border(`px(1), `solid, white),
      fontSize(`rem(1.)),
      padding(`rem(0.5)),
      paddingLeft(`rem(2.)),
      width(`percent(100.)),
      boxSizing(`borderBox),
      borderRadius(`rem(0.5)),
      color(white),
      background(`none),
      minWidth(`zero),
      placeholder([color(white), opacity(0.8)]),
    ])
  );

[@react.component]
let make = (~query, ~onQueryChange, ~concrete, ~onConcreteChange) => {
  let content =
    <>
      <div className=inputContainerStyle>
        <i className="fas fa-search" />
        <input
          className=inputStyle
          type_="text"
          value=query
          placeholder="Search ..."
          onChange={e => e->ReactEvent.Form.target##value->onQueryChange}
        />
      </div>
      <label>
        "Concrete"->React.string
        <br />
        "Types"->React.string
        <br />
      </label>
      <Toggle checked=concrete onChange=onConcreteChange />
    </>;

  <> <div className=containerStyle> content </div> </>;
};