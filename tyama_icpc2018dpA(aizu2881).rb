#!/usr/bin/ruby -an
$F.size>1 and puts $F[1].to_i>31||($F[1].to_i==31&&$F[2].to_i>4)?$_.split.tap{|e|e[0]='?';e[1]=e[1].to_i-30}*' ':$_
