#!/usr/bin/ruby
class Array
	def permutation2(n=self.size)
		return to_enum(:permutation2,n) unless block_given?
		return if n<0||self.size<n
		a=self.sort
		yield a[0,n]
		loop{
			a=a[0,n]+a[n..-1].reverse
			k=(a.size-2).downto(0).find{|i|a[i]<a[i+1]}
			break if !k
			l=(a.size-1).downto(k+1).find{|i|a[k]<a[i]}
			a[k],a[l]=a[l],a[k]
			a=a[0,k+1]+a[k+1..-1].reverse
			yield a[0,n]
		}
	end
end

N=6
P=([0]*N+[1]*N).permutation2.to_a # N=5のとき、permutation.to_a.uniqの70倍速
#各Pは経路を表す。1が縦、0が横を表す。
r=0
P.each{|e0|
	P.each{|f0|
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		(N*2).times{|i|
			zero1 += e0[i]==0 ? 1 : 0
			one1  += e0[i]==1 ? 1 : 0
			zero2 -= f0[N*2-1-i]==0 ? 1 : 0
			one2  -= f0[N*2-1-i]==1 ? 1 : 0
			flg+=1 if zero1==zero2
			flg+=1 if one1==one2
		}
		r+=1 if flg>=2
	}
}
p r # 527552