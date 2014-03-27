#!/usr/bin/ruby
P=13
s=(P*P).times.map{'.'*(P*P)}
P.times{|i|
	P.times{|j|
		P.times{|k|
			q=(i*k+j)%P
			s[P*i+j][P*k+q]='O'
		}
	}
}
p 150
150.times{|i|
	puts s[i][0,150]
}