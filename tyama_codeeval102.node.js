#!/usr/bin/node
(function() {
  var a=[];
  var stdin = process.openStdin();
  stdin.setEncoding('utf8');

  stdin.on('data', function(input) {
    var i=0,len,ref,x=[];
    ref=input.split("\n");
    for(len=ref.length;i<len;i++)x.push(ref[i]);
    if(x.length>2||!isNaN(x[1]))a=x;
    else a.push(x[0]);
  });

  stdin.on('end', function(z) {
    for(var i=0;i<a.length;i++){
      if(!a[i])continue;
      var json=JSON.parse(a[i])['menu']['items'];
      var n=0;
      for(var j=0;j<json.length;j++)if(json[j]&&json[j]['label'])n+=json[j]['id'];
	  console.log(n);
    }
  });
}).call(this);