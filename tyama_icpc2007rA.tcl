#!/usr/bin/tclsh
while 1 {
	set a [split [gets stdin] " "]
	set n [lindex $a 0]
	set k [lindex $a 1]
	set m [lindex $a 2]
	if {$n==0} {break}
	set r 0
	set i 1
	while {$i<$n} {
		set r [expr ( $r + $k ) % $i]
		set i [expr $i + 1]
	}
	puts [expr ( $r + $m ) % $n + 1]
}