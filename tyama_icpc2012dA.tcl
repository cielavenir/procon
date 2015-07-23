#!/usr/bin/tclsh
set t [gets stdin]
while {$t>0} {
	set a [split [gets stdin] " "]
	set y [expr [lindex $a 0] - 1]
	set m [expr [lindex $a 1] - 1]
	set d [lindex $a 2]
	set r 0
	if {[expr $y % 3]<2} {set r [expr $m / 2]}
	puts [expr 196471-$y*195-$y/3*5-$m*20+$r-$d]
	set t [expr $t - 1]
}