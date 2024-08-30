#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <path to file to exclude, starting from \$ZIGBEE_ROOT <platform>"
    exit 1
fi

if [ "$2" = "k32w0" ]; then
   exclude="build_dk6_mcux"
elif [ "$2" = "k32w1" ]; then
   exclude="build_k32w1_mcux"
else
    echo "Platform must be k32w0 or k32w1"
    exit 2
fi
echo "Changing FILE ${1}"

#file=$(echo "${1}" | sed -r 's/\//\\\//g')

#files=$(find verfication -type f -name .cproject)
files=$(find examples -type f -name .cproject -not -path *${exclude}*)
for i in $files; do
    echo $i

	sed -i "s@<entry excluding=\"@<entry excluding=\"$1|@" $i
done
