#!/usr/bin/ruby
#wget -O - http://projecteuler.net/project/base_exp.txt
z=[];i=0
while gets do a,b=$_.split(',').map &:to_i;z<<[b*Math.log(a),i+=1] end
p z.max[1]