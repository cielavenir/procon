#!/usr/bin/ruby
#coding:utf-8
OR=->(x,y){ x||y }
AND=->(x,y){ x&&y }
XOR=->(x,y){ x^y }
NAND=->(x,y){!( x&&y )}
NOR=->(x,y){!( x||y )}

def expr(trick,treat,a,b,c)
	b.call(
		OR.call( a.call(trick,treat),treat ),
		c.call(trick,treat)
	)
end

[OR,AND,XOR,NAND,NOR].zip([:OR,:AND,:XOR,:NAND,:NOR]).repeated_permutation(3){|a,b,c|
	if
		expr(false,false,a.first,b.first,c.first)==true &&
		expr(true,false,a.first,b.first,c.first)==false &&
		expr(false,true,a.first,b.first,c.first)==true &&
		expr(true,true,a.first,b.first,c.first)==false
		puts [a.last,b.last,c.last]*' '
	end
}
__END__
NOR AND NAND
5.NOR
1.AND
4.NAND

NOR XOR AND
5.NOR
3.XOR
1.AND