open Types;

module Operands = {
  let driver = type_("A", "Driver", None);
  let car = type_("B", "Car", None);
  let engine = type_("C", "Engine", None);
  let fn = (a, b) =>
    type_(
      a.abstractForm ++ " => " ++ b.abstractForm,
      a.concreteForm ++ " => " ++ b.concreteForm,
      Some("A unary function from one type to another"),
    );
};

let functionApplication =
  Operands.{
    title: "Unary Function Application",
    from: `type_(driver),
    with_: [`type_(fn(driver, car))],
    to_: `type_(car),
    provider: Language,
    example:
      Some(
        {|
val getDriverCar: Driver => Car = car => {
  // Some implemenation here
  ???
}

val driver = Driver("D. Toretto")
val car: Car = getDriverCar(driver)
|},
      ),
    details: None,
    using: None,
  };

let leftToRightFunctionComposition =
  Operands.{
    title: "Left-to-right Function Composition",
    from: `type_(fn(driver, car)),
    with_: [`type_(fn(car, engine))],
    to_: `type_(fn(driver, engine)),
    provider: Language,
    using: Some("`andThen` defined on all functions"),
    example:
      Some(
        {|
val getDriverCar: (Driver => Car) = car => {
  // some implementation here
  ???
}

val getCarEngine: (car => engine) = ???

val getdriverengine: (driver => engine) = getdrivercar andthen getcarengine
|},
      ),
    details: None,
  };

let rightToLeftFunctionComposition =
  Operands.{
    title: "Right-to-left Function Composition",
    from: `type_(fn(car, engine)),
    with_: [`type_(fn(driver, car))],
    to_: `type_(fn(driver, engine)),
    provider: Language,
    example:
      Some(
        {|
val getdrivercar: (driver => car) = car => {
  // some implementation here
  ???
}

val getCarEngine: (Car => Engine) = car => ???

val getdriverengine: (driver => engine) = getdrivercar andthen getcarengine
|},
      ),
    using: None,
    details: None,
  };

let all = [
  functionApplication,
  leftToRightFunctionComposition,
  rightToLeftFunctionComposition,
  rightToLeftFunctionComposition,
  rightToLeftFunctionComposition,
];