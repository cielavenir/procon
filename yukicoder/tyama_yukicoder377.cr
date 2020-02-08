#!/usr/bin/env crystal
M=1000000007_i64
def pow(x : Int64,y : Int64,m : Int64)
	z=1_i64
	while y>0
		z=z*x%m if y%2>0
		x=x*x%m
		y//=2
	end
	z
end
def prime_division(n)
	Process.run("factor",["factor",n.to_s]){|io|
		h=Hash(Int64,Int64).new(0_i64)
		io.output.gets.not_nil!.split()[1..-1].each{|e|h[e.to_i64]+=1}
		h.map{|k,v|[k,v]}
	}
end
def divisor_totient(a,d,n,t,&blk : (Int64,Int64)->_)
	if d==a.size
		blk.call(n,t)
	else
		(0..a[d][1]).each{|i|
			divisor_totient(
				a,d+1,
				n*pow(a[d][0],i.to_i64,M),
				i==0 ? t : t*(a[d][0]-1)*pow(a[d][0],(i-1).to_i64,M),&blk)
		}
	end
end

cache=Hash(Int64,Int64).new
h,w,k=ARGF.gets_to_end.split.map(&.to_i64)
a=prime_division(h)
b=prime_division(w)
r=0_i64
divisor_totient(a,0,1_i64,1_i64){|ad,at|
	divisor_totient(b,0,1_i64,1_i64){|bd,bt|
		key=w*h//ad.lcm(bd)
		cache[key]=pow(k,key,M) if !cache.has_key?(key)
		r=(r+at*bt%M*cache[key])%M
	}
}
p r*pow(w*h%M,M-2,M)%M