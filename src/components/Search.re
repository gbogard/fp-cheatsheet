let containerStyle =
  Css.(
    style([
      display(`flex),
      padding4(~top=`rem(0.5), ~bottom=`rem(2.), ~right=`zero, ~left=`zero),
    ])
  );

let inputStyle =
  Css.(
    style([
      border(`px(1), `solid, `hex("282828")),
      fontSize(`rem(1.)),
      padding(`rem(0.5)),
      flex(`num(1.)),
      borderRadius(`rem(0.5)),
      color(`hex("282828")),
      background(`none),
    ])
  );

[@react.component]
let make = (~query, ~onQueryChange, ~concrete, ~onConcreteChange) => {
  <div className=containerStyle>
    <input
      className=inputStyle
      type_="text"
      value=query
      placeholder="Search ..."
      onChange={e => e->ReactEvent.Form.target##value->onQueryChange}
    />
    <label htmlFor="concrete-ch">
      "Concrete Types"->React.string
    </label>
    <input
      id="concrete-ch"
      type_="checkbox"
      name="concrete"
      checked=concrete
      onChange={e => e->ReactEvent.Form.target##checked->onConcreteChange}
    />
  </div>;
};