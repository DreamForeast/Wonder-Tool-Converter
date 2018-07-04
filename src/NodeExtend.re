[@bs.module "fs"]
external readFileBufferSync : string => 'buffer = "readFileSync";

[@bs.module "fs"]
external writeFileBufferSync :
  (string, 'buffer, [@bs.string] [ | `binary]) => unit =
  "writeFileSync";

[@bs.new]
external newBufferFromArrayBuffer :
  Js.Typed_array.ArrayBuffer.t => Node.Buffer.t =
  "Buffer";