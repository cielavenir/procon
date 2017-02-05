#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;f=0
puts %w(Second First)[loop{
	b=a.map{|e|e&1^1}
	s=b.reduce :+
	s==n-1&&(0...n).find{|i|b[i]==0&&a[i]>1&&a[i]-=1}||(break f^=s&1)
	g=a.reduce :gcd
	a=a.map{|e|e/g}
	f^=1
}]
