#!/usr/bin/groovy
input = new Scanner(System.in);

for(;;){
	enemy1 = input.next() // name of enemy 1
	dist1 = input.nextInt() // distance to enemy 1
	enemy2 = input.next() // name of enemy 2
	dist2 = input.nextInt() // distance to enemy 2

	println(dist1<dist2 ? enemy1 : enemy2)
}