FROM debian:buster

ARG USER_ID=1111
ARG GROUP_ID=1111
ARG USER_NAME=dagobert

RUN apt-get update && \
    apt-get install build-essential -y && \
    apt-get install cmake rsync ssh curl netcat sshpass -y && \
    echo "Install-Step finished"

RUN groupadd -g $GROUP_ID ducks
RUN useradd -d /nao --uid $USER_ID --gid $GROUP_ID $USER_NAME
USER $USER_NAME