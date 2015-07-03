#!/usr/bin/ruby
C=[*?A..?Z]
S=[*?a..?z]
gets
s=gets
N=gets.to_i
puts s.tr(C*''+S*'',C.rotate(N)*''+S.rotate(N)*'')