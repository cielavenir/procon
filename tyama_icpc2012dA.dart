#!/usr/bin/env dart
//tested on 131012. API might change.

import 'dart:io'; 
main(){
	var i=0,n=0,y=0,m=0;
	n=int.parse(stdin.readLineSync());
	for(i=0;i<n;i++){
		var a=stdin.readLineSync().split(' ').map((e){return int.parse(e);}).toList();
		y=a[0]-1;m=a[1]-1;
		print(196471-y*195-y~/3*5-m*20+(y%3!=2?m~/2:0)-a[2]);
	}
}