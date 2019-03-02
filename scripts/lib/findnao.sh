#!/usr/bin/env bash
function findnao
{
ping -c 1 $1 ;
return $?
}