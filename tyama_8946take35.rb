#!/usr/bin/ruby
require 'mechanize'
mech=Mechanize.new
mech.user_agent='DoCoMo/2.0 F900i(c100;TB;W22H12;ser365079045783623;iccxxxxxxxxxxxxxxxxxxxx)'
mech.post('http://www.hackerschool.jp/hack/take35_mobile/',{'mode'=>'chk'})
puts mech.page.body