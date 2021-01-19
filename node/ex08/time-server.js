let http = require('http')
//require('date-utils')
if (process.argv.length != 3)
{
	console.log("arguments error")
	return ;
}
try{
	let server = http.createServer();
	const port = process.argv[2]
	//let now = new Date()
	server.on('request', function(req, res) {
		require('date-utils')
		let now = new Date()
		res.writeHead(200, { 'Content-Type': 'text/plain' })
		res.write(now.toFormat('YYYY-MM-DD HH:MI'))
		res.write('\n')
		res.end()
	})
	server.listen(port).on('error', (err) =>{
		console.log(err.message)
	})
}
catch(err)
{
	console.error(err)
}
