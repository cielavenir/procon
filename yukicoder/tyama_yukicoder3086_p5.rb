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
eNrt2cFNAzEQhWGfU8WUQJAiwc0lUIJLcSkuZUpJKSQr4LE8HMuemUOknQMHQvRt/qy9G/JxOZ1f
zvL2fnq9XE7XY558WpGq18jRmpPklErD79wJuRH3SSm3kJfTSkr5ZyT5V9N277QbVPPsxCOo5tCJ
COdq1IkYVHPr5F1NuZNjNT5lx4Nqk0ubZlzN9FZ4V+NOztWwtA0Mqhk6maopdXKv1uhFWF9Oi2oF
orTB6jATuarh/LWdxa3o3I7V35T1e/9WQnAAeHOWO23rLSkjv1O2vFDt72H+h+AKhOvh3Pmku6f2
EOwKqDbVCftSD8Ex0RPmOuUxwtUmOw0QjFC1iU5jZKIadxojNPtqvR0dD68gfK5xJ+x4ywhX63Uy
IVyt08mCcBvqtIiIPKpGnZYQKYjA1ajTGpLqdpidauhkRPo1Urk9VvC3JqR3vLIh4oPgE1AoAiYE
kaL7+xcJQLLs72W1iDuCpYfHnBEsPUTTAIT3xRgETCiCS30oAqZKGAImYp3wHMiBHMhzI42R5Iwk
fiW4n/NBcG1lRlwQIYIYA4KL0MOpmRlGDATu5xYREAYGiI0AM0SYKM38X3RG7N/ZKDGE8L2gnQFi
JphhhBa3/fssRtwIZoA4E9htGBE/Ah9SgcytvLn1CQREAPOFhBDYBjaEFrczU28/arse8/zzCQqj
wnE=
