#!/usr/bin/ruby
$h={'0'=>'0','1'=>'1','2'=>'abc','3'=>'def','4'=>'ghi','5'=>'jkl','6'=>'mno','7'=>'pqrs','8'=>'tuv','9'=>'wxyz'}
$i=0
def d(depth,str,ret)
	if depth==str.length
		print ',' if $i>0
		print ret
		$i+=1
	else
		$h[str[depth,1]].each_byte{|e|
			d(depth+1,str,ret+e.chr)
		}
	end
end
while gets
	$i=0
	d(0,$_.chomp,'')
	puts
end