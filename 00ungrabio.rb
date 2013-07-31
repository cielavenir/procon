#!/usr/bin/ruby
require 'zlib'
require 'base64'
$stderr.puts Zlib.inflate(Base64.decode64($<.read))