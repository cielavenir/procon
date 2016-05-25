#!/usr/bin/ruby
X,Y,Z,W=`dd`.split.map &:to_f;p W-Z*(W-Y)/(Z+X)