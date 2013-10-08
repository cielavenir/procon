/*
export MONO_PATH=/Applications/Unity/Unity.app/Contents/Frameworks/Mono/lib/mono/unity
/Applications/Unity/Unity.app/Contents/Frameworks/Mono/bin/mono /Applications/Unity/Unity.app/Contents/Frameworks/Mono/lib/mono/unity/us.exe -b:System.Object -m:Main -target:exe tyama_icpc2007dA.unity.js
/Applications/Unity/Unity.app/Contents/Frameworks/Mono/bin/mono tyama_icpc2007dA.unity.exe <A
*/

import System;

static function judge(n){
  var ma=0;
  var mi=1000;
  var s=0;
  var x;
  var i;
  for(i=0;i<n;i++){
    x=parseInt(Console.ReadLine());
    if(x<mi)mi=x;
    if(x>ma)ma=x;
    s+=x;
  }
  Console.WriteLine((s-ma-mi)/(n-2));
}

static function Main(){
  while(true){
    var n=parseInt(Console.ReadLine());
    if(n==0)break;
    judge(n);
  }
}