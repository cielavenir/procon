var inputs = readline().split(' ');
var x = parseInt(inputs[0]);
var y = parseInt(inputs[1]);
x-=parseInt(inputs[2]);
y-=parseInt(inputs[3]);

var repeat=function(s,n){return Array(n+1).join(s);}

var d0=repeat(y<0?'N':'S',Math.abs(y));
var d1=repeat(x<0?'W':'E',Math.abs(x));
for(var i=0;i<Math.max(d0.length,d1.length);i++)print((d0[i]||'')+(d1[i]||''));