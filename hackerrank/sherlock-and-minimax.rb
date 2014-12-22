#!/usr/bin/ruby
def calc(a,m)
	a.map{|e|(e-m).abs}.min
end
gets
a=gets.split.map(&:to_i).sort
p,q=gets.split.map(&:to_i)
r=calc(a,p)
_r=p
a.each_cons(2){|x,y|
	n=(x+y)/2
	if p<=n&&n<=q && (v=calc(a,n))>r
		r=v
		_r=n
	end
}
if (v=calc(a,q))>r
	r=v
	_r=q
end
p _r