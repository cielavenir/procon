var R = parseInt(readline());
var G = parseInt(readline());
var L = parseInt(readline());

for(;;){
	var s = parseInt(readline());
	var x = parseInt(readline());
	if(s+x-1>=R){
		print('JUMP');
		break;
	}else if(s<=G){
		print('SPEED');
	}else if(s>G+1){
		print('SLOW');
	}else{
		print('WAIT');
	}
}
for(;;)print('SLOW');