var gulp = require("gulp");

var commandUtils = require("./build/gulp_task/common/commandUtils");

var convert = require("./lib/js/src/ConvertGLBToWDBSystem.js");

gulp.task("convert", function (done) {
    var sourceGLTFFilePath = commandUtils.parseOption("--sourceGLBFilePath"),
        destDir = commandUtils.parseOption("--destDir") || "./dest/";

    if (destDir === null) {
        throw new Error("should define --sourceGLBFilePath");
    }

    convert.convert(sourceGLTFFilePath, destDir);

    done();
});
