#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'

puts "#!/usr/bin/env clj" if CLOJURE_STANDALONE && SCRIPTING
puts "(ns Solution (:gen-class))" if !CLOJURE_STANDALONE
puts "(use '[clojure.java.shell :only [sh]])"
puts "(defn -main [& args]" if !CLOJURE_STANDALONE

print "(println (:out (sh \"#{COMMAND}\" \"-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','\"').gsub("'",'\"')
	end
}
puts "\" :in *in*)))"

# http://dev.clojure.org/jira/browse/CLJ-959
print "(shutdown-agents)"
#print "(System/exit 0)"

print ")" if !CLOJURE_STANDALONE