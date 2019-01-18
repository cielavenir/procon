#!/usr/bin/ruby
s=gets
begin
idx=s.index('[')
s=s[idx+1..-1]
idx=s.index(':')
s=s[idx+1..-1]
idx=s.rindex(']')
s=s[0...idx]
idx=s.rindex(':')
s=s[0...idx]
p s.count('|')+4
rescue
p -1
end
__END__
p gets=~/\[.*?\:(.*)\:.*?\]/ ? $1.count(?|)+4 : -1
