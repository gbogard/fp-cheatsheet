open Hooks;

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
    {
      let rules =
        style([
          position(`fixed),
          top(`zero),
          width(`vw(100.)),
          boxSizing(`borderBox),
          borderRadius(`zero),
          paddingLeft(`px(10)),
          paddingRight(`px(10)),
          zIndex(100),
          Theme.tablet([paddingLeft(`px(100)), paddingRight(`px(100))]),
          Theme.desktop([paddingLeft(`px(300)), paddingRight(`px(300))]),
          transform(translateY(`percent(-100.))),
          transition(~duration=400, "transform")
        ]);

      [containerStyle, rules]->merge;
    }
  );

let stickyContainerStyleOpen = Css.(style([transform(translateY(`zero))]));

let inputContainerStyle =
  Css.(
    style([
      position(`relative),
      flexGrow(1.),
      selector(
        "i",
        [
          position(`absolute),
          top(`rem(0.7)),
          left(`rem(0.7)),
          color(white),
          opacity(0.8),
        ],
      ),
    ])
  );

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
  let {y} = useScrollPosition();

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

  let fixedNavbar =
    ReactDOMRe.createPortal(
      <>
        <div
          className={Cn.make([
            stickyContainerStyle,
            stickyContainerStyleOpen->Cn.ifTrue(y >= 600),
          ])}>
          content
        </div>
      </>,
      Webapi.Dom.Document.querySelector(
        "#navbar-container",
        Webapi.Dom.document,
      )
      ->Option.getExn,
    );
  <> fixedNavbar <div className=containerStyle> content </div> </>;
};