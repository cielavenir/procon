#!/usr/bin/groovy
cin=new Scanner(System.in)
while(true){
	name=""
	mi=9999999
	cin.nextInt().times{
		enemy=cin.next()
		dist=cin.nextDouble()
		if(mi>dist){
			mi=dist
			name=enemy
		}
	}
	println name
}