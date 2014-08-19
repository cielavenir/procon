#!/usr/bin/ruby
require 'mechanize'
require 'json'
mech=Mechanize.new
mech.post('http://prosite.expasy.org/cgi-bin/prosite/PSScan.cgi',{'seq'=>gets.chomp,'output'=>'json'})
puts JSON.parse(mech.page.body)['matchset'].max_by{|e|e['start'].to_i}['signature_ac']