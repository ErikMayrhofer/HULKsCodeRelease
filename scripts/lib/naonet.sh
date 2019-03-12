#!/bin/bash

function naocmd {
  if [ "$#" -ne 4 ]; then
    return 1
  fi
  local BASEDIR="$1"
  local NAME="$2"
  TARGET_PORT="$3"
  local COMMAND="$4"
  ssh -p $TARGET_PORT -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -o ConnectTimeout=5 -l nao -i "${BASEDIR}/scripts/ssh_key" -t "${NAME}" "${COMMAND}"
}

function naossh {
  if [ "$#" -ne 4 ]; then
    return 1
  fi
  local BASEDIR="$1"
  local NAME="$2"
  TARGET_PORT="$3"
  ssh -p $TARGET_PORT -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -l nao -i "${BASEDIR}/scripts/ssh_key" "${NAME}"
}

#TODO This may exist elsewhere, check that
function copysshkey {
  if [[ "$#" -ne 3 ]]; then
    return 1
  fi
  local BASEDIR="$1"
  local NAME="$2"
  TARGET_PORT="$3"

  cat "${BASEDIR}/scripts/files/ssh_key.pub" | ssh -l nao -p ${TARGET_PORT} "${NAME}" "test -d ~/.ssh || mkdir ~/.ssh; cat >> ~/.ssh/authorized_keys"
}

function naocp {
  if [ "$#" -lt 4 ]; then
    return 1
  fi
  local BASEDIR="$1"
  TARGET_PORT="$2"
  # take all arguments from second to penultimate one as source
  local SRC=${@:3:$(expr $# - 3)}
  # take last argument as destination
  local DST=${@:$#}
  echo $TARGET_PORT
  echo $SRC
  echo $DST
  scp -P $TARGET_PORT -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -r ${SRC} "${DST}"
}

function naocmdpass {
  if [ "$#" -ne 3 ]; then
    return 1
  fi
  local NAME="$1"
  local TARGET_PORT="$2"
  local COMMAND="$3"
  sshpass -p nao ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -p $TARGET_PORT -l nao -t "${NAME}" "${COMMAND}"
}

function naocppass {
  if [ "$#" -ne 3 ]; then
    return 1
  fi
  local SRC="$1"
  local TARGET_PORT="$2"
  local DST="$3"
  sshpass -p nao scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -o LogLevel=quiet -r -p $TARGET_PORT "${SRC}" "${DST}"
}
