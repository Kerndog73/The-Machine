local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

assemble([
  e.player({
    pos: [0, 0]
  }),
  e.button({
    pos: [5, 5]
  }),
  a.piston({
    pos: [6, 5],
    dir: "right"
  }),
  e.wire({
    pos: [5, 7],
    sides: ["down", "right"]
  }),
  e.wire({
    pos: [5, 6],
    sides: ["down", "up"]
  }),
  a.piston({
    pos: [6, 7],
    dir: "right"
  }),

  e.lever({
    pos: [10, 6]
  }),
  e.cross_wire({
    pos: [10, 7]
  }),
  a.piston({
    pos: [10, 8],
    dir: "up"
  }),
  e.lever({
    pos: [9, 7]
  }),
  a.piston({
    pos: [11, 7],
    dir: "right"
  }),

  e.gate({
    pos: [15, 6],
    gate: "nor",
    dir: "right"
  }),
  e.wire({
    pos: [16, 6],
    sides: ["left", "down"]
  }),
  e.wire({
    pos: [16, 5],
    sides: ["up", "left"]
  }),
  e.wire({
    pos: [15, 5],
    sides: ["right", "up"]
  }),
  a.piston({
    pos: [15, 7],
    dir: "up"
  }),

  e.button({
    pos: [5, 0]
  }),
  e.signal_transmitter({
    pos: [5, 1],
    channel: 5
  }),
  e.signal_receiver({
    pos: [20, 10],
    channel: 5
  }),
  a.piston({
    pos: [20, 9],
    dir: "down"
  }),
])
