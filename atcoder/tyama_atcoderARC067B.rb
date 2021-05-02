#!/usr/bin/ruby
r=[x=0];gets;gets.chars{|c|r<<x+=c==?I?1:-1};p r.max
__END__
r=[x=0];`dd`.chars{|c|r<<x+=c==?I?1:c==?D?-1:0};p r.max
