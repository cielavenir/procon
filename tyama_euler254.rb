#!/usr/bin/ruby
#answer is confirmed on http://wonderfl.net/c/sDkG
$fact={}
10.times{|i|$fact[i]=(2..i).reduce(:*)||1}
def d(a,s,depth,n,c,t)
	if depth==n
		if s.to_s.chars.map(&:to_i).reduce(:+)==t
			return a.map(&:to_s).join.to_i
		else
			return nil
		end
	end
	c.step(9){|i|
		a[depth]=i
		r=d(a,s+$fact[i],depth+1,n,i,t)
		return r if r
	}
	return nil
end

class Integer
	#def fact() (2..self).reduce(:*)||1 end
	#def f() self.to_s.chars.map(&:to_i).map(&:fact).reduce(:+) end
	#def sf() self.f.to_s.chars.map(&:to_i).reduce(:+) end
	def g
		#(1..1/0.0).each{|i|
		#	a=i.to_s.split('')
		#	next if a!=a.sort
		#	p i
		#	return i if i.sf==self
		#}
		(1..1/0.0).each{|i|
			r=d([],0,0,i,1,self)
			if r then return r end
		}
	end
	def sg() self.g.to_s.chars.map(&:to_i).reduce(:+) end
end
a=(1..59).map{|i|p i;i.sg}.reduce(:+)
#p a # => 2278

def rec2c(a,n)
	if n==0 then return 0
	else
		a.length.times{|i|
			if n>=a[i] && a.find{|e|(n-a[i])%e==0}
				r=rec2c(a,n-a[i])
				if r>=0 then return r+9-i end
			end
		}
	end
	return nil
end
$a=[1]
1.step(9){|i|$a<<$fact[i]}
$a.reverse!

#fake... fake...
def d1(a,s,depth,n,t)
	if depth==n || (n-depth)*9<t-s then return nil end
	m=1/0.0
	1.step(9){|i|
		if s+i>t then break end
		a[depth]=i.to_s
		if s+i==t then
			r=rec2c($a,a.join.to_i)
			a[depth]=nil
			return r
		end
		r=d1(a,s+i,depth+1,n,t)
		if r&&m>r then m=r end
	}
	m
end
b=(60..63).map{|i|d1([],0,0,7,i)}.reduce(:+)
#p b # => 1120

def z(q)
	n=([(q+8)%9+1]+[9]*((q-1)/9)).map(&:to_s).join.to_i
	m=n % $a[0]
	x=n / $a[0]*9
	r=rec2c($a,m)
	r+x
end
c=(64..150).map{|i|z(i)}.reduce(:+)
#p c # => 8184523817112
#p a+b+c # => 8184523820510