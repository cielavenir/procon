#!/usr/bin/ruby
require 'exifr'
exif=EXIFR::JPEG.new(ARGV[0])
puts "model: #{exif.model}"
puts "place: https://maps.google.com/maps?q=#{exif.gps.latitude},#{exif.gps.longitude}" # => Wien