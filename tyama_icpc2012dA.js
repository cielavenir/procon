import System;

var i,n,y,m:int;
n=int(Console.ReadLine());
for(i=0;i<n;i++){
	var a:String[];
	a=Console.ReadLine().Split();
	y=int(a[0])-1;m=int(a[1])-1;
	Console.WriteLine(196471-y*195-int(y/3)*5-m*20+(y%3!=2?int(m/2):0)-int(a[2]));
}