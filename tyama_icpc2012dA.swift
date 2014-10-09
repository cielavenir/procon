#!/usr/bin/env xcrun swift
import Darwin
var t=0,y=0,m=0,d=0
withUnsafePointer(&t){vscanf("%d",getVaList([COpaquePointer($0)]))}
for i in 0..<t {
	withUnsafePointer(&y){vscanf("%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&m){vscanf("%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&d){vscanf("%d",getVaList([COpaquePointer($0)]))}
	y--
	m--
	var r=y%3-2>0 ? m/2 : 0
	//wtf is "expression was too complex to be solved in reasonable time"?
	var a=y/3*5
	var b=m*20
	var x=a+b+d
	println(196471-y*195+r-x)
}