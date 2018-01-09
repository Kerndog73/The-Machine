local e = import "entities.libsonnet";
local common = import "common.libsonnet";
local assemble = import "assemble.libsonnet";

assemble(["first", ["second", "third"], [["fourth", "fifth"], ["sixth", "seventh"]]])

/*[
  e.box({
    pos: [0, 0]
  }),
  e.radioactive_toggle({
    pos: [0, 1],
    dir: "down"
  }),
  e.air({
    pos: [0, 0]
  }),
  e.button({
    pos: [1, 1]
  }),
  e.air({
    pos: [1, 2]
  }),
  e.air({
    pos: [2, 1]
  }),
  e.gate({
    pos: [1, 0],
    gate: "xor"
  }),
  e.exit({
    pos: [2, 0]
  }),
  e.lever({
    pos: [3, 0]
  }),
  e.player({
    pos: [3, 1]
  }),
  e.wire({
    pos: [4, 1],
    sides: ["right", "down"]
  }),
  e.air({
    pos: [3, 1]
  }),
  e.piston_base({
    pos: [4, 0],
    dir: "right"
  }),
  e.piston_head({
    pos: [4, 0],
    dir: "right"
  }),
  e.air({
    pos: [5, 0]
  }),
  e.pressure_plate({
    pos: [5, 1],
    heavy: false
  }),
  e.air({
    pos: [5, 2]
  }),
  e.air({
    pos: [6, 1]
  }),
  e.box({
    pos: [10, 12],
    radioactive: true
  }),
  e.radioactivity_detector({
    pos: [9, 10],
    dir: "right"
  }),
  e.air({
    pos: [10, 10]
  }),
  e.signal_receiver({
    pos: [5, 10],
    channel: 5
  }),
  e.signal_transmitter({
    pos: [5, 5],
    channel: 5
  }),
  e.wall({
    pos: [4, 5]
  })
]*/
