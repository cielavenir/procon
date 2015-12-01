#!/usr/bin/ruby
p 2.times.map{gets.split.map(&:to_i)}.transpose.map.with_index(1){|(m,w),x|[150*x,(500-2*m)*x-50*w].max}.reduce(:+)+gets.split.map(&:to_i).zip([100,-50]).map{|x,y|x*y}.reduce(:+)