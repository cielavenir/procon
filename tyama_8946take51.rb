#!/usr/bin/ruby
require 'net/http'
require 'uri'
uri=URI.parse('http://www.hackerschool.jp/hack/51/index.php')
DATA.each{|l|
	proxy=URI.parse('http://'+l.chomp)
	puts proxy.host+':'+proxy.port.to_s
	begin
		Net::HTTP::Proxy(proxy.host,proxy.port).start(uri.host){|http|
			resp=http.get(uri.path)
			puts resp.body
			#exit
		}
	rescue; end
}
#From http://www.cybersyndrome.net/search.cgi?q=FR
__END__
195.154.95.82:8080
atreactor.com:3128
ks201232.kimsufi.com:3128
ks201232.kimsufi.com:7808
ks201232.kimsufi.com:8089
ks3098921.kimsufi.com:3128
ks356009.kimsufi.com:443
maintenance-gw1.duretelec.fr:80
r19794.ovh.net:8080
vps1.progamela.net:3128