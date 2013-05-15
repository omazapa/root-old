#!/bin/bash

#ranks
PROCS="$1"
#executable
PROGRAM_TEST="$2"
#memcheck options
MEMCHECK_OPTS=" --leak-check=full --track-origins=yes --show-reachable=yes"
#callgrind options
 CALLGRIND_OPTS=" --dump-instr=yes --trace-jump=yes "
CALLGRIND_OPTS_OUTPUT=" --callgrind-out-file=$PROGRAM_TEST-$(date  '+%Y-%m-%d').%p.callgrind "
#MEMCHECK EXECUTION
mpirun -np $PROCS valgrind --tool=memcheck $MEMCHECK_OPTS ./$PROGRAM_TEST 2> $PROGRAM_TEST-$(date  '+%Y-%m-%d').memcheck

#CALLGRIND EXECUTION
mpirun -np $PROCS valgrind --tool=callgrind $CALLGRIND_OPTS $CALLGRIND_OPTS_OUTPUT ./$PROGRAM_TEST 

