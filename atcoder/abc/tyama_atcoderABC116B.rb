#!/usr/bin/ruby
n=gets.to_i;p (4..1/0.0).find{b=[1,2,4].index n;n=[n/2,n*3+1][n%2];b}
