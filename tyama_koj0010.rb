#!/usr/bin/ruby
gets.to_i.times{
	a=3
	b=5
	n,s=gets.split
	ans=''
	f=nil
	if n.to_i%a==0 then ans+='Fizz';f=1 end
	if n.to_i%b==0 then ans+='Buzz';f=1 end
	if !f then ans=n end
	puts ans==s ?'OK':'NG'
}