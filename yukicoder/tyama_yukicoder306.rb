#!/usr/bin/ruby
X,Y,Z,W=$<.read.split.map &:to_f;p W-Z*(W-Y)/(Z+X)