#!/usr/bin/ruby
#progress report for POH paizen
while true
h,w=gets.split.map(&:to_i)
break if h==0
a=h.times.map{gets.chomp.chars.map{|c|c=='.' ? 1 : 0}+[0]}
#accum=h.times.map{[0]*w}
1.step(h-1){|i|
	0.step(w-1){|j|
		a[i][j]+=a[i-1][j] if a[i][j]>0
	}
}
#a.each{|e|p e}
ans=0
0.step(h-1){|i|
	stk=[]
	0.step(w){|j|
		cur=a[i][j]
		if stk.empty? or stk.last[1]<cur
			stk.push([j,cur])
		elsif stk.last[1]>cur
			idx=j
			while !stk.empty? and stk.last[1]>=cur
				height=stk.last[1]
				idx=stk.last[0]
				ans=[ans,height*(j-idx)].max
				stk.pop
			end
			stk.push([idx,cur])
		end
	}
}
p ans
end