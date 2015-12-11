#!/usr/bin/env xcrun swift
import CoreFoundation
var t=0,y=0,m=0,d=0
withUnsafeMutablePointer(&t){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
for i in 0..<t {
	withUnsafeMutablePointer(&y){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	withUnsafeMutablePointer(&m){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	withUnsafeMutablePointer(&d){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	y--
	m--
	print(196471-y*195-y/3*5-m*20+(y%3-2>0 ? m/2 : 0)-d)
}