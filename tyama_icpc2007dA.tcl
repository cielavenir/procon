#!/usr/bin/tclsh
set n [gets stdin]
while {$n!=0} {
  set ma 0; set mi 1000; set sum 0; set i 0
  while {$i!=$n} {
    set s [gets stdin]
    if {$ma<$s} {set ma $s}
    if {$mi>$s} {set mi $s}
    set sum [expr $sum + $s]
    incr i
  }
  set sum [expr $sum - $ma - $mi]
  set n [expr $n - 2]
  puts [expr $sum / $n]
  set n [gets stdin]
}