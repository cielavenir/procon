#!/bin/sh
ruby -e 'print gets.split.map(&:to_i).reduce(:+)," ",gets'