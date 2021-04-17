#!/usr/bin/ruby
require 'base64'
require 'zlib'
require 'stringio'
img = StringIO.new Zlib.inflate Base64.decode64 DATA.read
sig = img.gets.chomp
width, height = img.gets.split.map &:to_i
depth = img.gets.to_i
if false
img = img.read.bytes.each_slice(3).map{|r,g,b|r+g+b}
raise if sig!='P6'
gets.to_i.times{
y,x=gets.split.map &:to_i
p img[y*width+x]
}
elsif false
img = img.read.bytes.each_slice(3).map{|r,g,b|(r+g+b)/3/32*32}
STDOUT.puts 'P5'
STDOUT.puts '%d %d'%[width,height]
STDOUT.puts '%d'%depth
STDOUT.write img.pack 'C*'
else
img = img.read.bytes.each_slice(3).map{|r,g,b|(r+g+b)/3/32}
img << 0 if img.size%2>0
img = img.each_slice(2).map{|x,y|x<<4|y}
STDOUT.write img.pack 'C*'
end

# icon.ppm_p6.zlib.b64
__END__
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
WVuDR2z9R/HZwL/4HP8CpJ1oww==
