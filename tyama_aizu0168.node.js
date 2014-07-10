#!/usr/bin/node
(function(){
  var T=[];
  var stdin = process.openStdin();
  stdin.setEncoding('utf8');
  var a=[1,1,2];
  for(var i=3;i<31;i++)a.push(a[i-1]+a[i-2]+a[i-3]);

  var input_fragment="";
  stdin.on('data', function(input) {
	var ref=(input_fragment+input).split("\n");
	input_fragment=ref.pop();
	for(var i=0;i<ref.length;i++){
		if(ref[i]=='')continue;
		T.push(ref[i]^0);
	}
  });

  stdin.on('end', function(z) {
    for(var i=0;T[i];i++){
      console.log((a[T[i]]+3649)/3650^0);
	}
  });
})();