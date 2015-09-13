#!/usr/bin/ruby
n=gets.to_i
puts n==2||n==3||n==5||(n!=1&&n%2!=0&&n%3!=0&&n%5!=0) ? :Prime : 'Not Prime'