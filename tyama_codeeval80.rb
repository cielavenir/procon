#!/usr/bin/ruby
require 'cgi'
while gets
a,b=$_.chomp.split(';').map{|e|CGI.unescape(e)+'/'}
a=~/^(.*?):\/\/(.*?)\/(.*)$/
c=[$1,$2,$3]
b=~/^(.*?):\/\/(.*?)\/(.*)$/
d=[$1,$2,$3]
if !c[1].index(':') then c[1]+=':80' end
if !d[1].index(':') then d[1]+=':80' end
if c[1].index(':')==c[1].size-1 then c[1]+='80' end
if d[1].index(':')==d[1].size-1 then d[1]+='80' end
puts c[0].casecmp(d[0])==0 && c[1].casecmp(d[1])==0 && c[2]==d[2] ?'True':'False'
end