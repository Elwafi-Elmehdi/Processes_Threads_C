#!/usr/bin/env bash

if [ $# -ne 2 ]; then
	echo "Invalid args"
fi

name=$1
reason=$2

cat <<-EOF > ./$name.c
// REASON : `echo $reason`
// AUTHOR : `echo $USER`
// CREATED DATE : $(date +"%F %T")

#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
EOF
