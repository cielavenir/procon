#!/usr/bin/ruby
$h={0=>1}
def z(n) $h[n] || $h[n] = n%2==1 ? z(n/2) : z(n/2)+z(n/2-1) end
p z(gets.to_i)
__END__
10000000000000000000000000
