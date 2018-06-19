open Wonderjs;

open Node;

let _buildWDFilePath = (sourceGLTFFilePath, destDir) =>
  Path.join([|destDir, Path.basename_ext(sourceGLTFFilePath, ".gltf") ++ ".wd"|]);

let convert = (sourceGLTFFilePath, destDir) =>
  Fs.readFileAsUtf8Sync(sourceGLTFFilePath)
  |> ConverterAPI.convertGLTFToWD
  |> WriteWDSystem.write(_buildWDFilePath(sourceGLTFFilePath, destDir));