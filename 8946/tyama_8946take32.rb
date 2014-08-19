#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
#prepare...
uri=URI.parse('http://www.hackerschool.jp/hack/take32.php')
str='PHPSESSID='
Mechanize::Cookie.parse(uri, str){|c|mech.cookie_jar.add(uri, c)}
#execute!
mech.get(uri)
form=mech.page.form_with(:action=>'./take32.php')
form['input_id']=mech.page.at('div#question').text.split(' x ').map(&:to_i).reduce(:*)
#form.add_field!('time_set',1)
form.submit
#puts mech.page.body