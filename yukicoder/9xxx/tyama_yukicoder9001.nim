#[
/usr/bin/env nim c --nimcache:$HOME/.nimcache --opt:speed --run $0 $@;exit
#]#
import strutils
var AB=readLine(stdin).split()
var n=parseInt(AB[0])+parseInt(AB[1])
echo($n&" "&readLine(stdin))
