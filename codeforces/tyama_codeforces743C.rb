#!/usr/bin/ruby
n=gets.to_i;puts n==1 ? -1 : [n,-~n,n*-~n]*' '
