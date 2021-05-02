#!/bin/sh
read A B C;ruby "-ep $A+$B+$C-[$A,$B,$C].max"
