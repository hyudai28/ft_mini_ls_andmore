const fs = require('fs')
try
{
	let ret = 0;
	let text = fs.readFileSync(process.argv[2], 'utf8')
//	let text = fs.readFileSync(process.argv[2])
//	text = text.toString()
	for(let i = 0; i < text.length; i++)
	{
		if (text[i] == '\n')
			ret++;
	}
	console.log(ret)
}
catch(error)
{
	console.log(error)
}
