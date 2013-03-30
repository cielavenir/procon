#!/usr/bin/ruby
#coding:utf-8
raise 'Ruby 1.9+ is required' if RUBY_VERSION<'1.9'
require 'digest/md5'
puts [*'あ'..'ん'].repeated_permutation(4).find{|e|Digest::MD5.hexdigest(e.join)=='239363c3075ba1b350aaf62c7e15b574'}*''