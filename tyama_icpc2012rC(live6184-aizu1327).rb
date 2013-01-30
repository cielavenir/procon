#!/usr/bin/ruby
def mul(a,b)
	c=$n.times.map{[0]*$n}
	$n.times{|i|
		$n.times{|j|
			#c[i][j]=a[i].zip(b.transpose[j]).map{|e|e.reduce(:*)}.reduce(:+)%$m
			$n.times{|k|c[i][j]=(c[i][j]+a[i][k]*b[k][j])%$m}
		}
	}
	return c
end

def exp(a,n)
	return $e if n==0
	return a if n==1
	return mul(exp(a,n-1),a) if n%2==1
	b=exp(a,n/2)
	mul(b,b)
end

while($n,$m,a,b,c,t=gets.split.map(&:to_i))!=[0]*6
s=gets.split.map(&:to_i)
x=$n.times.map{[0]*$n}
$n.times{|i|
	x[i][i-1]=a if i>0
	x[i][i]=b
	x[i][i+1]=c if i<$n-1
}
$e=$n.times.map{[0]*$n}
$n.times{|i|$e[i][i]=1}
puts exp(x,t).map{|e|e.zip(s).map{|f|f.reduce(:*)}.reduce(:+)%$m}*' '
end