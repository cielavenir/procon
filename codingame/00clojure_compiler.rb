#!/usr/bin/ruby
STANDALONE=false

puts "(ns Solution (:gen-class))" if !STANDALONE
puts "(use '[clojure.java.shell :only [sh]])"
puts "(defn -main [& args]" if !STANDALONE

print "(println (:out (sh \"ruby\" \"-e\" \""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\" :in *in*)))"

# http://dev.clojure.org/jira/browse/CLJ-959
puts "(shutdown-agents)"
#puts "(System/exit 0)"

puts ")" if !STANDALONE