#!/usr/bin/env bash

BASEDIR=`cd $(dirname $0); pwd -P`

DUCKLIBPATH="${BASEDIR}/lib"

cd ${BASEDIR}
cd bin

echo "==================STARTING DUCKBURG==============="
LD_LIBRARY_PATH=${DUCKLIBPATH} ./launcher
EXIT=$?
echo "==================DUCKBURG EXITED==============="
echo "Summary: "
echo "  - Return Code: ${EXIT}"
