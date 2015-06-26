#!/usr/bin/ruby
T,a,b=gets.split.map &:to_i
if [a,b].max>T || (T==1 && a+b==0)
	puts :NO
else
	puts :YES
	r=[]
	if a==0 && (b-T)%2>0
		r<<'^'
		r<<'v>'
		b-=1
	elsif b==0 && (a-T)%2>0
		r<<'>'
		r<<'<^'
		a-=1
	elsif a+b>0 && (T-a-b)%2==0 && T>a+b
		r<<'>'
		r<<'^'
		a-=1
		b-=1
	end
	n=[a,b].min
	n.times{r<<'^>'}
	a-=n
	b-=n
	a.times{r<<'^'}
	b.times{r<<'>'}
	((T-r.size)/2).times{
		r<<'^'
		r<<'v'
	}
	puts r
end