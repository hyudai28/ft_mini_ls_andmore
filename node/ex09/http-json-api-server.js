const http = require('http')
const url = require('url')

if (process.argv.length != 3)
{
	console.log("argument error")
	return
}
const port = process.argv[2]
const server = http.createServer((request,response) => {
	if (request.method == 'GET') {
		const parsedURL = url.parse(request.url, true)
		const path = parsedURL.pathname
		const date = new Date(parsedURL.query.iso)

		if (path == '/api/parsetime')
		{
			const output = { 
				hour: date.getUTCHours(),
				minute: date.getMinutes(),
				second: date.getSeconds()
			}
			if (isNaN(output.hour))
				{
					console.log("invalid")
					response.end()
					return
				}
				response.writeHead(200,{'content-type':'application / json'})
				response.write(JSON.stringify(output))
			}
		else if (path == '/api/unixtime') {
			response.writeHead(200,{'content-type':'application / json'})
			const output = { "unixtime" : date.getTime()}
			if (isNaN(output.unixtime))
			{
				console.log("invalid")
				response.end()
				return
			}
			response.write(JSON.stringify(output))
		}
		else{
			response.writeHead(404)
			console.log("argument err")
		}
		response.end()
	}
})
			server.listen(port).on('error', function (err){
				console.log(err.message)})

