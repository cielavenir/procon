#!/usr/bin/ruby
#cf: atcoder cf16-final B
n=gets.to_i;s=i=0;s+=i+=1while s<n;r=[*1..i]-[s-n];p r.size;puts r*' '
__END__
(1..i).map{|e|e!=s-n&&r<<e}
