#!/usr/bin/node
(function() {
  var T=[];
  var S=[];
  var stdin = process.openStdin();
  stdin.setEncoding('utf8');

  var rec=function(x,y){
    if(0<=x&&x<T[0].length&&0<=y&&y<T.length&&T[y][x])
      T[y][x]=0,rec(x-1,y),rec(x+1,y),rec(x,y-1),rec(x,y+1),
      rec(x-1,y-1),rec(x+1,y-1),rec(x-1,y+1),rec(x+1,y+1);
  }

  stdin.on('data', function(input) {
    var i=0,len,ref,x=[];
    ref=input.split("\n");
    for(len=ref.length;i<len;i++){
    	if(ref[i]=='')continue;
    	var y=ref[i].split(" ");
    	for(var j=0;j<y.length;j++)y[j]=parseInt(y[j])
    	x.push(y);
    }
    if(x.length>2||!isNaN(x[1]))S=x;
    else S.push(x[0]);
  });

  stdin.on('end', function(z) {
    var i,j,r;
    for(;;){
      r=0;
      var h=(S.shift())[1];
      if(!h)break;
      T=S.slice(0,h);
      for(i=0;i<T[0].length;i++)for(j=0;j<T.length;j++)if(T[j][i])r++,rec(i,j);
      console.log(r);
      S=S.slice(h);
    }
  });
}).call(this);