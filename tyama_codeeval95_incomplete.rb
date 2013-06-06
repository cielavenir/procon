#!/usr/bin/ruby
require 'mathn'
include Math
def sin
puts$<.map{|l|
	x=l.gsub('Pi','PI').gsub('e','E').gsub('lg','log10').gsub('ln','log').gsub('^','**')
	x=x.gsub(/(\d+)!/){(1..$1.to_i).reduce(:*).to_s}
	x=x.gsub(/\|(.*)\|/,'(\1).abs').gsub(/\|(.*)\|/,'(\1).abs')
	x=x.gsub(/(\d+) mod (\d+)/){$1.to_i%$2.to_i}
	("%.5f"%eval(x)).sub(/0+$/,'').sub(/\.$/,'')
}

__END__
2+2					
234*75
34/4
12/2
3.48234621 - 9.3457215127
3.482 * 9.34
3.48234621*2 - 9.3457215127/1
8.654^4*3
-(48)+2
-(0.048-0.047)^-1
241 * 14.3
4^6 / 147
4 / 147^-1
(59 - 15 + 3*7)/21
(35-(43.568*34-23456)*3/(8312))+(-21)
(((12-43.2) + 823.592)*(23.34/2))-2^1
(((12-43.2) + 823.592)*(23.34/2))-2^-2
Pi
e
|-|33/7 mod 5||
sin(sqrt(5!))*lg(21)*Pi/e -> not OK
tan(0) / 1
ln(e)^21
sin(Pi^2) + cos(Pi^2) -> not OK
sin(cos(tan(lg(ln(13))))) -> not OK
tan(0.0001) -> not OK, answer = 0