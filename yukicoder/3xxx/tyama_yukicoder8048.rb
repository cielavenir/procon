#!/usr/bin/ruby
require'zlib'
S=DATA.read
M=10**9+7
BSE=5000000
def f(n)
	if n>=M
		0
	elsif false
		r=1
		n.times{|i|
			r=r*(i+1)%M
			p r if (i+1)%BSE==0
		}
		r
	else
		d,n=n.divmod BSE
		r=Zlib.inflate(S.unpack('m')[0]).split.map(&:to_i)[d]
		n.times{|i|
			r=r*(d*BSE+i+1)%M
		}
		r
	end
end
k=gets.to_i
if k%2>0
	p 0
	exit
end
p f(k)*f(k/2).pow(M-2,M)**2%M
__END__
eNolycG1ZUEIQtE50ZSKCPkn1vf9PqO9oJDj05GG3IzTwcYulRpM1at5xlqzT/dw4iU0qDFvUrgel8ZE
XbuPb6AbnnfAd1fxFPpGnnfQ03TPM9S7JNsoKSJRie08Y4dMuRu2377rgc3hPBnpsx+PqOpmOod2WdNH
3L2tujSkv/sOmX1+fgP17HDUuJzpciH33u5Ooad7Z/TQqjHrFtp0k0NU1nYy2JcXlQcSH1vCeatmeFie
tJ5GourWDerF49VguGOXkJnmag6pmnincE2lrg9VjFcajJze0KDIlSm07PFPGbfy7qFGr8UcVrz11aKq
Jy81KF3zUYuaZfxI2GE96qHrllQPEr1cFLAymh1C726eb7Hvnd/S0NZzPTUkV8/2YjWcbgrVpo8Kppyt
6GFe7ooPmfC9W2z3Y64/bcLrT/Py1qqFmnvHEsZ6fdvElWJliXJ6Uv3psuVHoehtqw7buRYdhG912wPe
XDk6pO6ZLaLesrI02Ok75SFzfHnPSFTi9IHlnRsas9Yu63C381Y5rDzp2cOkPb7XOL93vWVsdHMhQbUm
eYY50zUR+rbeqgNOv3mpQ176G7OYLnn1jKSScWPfm57CvZlcHmFN79shbv4XlJ/jeULO82oWFq28XujZ
PZ4D5Uo10atixQPmw86nYrkvd5Dtl8uDIrXdBveoaAjNZZJZ7OvOcQlX7e3lQL+dpmE6TaXQelVLo6bu
emT0VcWcwzUp7jtsPe27PPS1i3eFFcv2CtOqzbyArFmR4Kq2nwmX0tk75A0ln9HletfVSPeu3KhouC/G
KZfdKvDdlt815ua4lYfivX2nhZ6a5StIYkZv4F5fJcSqXpVekL1MqojTdq0TcNa+OqNfzaTnwdvz+GZB
Je1+hjTz7ubAYo+0D3PbubtGV9FH6dNtfC/QaVsVQc2ihwInrEoVdHXD3EHk26cQau57W4urbTHPOHrr
jQNX/OpM9JtKOcbwvXmVAnuypSPmd75nQZ2zKoNhPb+aha69b1WQebSr4eKoP0JPva8M95jLCHWrsftQ
Jel2BqVJe3joFW+6DpPZ1VWgPu1XQ77+WERzL6snjDrdaaxF7u0gOxoOH+q6ih2j9SiFQWXOdU3cqpZ6
n87x3AXMm3o98FjOEVmmBlNbb1SLoSK9HUR73h5huvJeXoHpY0mLnb7XNYu5m87rhXniVuunZfoa0+v4
oFj1pX8xuXSu
