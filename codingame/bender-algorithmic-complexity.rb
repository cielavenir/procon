#!/usr/bin/ruby
N=gets.to_i
a=N.times.map{
	gets.split.map(&:to_f)
}.sort
b=a.each_cons(2).map{|(a,b),(x,y)|(y-b)/(x-a)}
f=b[0,4].reduce(:+)
g=b[-4..-1].reduce(:+)
nd=a[-2][0]-a[2][0]
n=g/f / nd
#適当にやっても半分は取れてしまう
if n<0.000001
	puts 'O(1)'
elsif n<0.0001
	puts 'O(log n)'
elsif n<0.0015
	puts 'O(n)'
elsif n<0.002
	puts 'O(n log n)'
elsif n<0.005
	puts 'O(n^2)'
elsif n<0.1
	puts 'O(n^2 log n)'
elsif n<1
	puts 'O(n^3)'
else
	puts 'O(2^n)'
end