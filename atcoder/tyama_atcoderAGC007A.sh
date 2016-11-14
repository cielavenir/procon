#!/bin/sh
read H W;ruby "-eprint'`dd`'.count(?#)==$H+$W-1?:P: :Imp,:ossible"
