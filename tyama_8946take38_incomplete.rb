#!/usr/bin/ruby
require 'json'
require 'mechanize'
mech=Mechanize.new
#prepare...
uri=URI.parse('http://www.hackerschool.jp/hack/ajax_take38.php')
mech.post(uri,{'inc_file_path'=>"take38_answer.php"})#,'timestamp'=>'1365418014'})
p JSON.parse(mech.page.body)