#!/usr/bin/ruby
#130629 fixed: sin/cos/tan must convert from deg to rad.
require 'mathn'
def lg(n) Math.log10(n) end
def ln(n) Math.log(n) end
def sqrt(n) Math.sqrt(n) end
def sin(n) Math.sin(n*Math::PI/180) end
def cos(n) Math.cos(n*Math::PI/180) end
def tan(n) Math.tan(n*Math::PI/180) end
puts$<.map{|l|
	x=l.gsub('Pi','Math::PI').gsub('e','Math::E').gsub('^','**')
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
sin(sqrt(5!))*lg(21)*Pi/e
tan(0) / 1
ln(e)^21
sin(Pi^2) + cos(Pi^2)
sin(cos(tan(lg(ln(13)))))
tan(0.0001)