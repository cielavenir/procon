#!/usr/bin/ruby
s=$<.read;puts [:Friendship,:Anton,:Danik][s.count(?A)<=>s.count(?D)]
