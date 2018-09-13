open Wonderjs;

let readWDB = wdbFilePath => {
  let buffer = NodeExtend.readFileBufferSync(wdbFilePath);

  buffer##buffer;
};

let getWDFileContent = wdb => {
  let (wdFileContent, _, _) =
    BufferUtils.decodeWDB(wdb, AssembleWholeWDBSystem._checkWDB);

  wdFileContent;
};