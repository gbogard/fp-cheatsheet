type type_ = {
  abstractForm: string,
  concreteForm: string,
  explanation: option(string),
};

let type_ = (abstractForm, concreteForm, explanation) => {
  abstractForm,
  concreteForm,
  explanation
};

type operand = [`type_(type_)]

type provider =
  | Language;

type transformation = {
  title: string,
  from: operand,
  with_: list(operand),
  to_: operand,
  provider: provider,
  example: option(string),
  details: option(string)
};