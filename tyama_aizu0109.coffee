#!/usr/bin/coffee
stdin = process.openStdin()
stdin.setEncoding 'utf8'
a=[]

proc = (s) ->
	bidx=s.indexOf('(')
	while bidx!=-1
		count=1;eidx=bidx+1
		while count>0
			if s[eidx]=='('
				count++
			if s[eidx]==')'
				count--
			eidx++
		s=s.substring(0,bidx)+proc(s.substring(bidx+1,eidx-1))+s.substring(eidx);
		bidx=s.indexOf('(')
	while (m=/^(.*?)(-?\d+)([*/])(-?\d+)(.*)$/.exec(s))?
		if m[3]=='*'
			s=m[1]+(parseInt(m[2])*parseInt(m[4]))+m[5]
		else
			s=m[1]+(parseInt(m[2])/parseInt(m[4])^0)+m[5]
	while (m=/^(.*?)(-?\d+)([+Z])(-?\d+)(.*)$/.exec(s))?
		if m[3]=='+'
			s=m[1]+(parseInt(m[2])+parseInt(m[4]))+m[5]
		else
			s=m[1]+(parseInt(m[2])-parseInt(m[4]))+m[5]
	return s

stdin.on 'data', (input) ->
	x=(e for e in input.split("\n"))
	if x.length>2 || !isNaN(x[1]) then a=x else a.push(x[0]) # x might be [num,'']

stdin.on 'end', (z) ->
	n=parseInt(a[0])
	for i in [1..n]
		s=a[i].substring(0,a[i].indexOf('=')).replace(/-/g,'Z')
		console.log(proc(s))