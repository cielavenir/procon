#!/usr/bin/ruby
def vec_product(a,b)
	a.zip(b).reduce(0){|s,(x,y)|s+x*y}
end
def matrix_mul(a,_b)
	b=_b.transpose
	a.size.times.map{|i|
		b.size.times.map{|j|
			vec_product(a[i],b[j])
		}
	}
end
n,m=gets.split.map(&:to_i)
matrix_mul(*[n,m].map{|e|e.times.map{gets.split.map(&:to_i)}}).each{|e|puts e*' '}