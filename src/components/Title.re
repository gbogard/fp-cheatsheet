[@bs.val] external fontsReady: Js.Promise.t(unit) = "document.fonts.ready";

let container =
  Css.(
    style([
      position(`relative),
      textAlign(`center),
      display(`inlineBlock),
      whiteSpace(`nowrap),
      fontFamily(Theme.font(`luckiestGuy)),
      color(white),
      lineHeight(`rem(2.)),
      textShadow(
        Shadow.text(
          ~x=`px(10),
          ~y=`px(10),
          ~blur=`px(10),
          rgba(0, 0, 0, 0.5),
        ),
      ),
      marginBottom(`px(10)),
      Theme.tablet([marginBottom(`px(30)), lineHeight(`rem(4.5))]),
    ])
  );

let ofStyle =
  Css.(
    style([
      position(`absolute),
      fontFamily(Theme.font(`lobster)),
      color(hex("d79921")),
      left(`percent(50.)),
      top(`rem(0.5)),
      transform(translateX(`percent(-50.))),
      Theme.tablet([
        top(`rem(1.6))
      ])
    ])
  );

[@react.component]
let make = () => {
  let divRef = React.useRef(Js.Nullable.null);

  React.useEffect1(
    () => {
      Js.Promise.then_(
        _ => {
          Js.Promise.resolve(
            {
              divRef
              ->React.Ref.current
              ->Js.Nullable.toOption
              ->Option.forEach(Fitty.fitty);
            },
          )
        },
        fontsReady,
      ) -> ignore;

      None;
    },
    [|divRef|],
  );

  <div className=container ref={ReactDOMRe.Ref.domRef(divRef)}>
    <span className=ofStyle> "of"->React.string </span>
    "The Cheat Sheet"->React.string
    <br />
    "Functional transformations"->React.string
  </div>;
};