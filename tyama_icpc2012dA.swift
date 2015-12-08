#!/usr/bin/env xcrun swift
import CoreFoundation
var t=0,y=0,m=0,d=0
withUnsafePointer(&t){vscanf("%d",getVaList([COpaquePointer($0)]))}
for i in 0..<t {
	withUnsafePointer(&y){vscanf("%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&m){vscanf("%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&d){vscanf("%d",getVaList([COpaquePointer($0)]))}
	y--
	m--
	print(196471-y*195-y/3*5-m*20+(y%3-2>0 ? m/2 : 0)-d)
}