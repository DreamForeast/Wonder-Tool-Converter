var gulp = require("gulp");

var commandUtils = require("./build/gulp_task/common/commandUtils");

var convert = require("./lib/js/src/ConvertGLTFToWDSystem.js");

gulp.task("convert", function (done) {
    var sourceGLTFFilePath = commandUtils.parseOption("--sourceGLTFFilePath"),
        destDir = commandUtils.parseOption("--destDir") || "./dest/";

    if (destDir === null) {
        throw new Error("should define --sourceGLTFFilePath");
    }

    convert.convert(sourceGLTFFilePath, destDir);

    done();
});
