#!/usr/bin/ruby
#coding:utf-8

STR=gets.chomp
last=0
siz=STR.bytes.to_a.size
please=(siz+3)/4-2
STR.each_byte.with_index{|e,i|
	c = e
	c = (c & 0x55) << 1 | (c & 0xaa) >> 1
	c = (c & 0x33) << 2 | (c & 0xcc) >> 2
	c = (c & 0x0f) << 4 | (c & 0xf0) >> 4
	last2 = c
	c = (last-c)&0xff
	last = last2
	p c&0xff
}

__END__
[cesspool.c]
unsigned int lastout = 0;
c = lastout - a[i];
lastout = c;
c = (c & 0x0f) << 4 | (c & 0xf0) >> 4;
c = (c & 0x33) << 2 | (c & 0xcc) >> 2;
c = (c & 0x55) << 1 | (c & 0xaa) >> 1;
putchar(c);