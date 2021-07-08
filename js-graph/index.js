const Graph = require('graphology');
const random = require('graphology-layout/random');
const node = require('graphology-canvas/node');

const graph = new Graph();
graph.addNode('John');
graph.addNode('Martha');
graph.addEdge('John', 'Martha');

random(graph, {scale: 5})
// random.assign(graph);

node.renderToPNG(graph, './graph.png', () => console.log('Done!'));
