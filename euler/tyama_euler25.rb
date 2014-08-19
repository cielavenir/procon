#!/usr/bin/ruby
result=[1,1]
a,b,n=1,1,2
digits=2
while digits<=5000
	while b<10**(digits-1) do a,b,n=b,a+b,n+1 end
	result[digits]=n
	digits+=1
end
gets.to_i.times{
	p result[gets.to_i]
}
__END__
1
1000