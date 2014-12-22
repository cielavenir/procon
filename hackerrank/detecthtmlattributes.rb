#!/usr/bin/ruby
h={}
$<.read.scan(/\<(.+?)\>/).each{|e|
	tag=e[0].split[0]
	next if tag[0,1]=='/'
	h[tag]={} if !h.has_key?(tag)
	e[0].scan(/([^\s]+?)=['"](?:.*?)["']/).each{|f|
		h[tag][f[0]]=1
	}
}
h.keys.sort.each{|e|
	puts [e,h[e].keys.sort*',']*':'
}