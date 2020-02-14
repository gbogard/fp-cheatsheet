open Types;

let containerStyle =
  Css.(
    style([
      background(Theme.elementBackground),
      borderRadius(`px(4)),
      overflow(`hidden),
      marginBottom(`rem(2.5)),
      boxShadow(
        Shadow.box(
          ~x=px(5),
          ~y=px(5),
          ~blur=px(8),
          rgba(0, 0, 0, 0.1),
        ),
      ),
    ])
  );

let titleStyle =
  Css.(
    style([
      background(Theme.titleBackground),
      margin(`zero),
      padding2(~v=rem(0.5), ~h=rem(0.5)),
      fontFamily(Theme.font(`mukta)),
      color(Theme.yellow),
    ])
  );

let operandGroupStyle =
  Css.(
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      padding2(~v=`zero, ~h=`rem(1.5)),
      selector(
        "h6",
        [textAlign(`center), margin2(~h=`zero, ~v=`rem(0.4))],
      ),
    ])
  );

let operandStyle = Css.(style([]));

let contentStyle = Css.(style([padding2(~v=`rem(1.), ~h=`zero)]));

let codeStyle =
  Css.(style([margin(`zero), important(padding(`rem(1.)))]));

let renderSymbol = s => <span> s.abstractForm->React.string </span>;

let renderOperand = (concrete, operand) =>
  <div key={operand->operandKey}>
    {switch (operand, concrete) {
     | (`type_(t), true) => React.string(t.concreteForm)
     | (`type_(t), false) => React.string(t.abstractForm)
     }}
  </div>;

let renderExample = e => {
  let fallback = <div> "Loading example"->React.string </div>;

  <React.Suspense fallback>
    <LazySyntaxHighlighter.Lazy className=codeStyle>
      e
    </LazySyntaxHighlighter.Lazy>
  </React.Suspense>;
};

[@react.component]
let make = (~transformation, ~concrete) => {
  <div className=containerStyle>
    <h3 className=titleStyle> transformation.title->React.string </h3>
    <div className=contentStyle>
      <div className=operandGroupStyle>
        <div>
          <h6> "FROM"->React.string </h6>
          {renderOperand(concrete, transformation.from)}
        </div>
        <div>
          <h6> "WITH"->React.string </h6>
          <div className=operandGroupStyle>
            {transformation.with_
             ->List.map(renderOperand(concrete))
             ->List.toArray
             ->React.array}
          </div>
        </div>
        <div>
          <h6> "TO"->React.string </h6>
          {renderOperand(concrete, transformation.to_)}
        </div>
      </div>
    </div>
    {transformation.example
     ->Option.map(renderExample)
     ->Option.getWithDefault(React.null)}
  </div>;
};