#!/usr/bin/ruby
MOD=1000000007
def pow_binary_mod(x,y)
	z = 1
	while y!=0
		z=z*x%MOD if y&1!=0
		x=x*x%MOD
		y>>=1
	end
	z
end
def div(x,n)
	m=(n%MOD+MOD)%MOD
	raise if m==0
	x*pow_binary_mod(m,MOD-2)%MOD
end

def gauss(a)
	if !a || a.length==0 then return nil end
	n=a.length
	n.times{|i| #各式(i)で
		if a[i][i]==0
			if (i+1).step(n-1){|j|
				if a[j][i]!=0
					i.step(n){|k| a[i][k]+=a[j][k]}
					break
				end
			}
				raise 'given equation is not solvable'
			end
		end
		n.times{|j|
			if j!=i then #式jの
				r = div(a[j][i],a[i][i])
				i.step(n){|k| a[j][k] = a[j][k] - a[i][k]*r} #第i項以降を消去
			end
		}
		#p(a)
	}

	n.times{|i| #係数修正
		x=a[i][i]
		a[i].length.times{|j|
			a[i][j]=div(a[i][j],x)
		}
	}

	return a
end

n=gets.to_i
raise if n>100
a=gets.split.map(&:to_i)
t=gets.to_i
m=(0..n).map{|i|(0..n).map{|j|i**j}+[a[i]]}
p gauss(m).each_with_index.map{|e,i|e.last.to_i*t**i}.reduce(:+)%MOD