/*
let http = require('http')
let bl = require('bl')


http.get(process.argv[2], (response) => {
	    response.pipe(bl((err, data) => {
			        if (err)
				            return console.error(err)
			        data = data.toString()
			        console.log(data.length)
			        console.log(data)
			    }))
})
*/

try{
	let http = require('http')
	let url = process.argv[2]

	let lt = 0
	let body = []
	http.get(url,function (res) {
		res.setEncoding('utf8')
		res.on('data', (chunk) => {
			lt += chunk.length
			body += chunk
		})
			.on('end',() => {
				console.log(lt)
				console.log(body)
			})
	})
		.on('error', (err) =>{
			console.log(err.message)
		})
}catch(err){
	console.log(err.message)
}
