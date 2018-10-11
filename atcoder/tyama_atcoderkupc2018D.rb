#!/usr/bin/ruby
F=->n{puts'? %d'%n;STDOUT.flush;gets.chomp=='odd'}
q=F[2]
s=1
29.downto(1){|i|
  next if s+2**i>1e9
  s+=2**i if F[s+2**i]!=q
}
puts'! %d'%(s+(q ? 0 : 1))
