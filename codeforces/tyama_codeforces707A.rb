#!/usr/bin/ruby
s=$<.read
puts s==s.tr('CMY','') ? '#Black&White' : '#Color'