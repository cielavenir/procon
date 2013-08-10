#!/usr/bin/ruby
require 'zipruby'

ARCH='take40.zip'

def try(arc,password)
	puts 'trying '+password.inspect
	begin
		Zip::Archive.decrypt(arc,password)
	rescue
		return false
	end
	puts 'ok!'
	exit
end

try(ARCH,'6c626d41a33f')
try(ARCH,'6c:62:6d:41:a3:3f')
try(ARCH,'192.168.0.12')
try(ARCH,'192.168.1.3')
A='00:00:00:6b:30:15:9d:bd:4b:ed:55:0f:16:21:31:ae:3f:1e:ed'
try(ARCH,A)
B='00:00:00:f5:51:b7:05:be:71:52:9a:f6:ac:a0:98:a3:d6:db:b5'
try(ARCH,B)
A1=A[9..-1]
try(ARCH,A1)
B1=B[9..-1]
try(ARCH,B1)
try(ARCH,A1+':'+B1)
try(ARCH,B1+':'+A1)
try(ARCH,A1.tr(':',''))
try(ARCH,B1.tr(':',''))
try(ARCH,A1.tr(':','')+B1.tr(':',''))
try(ARCH,B1.tr(':','')+A1.tr(':',''))
try(ARCH,A1.split(':').map{|e|e.hex.chr})
try(ARCH,B1.split(':').map{|e|e.hex.chr})

a=A1.split(':').map(&:hex)
b=B1.split(':').map(&:hex)
try(ARCH,a.zip(b).map{|x,y|'%02x'%(x^y)}*'')