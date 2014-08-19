#!/usr/bin/ruby
while(l=gets.to_f)>0
a=l*16;puts a!=(a=a.to_i)||a>4095?'NA':'%08b.%04b'%[a/16,a%16]end