[@react.component]
let make = (~children, ~className) =>
  <ReactSyntaxHighlighter.Hljs
    className
    language=`Scala
    style=ReactSyntaxHighlighter.Hljs.Style.gruvboxLight>
    children
  </ReactSyntaxHighlighter.Hljs>;

let default = make;