#!/bin/sh
read x y;ruby "-ep ($y/$x).bit_length"
