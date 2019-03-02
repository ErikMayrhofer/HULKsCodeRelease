#!/usr/bin/env bash
function findnao
{
ping -c 1 -w 3 $1
return $?
}