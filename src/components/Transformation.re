open Types;

let style =
  Css.(
    style([
      background(Theme.elementBackground),
      borderRadius(`px(4)),
      overflow(`hidden),
      marginBottom(`rem(1.5)),
    ])
  );

let title =
  Css.(
    style([
      background(Theme.titleBackground),
      margin(`zero),
      padding2(~v=rem(0.5), ~h=rem(0.5)),
    ])
  );

let code = Css.(style([margin(`zero), important(padding(`rem(1.)))]));

let renderSymbol = s => <span> s.abstractForm->React.string </span>;

let renderExample = e => {
  let fallback = <div />;

  <React.Suspense fallback>
    <LazySyntaxHighlighter.Lazy className=code> e </LazySyntaxHighlighter.Lazy>
  </React.Suspense>;
};

[@react.component]
let make = (~transformation) => {
  <div className=style>
    <h3 className=title> transformation.title->React.string </h3>
    {transformation.example
     ->Option.map(renderExample)
     ->Option.getWithDefault(React.null)}
  </div>;
};