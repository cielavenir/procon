#!/usr/bin/ruby

=begin
class String
	def <=>(other)
		# *** Never compare Strings in this method ***
		r=self.size<=>other.size
		return r if r!=0
		siz=[self.size,other.size].max
		a='0'*(siz-self.size)+self
		b='0'*(siz-other.size)+other
		siz.times{|i|
			r=a[i].ord<=>b[i].ord
			return r if r!=0
		}
		return 0
	end
end
=end
def compare(a,b)
	r=a.size<=>b.size
	return r if r!=0
	return a<=>b
end

class Solve
	def initialize(_str)
		@memo={}
		@str=_str
	end
	def dfs(s,prev)
		return 0 if s==''
		return nil if s[0,1]=='0'
		return @memo[[s,prev]] if @memo.has_key?([s,prev])
		r=nil
		(prev.size-1).step(s.size-1){|i|
			#if prev.to_i<s[0..i].to_i
			#if prev<s[0..i]
			if compare(prev,s[0..i])==-1
				x=dfs(s[i+1..-1],s[0..i])
				if x
					r||=x+1
					r=[r,x+1].max
				end
			end
		}
		return @memo[[s,prev]]=r
	end
	def run
		return dfs(@str,'0')
	end
end

STDOUT.sync=true
while gets
	p Solve.new($_.chomp).run
end