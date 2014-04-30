#!/usr/bin/node

function yourCode() {
	var arr = [];
	var RNG_X = 36;
	var RNG_Y = 18;
	for (var y = -RNG_Y; y <= RNG_Y; y ++) {
		for (var x = -RNG_X; x <= RNG_X; x ++) {
			arr.push(
				//Level1
				//(Math.pow(Math.abs(x)/32,3)+Math.pow(Math.abs(y)/8,3)<=1)+(Math.pow(Math.abs(x)/16,3)+Math.pow(Math.abs(y)/16,3)<=1)*2
				//(X=x>0?x:-x,Y=y>0?y:-y,(X*X*X+Y*Y*Y*64<=32768)+(X*X*X+Y*Y*Y<=4096)*2) //69
				//(X=Math.abs(x*x*x),Y=Math.abs(y*y*y),(X+Y*64<=32768)+(X+Y<=4096)*2) //67
				//((X=Math.abs(x*x*x))+(Y=Math.abs(y*y*y))*64<=32768)+(X+Y<=4096)*2 //65
				//$('#sample').text().split('\n')[y+18][x+36] //43 (forbidden)
				//$('#sample').text()[(y+18)*74+x+36] //35 (forbidden)
				//$('#sample').text()[74*y+x+1368] //32 (forbidden)
				//Level2
				//(A=function(z){if(z<0)z=-z;return z},X=A(x),Y=A(y),(X*X*X+Y*Y*Y*64<=32768)+(X*X*X+Y*Y*Y<=4096)*2) //97
				//(A=function(z){if(z<0)z=-z;return z},X=A(x*x*x),Y=A(y*y*y),(X+Y*64<=32768)+(X+Y<=4096)*2) //89
				//(X=(x^(z=x>>31))-z,Y=(y^(z=y>>31))-z,(X*X*X+Y*Y*Y*64<=32768)+(X*X*X+Y*Y*Y<=4096)*2) //83
				//(X=((X=x*x*x)^(z=X>>31))-z,Y=((Y=y*y*y)^(z=Y>>31))-z,(X+Y*64<=32768)+(X+Y<=4096)*2) //83
				//(X=(x>>9|1)*x*x*x,Y=(y>>9|1)*y*y*y,(X+Y*64<=32768)+(X+Y<=4096)*2) //65
				//((X=(x>>9|1)*x*x*x)+(Y=(y>>9|1)*y*y*y)*64<=32768)+(X+Y<=4096)*2 //63
				((X=(x>>9|1)*x*x*x)+(Y=(y>>9|1)*y*y*y)<4097)*2|X/64+Y<=512 //58
				//document.getElementById((function sample(){}).name).textContent.charAt(74*y+x+1368) //83 (forbidden)
				//Level3
				//(A=function(z){if(z<0)z=-z;return z},X=A(x),Y=A(y),M=function(a,b){for(r=0;b;a+=a,b>>=1)if(b%2)r+=a;return r},(M(X,M(X,X))+(M(Y,M(Y,Y))<<6)<=32768)+M(M(X,M(X,X))+M(Y,M(Y,Y))<=4096,2)) //183
				//(A=function(z){if(z<0)z=-z;return z},X=A(x),Y=A(y),M=function(a,b){for(r=0;b;a+=a,b>>=1)if(b%2)r+=a;return r},X=M(X,M(X,X)),Y=M(Y,M(Y,Y)),(X+(Y<<6)<=32768)+M(X+Y<=4096,2)) //171
				//(X=(x^(z=x>>31))-z,Y=(y^(z=y>>31))-z,M=function(a,b){for(r=0;b;a+=a,b>>=1)if(b%2)r+=a;return r},X=M(X,M(X,X)),Y=M(Y,M(Y,Y)),(X+(Y<<6)<=32768)+M(X+Y<=4096,2)) //157
				//(A=function(z){if(z<0)z=-z;return z},X=A(x),Y=A(y),M=function(a,b){for(r=0;b--;)r+=a;return r},X=M(X,M(X,X)),Y=M(Y,M(Y,Y)),(X+(Y<<6)<=32768)+M(X+Y<=4096,2)) //156
				//(X=(x^(z=x>>31))-z,Y=(y^(z=y>>31))-z,M=function(a,b){for(r=0;b--;)r+=a;return r},X=M(X,M(X,X)),Y=M(Y,M(Y,Y)),(X+(Y<<6)<=32768)+M(X+Y<=4096,2)) //142
				//document.getElementById((function sample(){}).name).textContent.charAt((y<<6)+(y<<3)+y+y+x+1368) //96 (forbidden)
			);
		}
	}
	return arr;
}

console.log(yourCode().join(','));
//MD5  623eb6fd17c459da129782219f76e18e
//SHA1 192961c983cb8ca03d43ae21490c3d26c99538bf