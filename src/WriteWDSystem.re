let write = (targetFilePath, wdRecord) =>
  Node.Fs.writeFileAsUtf8Sync(
    targetFilePath
   |>WonderLog.Log.print 
    ,
    wdRecord |> WriteWDType.wdRecordToJson |> Js.Json.stringify,
  );