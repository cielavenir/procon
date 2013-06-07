#!/usr/bin/ruby
require 'net/http'
require 'digest/md5'
require 'base64'
#2013/06/03: d087b2a758e31b8e026425ab68ec6522 -> MTgw
#2013/06/04: 45dedbe49c95fce54c4561bbf240f4e1 -> Mjgw
#2013/06/05: 1974dc043923c87497e040acd0a23d38 -> Mzgw
T=[*'0'..'9']+[*'A'..'Z']+[*'a'..'z']+['+','/']
def toInt(s)
	#s.chars.each_with_index.map{|e,i|T.index(e)*T.size**(s.size-1-i)}.reduce(:+)
	Base64.decode64(s).to_i
end
def toString(n)
	#r='';while n>0 do r+=T[n%T.size];n/=T.size end;r.reverse
	Base64.encode64(n.to_s).chomp
end
d=toInt('Mjgw')-toInt('MTgw')
raise if d!=toInt('Mzgw')-toInt('Mjgw')
session=toString(toInt('Mzgw')+2*d)

uri=URI.parse('http://whitecafe.moe.hm/take50_sub/index.php')
Net::HTTP.start(uri.host){|http|
	resp=http.get(
		uri.path,
		{
			'Cookie'=>'PHPSESSID='+Digest::MD5.hexdigest(session),
		}
	)
	puts resp.body
}