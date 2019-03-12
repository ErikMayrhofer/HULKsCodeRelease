#!/bin/bash

function naocmd {
  if [ "$#" -ne 3 ]; then
    return 1
  fi
  local BASEDIR="$1"
  local NAME="$2"
  local COMMAND="$3"
  TARGET_PORT=""
  if [[ $NAME="localhost" ]]; then
    TARGET_PORT="-p 2222"
  fi
  ssh $TARGET_PORT -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -o ConnectTimeout=5 -l nao -i "${BASEDIR}/scripts/ssh_key" -t "${NAME}" "${COMMAND}"
}

function naossh {
  if [ "$#" -ne 2 ]; then
    return 1
  fi
  local BASEDIR="$1"
  local NAME="$2"
  TARGET_PORT=""
  if [[ $RSYNC_TARGET="localhost" ]]; then
    TARGET_PORT="-p 2222"
  fi
  ssh $TARGET_PORT -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -l nao -i "${BASEDIR}/scripts/ssh_key" "${NAME}"
}

function naocp {
  if [ "$#" -lt 3 ]; then
    return 1
  fi
  local BASEDIR="$1"
  # take all arguments from second to penultimate one as source
  local SRC=${@:2:$(expr $# - 2)}
  # take last argument as destination
  local DST=${@:$#}
  TARGET=$(echo "$DST" | cut -d: -f1)
  IP=$(echo "$DST" | cut -d@ -f2)
  echo "$IP"
  if [[ IP="localhost" ]]; then
    TARGET_PORT="-P 2222"
  fi
  scp $TARGET_PORT -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -r ${SRC} "${DST}"
}

function naocmdpass {
  if [ "$#" -ne 2 ]; then
    return 1
  fi
  local NAME="$1"
  local COMMAND="$2"
  TARGET=$(echo "$DST" | cut -d: -f1)
  if [[ TARGET="localhost" ]]; then
    TARGET_PORT="-p 2222"
  fi
  sshpass -p nao ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet $TARGET_PORT -l nao -t "${NAME}" "${COMMAND}"
}

function naocppass {
  if [ "$#" -ne 2 ]; then
    return 1
  fi
  local SRC="$1"
  local DST="$2"
  TARGET=$(echo "$DST" | cut -d: -f1)
  if [[ TARGET="localhost" ]]; then
    TARGET_PORT="-p 2222"
  fi
  sshpass -p nao scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -r $TARGET_PORT "${SRC}" "${DST}"
}
