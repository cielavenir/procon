#!/usr/bin/ruby
N,M,*X=$<.read.split.map &:to_i;p (0..2*N).bsearch{|n|c=1;X.all?{|e|(n>=b=c>e ?0:e-c)&&c=-~e+(n>b*3?n-b*2:n-b>>1)}&&c>N}
#N,M,*X=$<.read.split.map &:to_i;p (0..2*N).bsearch{|n|c=0;X.all?{|e|(n>=b=c<e ?~c+e :0)&&c=e+(n>b*3?n-b*2:n-b>>1)}&&c>=N}
#N,M,*X=$<.read.split.map &:to_i;p (0..2*N).bsearch{|n|c=-1;X.all?{|e|(n>=b=-c>e ?0:e+c)&&c= ~e-(n>b*3?n-b*2:n-b>>1)}&&-c>N}

__END__
N,M=gets.split.map(&:to_i)
X=M.times.map{gets.to_i}
p (0..N-1+[X[0]-1,N-X[M-1]].min).bsearch{|n|
	cur=1
	X.each{|e|
		cur=e if cur>e
		back=e-cur
		break if back>n
		cur=1+e+(n>3*back ? n-back*2 : (n-back)/2)
	} && cur>N
}
 
n-back*2>(n-back)/2
2n-4back>n-back
n>3back