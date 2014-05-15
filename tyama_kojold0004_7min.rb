#!/usr/bin/ruby
loop{
	a,b,n,s=gets.split
	if n=='0' then break end
	a=a.to_i;b=b.to_i
	ans=''
	f=nil
	if n.to_i%a==0 then ans+='Fizz';f=1 end
	if n.to_i%b==0 then ans+='Buzz';f=1 end
	if !f then ans=n end
	puts ans==s ?'OK':'NG'
}