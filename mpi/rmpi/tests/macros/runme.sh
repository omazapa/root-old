#!/bin/bash
#script to run automatic test
PROCS=4
echo "RUNNING AllGatherObject.C"
rootmpi -l -q -np $PROCS AllGatherObject.C
 echo "FINISHED AllGatherObject.C"
echo "RUNNING BcastObject.C"
rootmpi -l -q -np $PROCS BcastObject.C
 echo "FINISHED BcastObject.C"
echo "RUNNING Constants.C"
rootmpi -l -q -np $PROCS Constants.C
 echo "FINISHED Constants.C"
echo "RUNNING Datatype.C"
rootmpi -l -q -np $PROCS Datatype.C
 echo "FINISHED Datatype.C"
echo "RUNNING GatherObject.C"
rootmpi -l -q -np $PROCS GatherObject.C
 echo "FINISHED GatherObject.C"
echo "RUNNING ISendRecvObject.C"
rootmpi -l -q -np $PROCS ISendRecvObject.C
 echo "FINISHED ISendRecvObject.C"
echo "RUNNING ScatterObject.C"
rootmpi -l -q -np $PROCS ScatterObject.C
 echo "FINISHED ScatterObject.C"
echo "RUNNING SendRecvObject.C"
rootmpi -l -q -np $PROCS SendRecvObject.C
 echo "FINISHED SendRecvObject.C"
echo "RUNNING SendRecvObjectExtreme.C"
rootmpi -l -q -np $PROCS SendRecvObjectExtreme.C
 echo "FINISHED SendRecvObjectExtreme.C"
