#!/bin/bash

R -e "remove.packages('ROOTR')" &> /dev/null
R CMD build ROOTR
R -e "install.packages('ROOTR_1.0.tar.gz')"
rm ROOTR_1.0.tar.gz ROOTR.Rcheck/ -rf
