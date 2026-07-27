#!/usr/bin/ruby
require 'base64'
require 'zlib'
require 'stringio'
img = StringIO.new Zlib.inflate Base64.decode64 DATA.read
sig = img.gets.chomp
width, height = img.gets.split.map &:to_i
depth = img.gets.to_i
img = img.read.bytes

raise if sig!='P5'
gets.to_i.times{
y,x=gets.split.map &:to_i
p img[y*width+x]*3
}

# icon.ppm_p5.zlib.b64
__END__
eNoKMOUyNDBUsLDkMjI15XowCgDs2dFtwzAMRVGOwlE0ikbxKBqFo7Ux2oeq8YtxAekjQPQbBMe+
MWXXffM1eh61VaijRbaIPjYSGdkeK6KN2tMpomllrK9W49FpXqwa6DSvXFJNnWZieTV1sgyqBjot
rFa2E6gGLtn7RatptNEC1cBPwauBTqAaGG3KqNraTqBa8U602rg/CXg6g7eiRB98OhjRjlp7/YKr
ePSiO5bblOt3/64nRAcw/zi8k+YtLpC/KUcLXu3/YV4iugPpfgivp5q/ahDtCrSaImhfsoiOaf4C
7tTuEVDNdLpBtHKuBjoB5L6a6wSQc83V/I6ujznirzV18jseQVw13wkjpprvxBHTxndiSObLar4T
QLL3CF/NdyJIHOdh+mq+E0Jsjejfn3V/Egwxx5snkssQ/QW0GRGzHsle8/NLbkBazs+y1XMDotHT
Z8sRjV7pVBYifl/ch4jZiOhWvxcRc+Q+RMz6OfHrg3yQD/KuyHhGYjESUZevVhYiureCNzgMSRGA
AYhuQq+WHhsBwgg9zxGEE2IIwgkxGMnog79FR0hgQi9XPeKfBTljEEBQRogbbr40nwYBBGGEAIIw
eYEkIMA/bYSgyWPzKYQQnPlBGIG3gRNhw82Z43E7GF97MPTBKAAACqPCcQ==
