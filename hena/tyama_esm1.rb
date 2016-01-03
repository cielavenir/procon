#!/usr/bin/env ruby
#https://gist.github.com/mtsmfm/4b8ffb53ffac055f5843

N=8
def fill_table(a,n)
	idx=N.times.find{|st|n.times.all?{|i|a[(st+i)%N]==0}}
	if idx
		n.times{|i|a[(idx+i)%N]=1}
		true
	else
		false
	end
end
def clear_table(a)
	N.times{|i|
		a[i]=0 if a[i]==4
	}
end
def take_turn(a)
	N.times{|i|
		a[i]+=1 if a[i]>0
	}
end
		
if __FILE__==$0
	while gets
		a=[0]*N
		$_.chomp.chars{|c|
			clear_table(a)
			f=fill_table(a,c.to_i)
			take_turn(a)
			redo if !f
		}
		puts a.map{|e|e==0 ? 0 : 1}*'' 
		STDOUT.flush
	end
end