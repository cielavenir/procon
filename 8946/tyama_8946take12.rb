#!/usr/bin/ruby
require 'net/http'
puts Net::HTTP.get(URI.parse('http://www.hackerschool.jp/hack/svn/.svn/text-base/index.php.svn-base'))