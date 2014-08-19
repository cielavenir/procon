#!/usr/bin/node
(function() {
  var a=[];
  var stdin = process.openStdin();
  stdin.setEncoding('utf8');

  var input_fragment="";
  stdin.on('data', function(input) {
	var ref=(input_fragment+input).split("\n");
	input_fragment=ref.pop();
	for(var i=0;i<ref.length;i++){
		if(ref[i]=='')continue;
		T.push(ref[i]);
	}
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