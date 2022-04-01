#!/bin/bash

DIR=$1
SRC=$2

files=$(find ${DIR} -type f -name '*.c' | awk '{print "\t"$0"\\\\"}' | LC_ALL=C sort)
begin=$(awk '/^'${SRC}'.*=\\/{print NR}' Makefile)
end=$(awk '/^'${SRC}'.*=\\/,/^$/{print NR}' Makefile | sort -nr | head -n 1)

makefile=$(awk -v begin=$begin -v end=$end '!(NR > begin && NR < end) {print $0}' Makefile |
			awk -v src="${SRC}" -v files="${files}" '
			{
				sub("^"src"[\t ][\t ]*=\\\\$", src"\t=\\\n"files);
				print $0
			}')

echo -n "${makefile}" > Makefile