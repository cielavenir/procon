#!/bin/sh
read A B;ruby "-ep $[A+B].gcd $A*$B"
