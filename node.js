// import { ConvertGLBtoGltf, ConvertGltfToGLB, ConvertToGLB} from 'gltf-import-export';

var ConvertGltfToGLB = require("gltf-import-export").ConvertGltfToGLB;


var path = require("path");

// const inputGlb = 'pathtoyour.glb';
// const extractedGltfFilename = 'newfile.gltf';

// // Perform the conversion; output paths are overwritten
// ConvertGLBtoGltf(inputGlb, extractedGltfFilename);

// let gltfContent = fs.readFileSync(extractedGltfFilename, 'utf8');
// let gltf = JSON.parse(gltfContent);

const outputGlb = path.join(
    process.cwd(), "./mine/fish/glb/", "fish.glb"
);


// // Perform the conversion; output path is overwritten
// ConvertToGLB(gltf, extractedGltfFilename, outputGlb);

const gltfFilename = path.join(
    process.cwd(), "./mine/fish/gltf/", "fish.gltf"
);

// optionally if you haven't already parsed the gltf JSON
// ConvertGltfToGLB(gltfFilename, outputGlb);
ConvertGltfToGLB(gltfFilename, outputGlb);