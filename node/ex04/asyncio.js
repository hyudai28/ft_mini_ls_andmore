const fs = require('fs')
let data
let ret = 0
fs.readFile(path = process.argv[2], 'utf8', (err, data) => {
		for(let i = 0;i < data.length;i++)
			if (data[i] == '\n')
				ret++;
		/*ret = data.toString().split('\n').length - 1*/
		console.log(ret);
	}
);
console.log("test");

