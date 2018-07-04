open Wonderjs;

open Node;

let convertUint8ArrayToBuffer = [%raw
  uint8Array => {|
            {
                 var buf = new Buffer(uint8Array.byteLength);

                 for (var i = 0; i < buf.length; ++i) {
                     buf[i] = uint8Array[i];
                 }

                 return buf;
             }
            |}
];

let buildFakeTextDecoder = [%raw
  convertUint8ArrayToBufferFunc => {|
              var TextDecoder = function(utfLabel){
              };

              TextDecoder.prototype.decode = (uint8Array) => {
                var buffer = convertUint8ArrayToBufferFunc(uint8Array);

                return buffer.toString("utf8");
              };

              global.TextDecoder = TextDecoder;
          |}
];

let buildFakeTextEncoder =
  [@bs]
  [%raw
    () => {|
              var TextEncoder = function(){
              };

              TextEncoder.prototype.encode = (str) => {
                var buffer = Buffer.from(str, "utf8");

                return buffer;
              };

              global.TextEncoder = TextEncoder;
          |}
  ];


let _buildWDBFilePath = (sourceGLBFilePath, destDir) =>
  Path.join([|
    destDir,
    Path.basename_ext(sourceGLBFilePath, ".glb") ++ ".wdb",
  |]);

let convert = (sourceGLBFilePath, destDir) => {
  let buffer = NodeExtend.readFileBufferSync(sourceGLBFilePath);

  buildFakeTextDecoder(convertUint8ArrayToBuffer);
  buildFakeTextEncoder(.);

  buffer##buffer
  |> ConverterAPI.convertGLBToWDB
  |> WriteWDBSystem.write(_buildWDBFilePath(sourceGLBFilePath, destDir));
};