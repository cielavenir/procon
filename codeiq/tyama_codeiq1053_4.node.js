#!/usr/bin/env node

console.log(
// CODE_START
(function() {
  var text = "L71EQS78EVNX85HG95UJZ73VNW83UAG95UJS78EVYP79YJF84AG95UJNX85HS78EVZ73VNB88UQNZ46LP76XBZ73VNS78EVNX85HB88UQG95UJZ73VNW83UAG95UJS78EVYP79YJF84AG95UJNX85HS78EVZ73VNB88UQNZ46L";

  var answer = text.replace(
	/[^\d]/g,'').replace(/\d{2}/g
	,
	function(s){return String.fromCharCode(s)}
  );

  return answer;
})()
// CODE_END
);