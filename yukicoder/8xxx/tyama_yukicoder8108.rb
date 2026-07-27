#!/usr/bin/ruby
A=0,1;(2..gets.to_i).map{A<<A[-2]+A[-1]};p A[-1]%998244353
