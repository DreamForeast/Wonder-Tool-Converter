let write = (targetFilePath, wdb) =>
  NodeExtend.writeFileBufferSync(
    targetFilePath,
    NodeExtend.newBufferFromArrayBuffer(wdb),
    `binary,
  );