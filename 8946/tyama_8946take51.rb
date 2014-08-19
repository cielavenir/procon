#!/usr/bin/ruby
require 'net/http'
require 'uri'
uri=URI.parse('http://www.hackerschool.jp/hack/51/index.php')
DATA.each{|e|
	puts 'Trying '+e
	_e=e.split(':')
	begin
		Net::HTTP::Proxy(_e[0],_e[1].to_i).start(uri.host){|http|
			resp=http.get(uri.path)
			puts resp.body
			#exit
		}
	rescue; end
}
#From http://www.cybersyndrome.net/search.cgi?q=FR
__END__
46-105-42-93.kimsufi.com:3128
94.247.25.163:80
athene.ssh.onlysavvy.com:3128
ks363647.kimsufi.com:3128
ks363886.kimsufi.com:3128
ks36571.kimsufi.com:3128
mail.deltacity.org:3128
maintenance-gw1.duretelec.fr:80
sds-23.hosteur.com:3128