open Wonder_jest;

let _ =
  describe("convert", () => {
    open Expect;
    open Expect.Operators;
    open Sinon;

    let sandbox = getSandboxDefaultVal();
    let destDir = ref("");

    beforeEach(() => {
      sandbox := createSandbox();
      destDir := Node.Path.join([|Node.Process.cwd(), "test/dist/"|]);
    });
    afterEach(() => {
      restoreSandbox(refJsObjToSandbox(sandbox^));

      WonderCommonlib.NodeExtend.rmdirFilesSync(destDir^);
    });

    describe("convert gltf file to wd file", () =>
      test("test", () => {
        ConvertGLBToWDBSystem.convert(
          Node.Path.join([|Node.Process.cwd(), "test/res/BoxTextured.glb"|]),
          destDir^,
        );

        ConvertTool.readWDB(Node.Path.join([|destDir^, "BoxTextured.wdb"|]))
        |> ConvertTool.getWDFileContent
        |>
        expect == {|[["2.0","GLTF2WD"],[[0],null,null],[[[[0],[[1]]],[[0,1],[0,1]],[[],[]],[[],[]],[[],[]],[[1],[0]],[[],[]],[[],[]],[[1],[0]]],[[[0],[0]]],[[0],[0]],[[0],[0]]],[2,["gameObject_0","Mesh"]],[[3,"image/png"]],[["CesiumLogoFlat.png",1]],[[1,4,2,2]],[24360],[[0,768,72,null],[0,0,576,12],[0,576,192,8],[0,840,23516,null]],[[0,0,36,3,0],[1,0,24,5,2],[1,288,24,5,2],[2,0,24,5,1]],[],[],[0],[],[],[[[0,0,0],[-0.7071067811865475,0,0,0.7071067811865476],[1,1,1]],[null,null,null]],[[2,1,3,0]],[[[1,1,1],"Texture"]]]|};
      })
    );
  });