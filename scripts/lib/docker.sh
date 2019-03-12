#!/bin/bash

DOCKER_IMAGE_NAME="roboducker"

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
	if [ $OS = "Windows_NT" ]; then
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
  docker build -t "${DOCKER_IMAGE_NAME}" "${BASEDIR}/tools/docker/"
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