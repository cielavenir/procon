#!/usr/bin/tclsh
set n [gets stdin]
set r 1
while {$n!=0} {
  set r [expr $n * $r]
  set n [expr $n - 1]
}
puts $r