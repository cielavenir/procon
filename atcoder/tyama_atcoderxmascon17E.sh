#!/bin/bash
read s;<<<$s grep -E ^$(sed -E '-es/\n?/A*/g' '-es/B/B?/g')\$|wc|tr -d ' '|sed -E '-es/^0+$/NO/' '-es/^[0-9]+$/YES/'
