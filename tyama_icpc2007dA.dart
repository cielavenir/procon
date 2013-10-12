#!/usr/bin/env dart
//tested on 131012. API might change.

import 'dart:io'; 
main(){
	var n=-1,m=0,s=0,ma=0,mi=1000;
	//var stdin=new Stdin();
	while(true){
		var line = stdin.readLineSync();
		if(line != null){
			if(n==-1){
				n=int.parse(line);
				if(n==0)break;
				m=n;
			}else{
				var x=int.parse(line);
				if(ma<x)ma=x;
				if(mi>x)mi=x;
				s+=x;
				m-=1;
				if(m==0){
					print((s-ma-mi)~/(n-2));
					n=-1;s=0;ma=0;mi=1000;
				}
			}
		}
	}; 
}