local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "dir"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    Power: {},
    Device: {},
    PowerOutput: common.getDirBitsetComp("down", params.dir),
    RadioactivityDetector: {
      side: common.getDir(params.dir)
    },
    SpritePosition: {
      depth: common.getDepth("static"),
      dir: common.getDir(params.dir)
    },
    PowerSprite: common.getTransitionPowerSpriteComp("radioactivity detector 0")
  }
}
