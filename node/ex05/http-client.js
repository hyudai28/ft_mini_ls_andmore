try {
	let http = require('http')
	let url = process.argv[2]
	http.get(url, (res) => {
		res.setEncoding('utf8')
		//	console.log(res)
		res.on('data', (chunk) => {console.log(chunk)})
		res.on('end',() => {})
	})
		.on('error', (err) =>{
				console.log(err.message)
			})
}catch(err) {
	console.log(err.message)
}
