local common = import "common.libsonnet";

function (params) {
  components: common.checkParams(params, ["pos"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "player"
    }),
    Position: params.pos,
    Power: {},
    Button: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SpritePosition: {
      depth: common.getDepth("static")
    },
    PowerSprite: {
      transition: common.getSpriteID("button 0")
    }
  }
}
