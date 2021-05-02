#!/usr/bin/ruby
A,B=gets.split.map &:to_i
K=35
M=K.times.map{'#'*(2*K)}+K.times.map{'.'*(2*K)}
(A-1).times{|i|M[i/K*2][i%K*2]='.'}
(B-1).times{|i|M[2*K-1-i/K*2][i%K*2]='#'}
puts [2*K,2*K]*' '
puts M
