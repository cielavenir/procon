#!/usr/bin/ruby
a,b,c=`dd`.split;puts (c=c.size)<a&&b<c ? :NO: :YES
