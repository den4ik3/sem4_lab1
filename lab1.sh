#!/bin/bash

if [ $# -gt 0 ]
then 
  # Цикл while
  echo "Цикл while:"
  count=$#
  while [ $count -gt 0 ]
  do
    echo "${!count}"
    count=$((count-1))
  done

  echo "----------------------"

  # Цикл for
  echo "Цикл for:"
  for ((count = $#; count > 0; count--))
  do
    echo "${!count}"
  done
else
	echo "No parametrs"
fi