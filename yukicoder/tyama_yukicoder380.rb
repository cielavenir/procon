#!/usr/bin/ruby
f={
'_digi'=>->s{s=~/nyo\W{0,3}$/},
'_petit'=>->s{s=~/nyu\W{0,3}$/},
'_rabi'=>->s{s=~/\w/},
'_gema'=>->s{s=~/gema\W{0,3}$/},
'_piyo'=>->s{s=~/pyo\W{0,3}$/},
}
f.default=->s{nil}
$<.each{|e|
a=('_'+e.chomp.tr('_','#')).split(' ',2)
puts f[a[0]][(a[1]||'').downcase] ? 'CORRECT (maybe)' : 'WRONG!'
}