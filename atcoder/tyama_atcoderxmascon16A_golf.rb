#!/usr/bin/ruby
n=gets.to_i;r=0;($>.<<("? %d %d\n"%[n-=q=n&-n,n+q]).flush;r+=gets.to_i)while n>0;puts'! %d'%r
