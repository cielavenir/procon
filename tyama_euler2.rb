#!/usr/bin/ruby
a=[1,2]
i=1;while(s=a[i]+a[i-1])<4*10**16 do a<<s;i+=1 end
gets.to_i.times{
	n=gets.to_i
	p a.take_while{|e|e<=n}.reduce(0){|s,e|s+=e%2==0?e:0}
}
__END__
1
4000000