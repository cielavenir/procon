#!/usr/bin/env xcrun swift
import Darwin
var n=0
withUnsafePointer(&n){vscanf("%d",getVaList([COpaquePointer($0)]))}
while n>0 {
	var ma=0
	var mi=1000
	var sum=0
	var s=0
	for i in 0..<n {
		withUnsafePointer(&s){vscanf("%d",getVaList([COpaquePointer($0)]))}
		if ma<s {ma=s}
		if mi>s {mi=s}
		sum+=s
	}
	println((sum-ma-mi)/(n-2))
	withUnsafePointer(&n){vscanf("%d",getVaList([COpaquePointer($0)]))}
}