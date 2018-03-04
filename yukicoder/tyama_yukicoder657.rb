#!/usr/bin/ruby
T=[0,0,0,0,1]
999999.times{T<<(T[-4]+T[-3]+T[-2]+T[-1])%17}
gets.to_i.times{p T[gets.to_i]}
