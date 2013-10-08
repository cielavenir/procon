/*
export MONO_PATH=/Applications/Unity/Unity.app/Contents/Frameworks/Mono/lib/mono/unity
/Applications/Unity/Unity.app/Contents/Frameworks/Mono/bin/mono /Applications/Unity/Unity.app/Contents/Frameworks/Mono/lib/mono/unity/us.exe -b:System.Object -m:Main -target:exe tyama_icpc2012dA.unity.js
/Applications/Unity/Unity.app/Contents/Frameworks/Mono/bin/mono tyama_icpc2007dA.unity.exe <A
*/

import System;

static function Main(){
	var i=0;
	var n=parseInt(Console.ReadLine());
	for(;i<n;i++){
		var a=Console.ReadLine().Split();
		var y=parseInt(a[0])-1;
		var m=parseInt(a[1])-1;
		Console.WriteLine(196471-y*195-y/3*5-m*20+(y%3!=2?m/2:0)-parseInt(a[2]));
	}
}