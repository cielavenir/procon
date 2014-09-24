#!/usr/bin/ruby
loop{
	a=3
	b=5
	n,s=gets.split
	if n=='0' then break end
	ans=''
	f=nil
	if n.to_i%a==0 then ans+='Fizz';f=1 end
	if n.to_i%b==0 then ans+='Buzz';f=1 end
	if !f then ans=n end
	puts ans==s ?'OK':'NG'
}