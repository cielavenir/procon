#!/usr/bin/ruby
k,l=gets.split.map &:to_i;k=1;r=0;gets.bytes{|b|k+=(b==43?1:-1);r,k=k>l ?[r+1,1]:[r,k]};p r