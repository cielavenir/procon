#!/usr/bin/clj
(ns Player
	(:gen-class))

(defn -main [& args]
	(while true
		(let [enemy1 (read) dist1 (read) enemy2 (read) dist2 (read)]
		; enemy1: name of enemy 1
		; dist1: distance to enemy 1
		; enemy2: name of enemy 2
		; dist2: distance to enemy 2
		(println (if (< dist1 dist2) enemy1 enemy2)))))