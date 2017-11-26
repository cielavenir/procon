#!/usr/bin/ruby
r=([*?a..?z]*2).each
q=->n{n<3??z*n:(s=q[n/2];x=n%2<1?'':r.next;x+s[0]+s+s[0]+x)}
$><<q[gets.to_i]
