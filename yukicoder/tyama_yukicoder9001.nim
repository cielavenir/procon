#!/usr/bin/env nim
import strutils
var AB=readLine(stdin).split()
var n=parseInt(AB[0])+parseInt(AB[1])
echo($n&" "&readLine(stdin))