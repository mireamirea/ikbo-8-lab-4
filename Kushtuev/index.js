var brain = require("brain");

let net = new brain.NeuralNetwork();

let options = {
  errorThresh: 0.0005,  // error threshold to reach
  iterations: 20000,   // maximum training iterations
  log: true,           // console.log() progress periodically
  logPeriod: 10,       // number of iterations between logging
  learningRate: 0.3    // learning rate
}

let data = {
	input: [0, 0, 0], output: [1], 
	input: [0, 0, 1], output: [1], 
	input: [0, 1, 0], output: [1], 
	input: [0, 1, 1], output: [1], 
	input: [1, 0, 0], output: [1], 
	input: [1, 0, 1], output: [1], 
	input: [1, 1, 0], output: [1], 
	input: [1, 1, 1], output: [0], 
};


switch (process.argv[2]) {
	case '-help': 
		console.log('node index <error trash> <iterations> <log period>');
		break;

	default: 

		options.errorTrash = !isNaN(parseFloat(process.argv[2])) ? options.errorTrash : parseFloat(process.argv[2]);   
		options.iterations = !isNaN(parseInt(process.argv[3])) ? options.iterations : parseInt(process.argv[3]);   
		options.logPeriod = !isNaN(parseInt(process.argv[4])) ? options.logPeriod : parseInt(process.argv[4]);   

		index(data, options)

		break;
}

function index(data, options) {
	let train = net.train(data, options)

	console.log('Neural train error: ' + train.error);
	console.log('Neural train iterations: ' + train.iterations);
}


