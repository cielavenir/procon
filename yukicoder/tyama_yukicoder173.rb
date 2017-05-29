#!/usr/bin/ruby
n,pa,pb=gets.split.zip([:to_i.to_proc,:to_f.to_proc,:to_f.to_proc]).map{|x,y|y.call(x)}
A=gets.split.map(&:to_i).sort
B=gets.split.map(&:to_i).sort
win=0
total=0
30000.times{
	total+=1
	a=A.dup
	b=B.dup
	a_score=b_score=0
	n.times{|i|
		a_idx=i==n-1||rand<pa ? 0 : [*1...n-i].sample
		b_idx=i==n-1||rand<pb ? 0 : [*1...n-i].sample
		score=a[a_idx]+b[b_idx]
		a_score+=score if a[a_idx]>b[b_idx]
		b_score+=score if a[a_idx]<b[b_idx]
		a=a[0,a_idx]+a[a_idx+1..-1]
		b=b[0,b_idx]+b[b_idx+1..-1]
	}
	win+=1 if a_score>b_score
}
p win*1.0/total
