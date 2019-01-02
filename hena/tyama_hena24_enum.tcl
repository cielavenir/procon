#!/usr/bin/env tclsh
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/

### tclsh >= 8.6 ###

proc isqrt {n} {
	if {$n<=0} {return 0}
	if {$n<4} {return 1}
	set x 0
	set y $n
	while {$x!=$y&&$x+1!=$y} {
		set x $y
		set y [expr ($n/$y+$y)/2]
	}
	return $x
}

proc icbrt {n} {
	if {$n<0} {return [icbrt -$n]}
	if {$n==0} {return 0}
	if {$n<8} {return 1}
	set x 0
	set y $n
	while {$x!=$y&&$x+1!=$y} {
		set x $y
		set y [expr ($n/$y/$y+$y*2)/3]
	}
	return $x
}

proc generate {g} {
	proc func {} {
		yield [info coroutine]
		set i 1
		while {true} {
			yield $i
			incr i
		}
	}
	coroutine $g func
}

proc drop_prev {g check prev} {
	proc func {check prev} {
		yield [info coroutine]
		set a [$prev]
		set b [$prev]
		while {true} {
			if {![$check $b]} {yield $a}
			set a $b
			set b [$prev]
		}
	}
	coroutine $g func $check $prev
}

proc drop_next {g check prev} {
	proc func {check prev} {
		yield [info coroutine]
		set a [$prev]
		set b [$prev]
		yield $a
		while {true} {
			if {![$check $a]} {yield $b}
			set a $b
			set b [$prev]
		}
	}
	coroutine $g func $check $prev
}

proc drop_n {g check n prev} {
	proc func {check n prev} {
		yield [info coroutine]
		set i 0
		while {true} {
			incr i
			set a [$prev]
			if {![$check $i $n]} {yield $a}
		}
	}
	coroutine $g func $check $n $prev
}

proc is_sq {n} {
	set x [isqrt $n]
	return [expr $x*$x==$n]
}

proc is_cb {n} {
	set x [icbrt $n]
	return [expr $x*$x*$x==$n]
}

proc is_multiple {i n} {return [expr $i%$n==0]}
proc is_le {i n} {return [expr $i<=$n]}

array set f {
	"S" {{g prev} {drop_next $g is_sq $prev}}
	"s" {{g prev} {drop_prev $g is_sq $prev}}
	"C" {{g prev} {drop_next $g is_cb $prev}}
	"c" {{g prev} {drop_prev $g is_cb $prev}}
	"h" {{g prev} {drop_n $g is_le 100 $prev}}
	"2" {{g prev} {drop_n $g is_multiple 2 $prev}}
	"3" {{g prev} {drop_n $g is_multiple 3 $prev}}
	"4" {{g prev} {drop_n $g is_multiple 4 $prev}}
	"5" {{g prev} {drop_n $g is_multiple 5 $prev}}
	"6" {{g prev} {drop_n $g is_multiple 6 $prev}}
	"7" {{g prev} {drop_n $g is_multiple 7 $prev}}
	"8" {{g prev} {drop_n $g is_multiple 8 $prev}}
	"9" {{g prev} {drop_n $g is_multiple 9 $prev}}
}
#2..9: Tcl does not have capturing.

set s [gets stdin]
while {$s!=""} {
	set lst [list hena24]
	generate [lindex $lst 0]
	for {set i 0} {$i < [string length $s]} {incr i} {
		set x [string index $s $i]
		lappend lst [lindex $lst $i]$x
		apply $f($x) [lindex $lst [expr $i+1]] [lindex $lst $i]
	}
	for {set j 0} {$j < 10} {incr j} {
		if {$j>0} {
			puts -nonewline ","
		}
		puts -nonewline [[lindex $lst $i]]
	}
	puts ""
	flush stdout
	set s [gets stdin]
}
