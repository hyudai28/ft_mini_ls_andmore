let adsum = 0;
for(let i = 2;i < process.argv.length; i++)
{
	adsum += +(process.argv[i]);
}
console.log(adsum);
