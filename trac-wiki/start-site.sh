#!/bin/bash

INSTANCE="8001"
VERSION="0.0.1"
ENV="YangVillageWeb2"
PIDFILE="${HOME}/YangVillageWeb2/tracd"
ARGS="--basic-auth=${ENV},htpasswd,qzlzdy -s ."
#ARGS="-s ${ENV}"

function start(){
    tracd -d -p ${INSTANCE} --pidfile=${PIDFILE}.${INSTANCE} --protocol=http ${ARGS}
}

function stop(){
    kill `cat ${PIDFILE}.${INSTANCE}`
}

$1

