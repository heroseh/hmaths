#!/bin/sh
mkdir -p build
clang -o build/generator tools/generator.c
if test $? -ne 0; then
	exit
fi
./build/generator
