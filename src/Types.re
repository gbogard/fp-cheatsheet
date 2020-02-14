type type_ = {
  abstractForm: string,
  concreteForm: string,
  explanation: option(string),
};

let type_ = (abstractForm, concreteForm, explanation) => {
  abstractForm,
  concreteForm,
  explanation,
};

type operand = [ | `type_(type_)];

let operandKey = operand =>
  switch (operand) {
  | `type_(t) => t.concreteForm ++ t.abstractForm
  };

type provider =
  | Language;

type transformation = {
  title: string,
  from: operand,
  with_: list(operand),
  to_: operand,
  using: option(string),
  provider,
  example: option(string),
  details: option(string),
};