for(;;){
	var enemy1 = readline(); // name of enemy 1
	var dist1 = parseInt(readline()); // distance to enemy 1
	var enemy2 = readline(); // name of enemy 2
	var dist2 = parseInt(readline()); // distance to enemy 2
	print(dist1<dist2 ? enemy1 : enemy2);
}