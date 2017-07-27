#!/usr/bin/ruby
eval"N,K,*A="+`dd`.split*?,;print K>A.max||K%A.reduce(:gcd)>0?:IM:'',:POSSIBLE
