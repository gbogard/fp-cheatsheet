open Types;

module Symbols = {
  let driver = type_("A", "Driver", None)
  let car = type_("B", "Car", None)
  let engine = type_("C", "Engine", None)
  let fn = (a, b) =>
    type_(
      a.abstractForm ++ " => " ++ b.abstractForm,
      a.concreteForm ++ " => " ++ b.concreteForm,
      Some("A unary function from one type to another")
    )
};

let functionApplication = Symbols.{
  title: "Unary Function Application",
  from: `type_(driver),
  with_: [`type_(fn(driver, car))],
  to_: `type_(car),
  provider: Language,
  example: None,
  details: None
}

let leftToRightFunctionComposition = Symbols.{
  title: "Left-to-right Function Composition",
  from: `type_(fn(driver, car)),
  with_: [`type_(fn(car, engine))],
  to_: `type_(fn(driver, engine)),
  provider: Language,
  example: Some({|
val getDriverCar: (Driver => Car) = {
  // Some implementation here
  ???
}

val getCarEngine: (Car => Engine) = ???

val getDriverEngine: (Driver => Engine) = getDriverCar andThen getCarEngine
|}),
  details: None
}

let rightToLeftFunctionComposition = Symbols.{
  title: "Right-to-left Function Composition",
  from: `type_(fn(car, engine)),
  with_: [`type_(fn(driver, car))],
  to_: `type_(fn(driver, engine)),
  provider: Language,
  example: None,
  details: None
}

let all = [
  functionApplication,
  leftToRightFunctionComposition,
  rightToLeftFunctionComposition
];