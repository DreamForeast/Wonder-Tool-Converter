open Wonderjs;

let readWDB = wdbFilePath => {
  let buffer = NodeExtend.readFileBufferSync(wdbFilePath);

  buffer##buffer;
};

let getWDFileContent = wdb => {
  let (wdFileContent, _) =
    BinaryUtils.decode(wdb, AssembleWDBSystem._checkWDB);

  wdFileContent;
};