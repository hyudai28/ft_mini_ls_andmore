var http = require('http')

function http_req(url)
{
	return(new Promise((resolve, reject) => 
		{
			let body = []
			try
			{
				http.get(url, (res) => 
					{
						res.setEncoding('utf8')
						res.on('data', (chunk) => 
							{
								body += chunk
							}).on('end',() => 
								{
									resolve(body)
								})
					})
						.on('error', (err) =>{
							console.log(err.message)})
			}
			catch(error)
			{
				reject(error)
			}
		}))
}

Promise.all([http_req(process.argv[2]), http_req(process.argv[3]), http_req(process.argv[4])]).then((values) => 
	{
		for(let i = 0;i < 3;i++) 
			console.log(values[i])
	})
