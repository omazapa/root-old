#!/bin/bash

R -e "remove.packages('ROOT')" &> /dev/null
R CMD build ROOT
R -e "install.packages('ROOT_1.0.tar.gz')"
rm ROOT_1.0.tar.gz ROOT.Rcheck/ -rf
