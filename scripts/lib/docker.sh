#!/bin/bash

DOCKER_IMAGE_NAME="roboducker"

source "${BASEDIR}/scripts/lib/polyfill.sh"
source "${BASEDIR}/scripts/lib/msg.sh"

function iAmInDocker {
  [ -f /.dockerenv ]
}

function handleDocker {
  local BASEDIR="$1"
  local USE_DOCKER=false
  shift
  if [ -f "${BASEDIR}/toolchain/docker" ] && ! iAmInDocker; then
    USE_DOCKER=true
  fi
  if ${USE_DOCKER}; then
    echo "================= ON DOCKER ================="
	if [ "$OS" = "Windows_NT" ]; then
		winpty docker run -it --net host --rm -u $UID:$GID -v "/${BASEDIR}://nao" --entrypoint //nao/scripts/`basename "$0"` "${DOCKER_IMAGE_NAME}" "$@"
	else
		docker run -it --net host --rm -u $UID:$GID -v "${BASEDIR}:/nao" --entrypoint /nao/scripts/`basename "$0"` "${DOCKER_IMAGE_NAME}" "$@"
	fi
  else
    run "$@"
  fi
}

function buildDocker {
  local BASEDIR="$1"
  shift
  UNAME=$(whoami)
  echo "Building Docker using $UID:$GID for user $UNAME"
  docker-compose --project-name "${DOCKER_IMAGE_NAME}" -f "${BASEDIR}/tools/docker/docker-compose.yml"  build  --build-arg USER_ID=$UID --build-arg GROUP_ID=$GID --build-arg USER_NAME=$UNAME   $@
  docker tag roboducker_roboducker roboducker
}

function enableDocker {
  local BASEDIR="$1"
  shift

  touch "${BASEDIR}/toolchain/docker"
}

function disableDocker {
  local BASEDIR="$1"
  shift

  rm "${BASEDIR}/toolchain/docker"
}

function execDockerCommand {
  local BASEDIR="$1"
  local ROOT="$2"
  shift
  shift

  if [[ $ROOT = "false" ]]; then
    usergroup="$UID:$GID"
  else
    usergroup="root:root"
  fi

  echo "================= ON DOCKER ================="
  echo " Docker> $@"
  if [[ "$OS" = "Windows_NT" ]]; then
		winpty docker run -it --net host --rm -u $usergroup -v "/${BASEDIR}://nao" "${DOCKER_IMAGE_NAME}" "$@"
	else
		docker run -it --net host --rm -u $usergroup -v "${BASEDIR}:/nao" "${DOCKER_IMAGE_NAME}" "$@"
	fi
}