#!/usr/bin/ruby
require 'zlib'
require 'base64'
$stderr.puts Base64.encode64(Zlib.deflate($<.read))