#!/usr/bin/ruby
puts "#!/usr/bin/python"
puts "import os"
print "os.system(\"ruby -e '"
$<.each{|e|print e.strip.gsub("'",'\"')+';' if !e.strip.start_with?('#')}
puts "'\")"