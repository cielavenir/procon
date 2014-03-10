#!/usr/bin/node
(function(){
  var T=[];
  var stdin = process.openStdin();
  stdin.setEncoding('utf8');
  var a=[1,1,2];
  for(var i=3;i<31;i++)a.push(a[i-1]+a[i-2]+a[i-3]);

  stdin.on('data', function(input) {
    var i=0,len,ref,x=[];
    ref=input.split("\n");
    for(len=ref.length;i<len;i++){
    	if(ref[i]=='')continue;
    	x.push(ref[i]^0);
    }
    //リダイレクトしてもttyから読み込んでも実行できる特殊処理
    if(x.length>2||!isNaN(x[1]))T=x;
    else T.push(x[0]);
  });

  stdin.on('end', function(z) {
    for(var i=0;T[i];i++){
      console.log((a[T[i]]+3649)/3650^0);
	}
  });
})();