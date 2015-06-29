#!/usr/bin/ruby
#wget -O - https://projecteuler.net/project/resources/p099_base_exp.txt
z=[];i=0
while gets do a,b=$_.split(',').map &:to_i;z<<[b*Math.log(a),i+=1] end
p z.max[1]