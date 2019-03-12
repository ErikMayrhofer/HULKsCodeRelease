#!/usr/bin/env bash
function findnao
{
ping -q -c 1 -w 3 "$1" > /dev/null
return $?
}