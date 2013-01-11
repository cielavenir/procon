#!/usr/bin/env dart
//tested on 120528. API might change.

#import('dart:io'); 
main(){
	var n=-1,m=0,s=0,ma=0,mi=1000;
	var stream = new StringInputStream(stdin); 
	stream.onLine = (){
		var line = stream.readLine();
		if(line != null){
			if(n==-1){
				n=Math.parseInt(line);
				m=n;
			}else{
				var x=Math.parseInt(line);
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