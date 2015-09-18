#!/usr/bin/env xcrun swift
import Darwin
var n=0,k=0,m=0,r=0,i=0
withUnsafePointer(&n){vscanf("%d",getVaList([COpaquePointer($0)]))}
while n>0 {
	withUnsafePointer(&k){vscanf("%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&m){vscanf("%d",getVaList([COpaquePointer($0)]))}
	r=0
	for i=0;++i<n;r%=i {r+=k}
	print((r+m)%n+1)
	withUnsafePointer(&n){vscanf("%d",getVaList([COpaquePointer($0)]))}
}