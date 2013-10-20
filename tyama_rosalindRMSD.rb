#!/usr/bin/ruby
#draft: http://rosalind.info/problems/suggested/21/
def norm(a,b) a.zip(b).map{|e,f|(e-f)**2}.reduce(:+) end
a=$<.map{|e|
	a=e.split.map(&:to_f)
	b=a[3,3];a=a[0,3]
	norm(a,b)
}
p Math.sqrt(a.reduce(:+)/a.size)