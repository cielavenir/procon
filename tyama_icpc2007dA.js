import System;

function judge(n:int):void{
  var ma,mi,s,x,i:int;
  ma=0,mi=1000,s=0;
  for(i=0;i<n;i++){
    x=int(Console.ReadLine());
    if(x<mi)mi=x;
    if(x>ma)ma=x;
    s+=x;
  }
  Console.WriteLine(int((s-ma-mi)/(n-2)));
}

while(true){
  var n:int;
  n=int(Console.ReadLine());
  if(n==0)break;
  judge(n);
}