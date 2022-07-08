#!/bin/bash

cd $1
clang++ -Wall -Wextra -Werror -W -std=c++98 *.cpp
./a.out | cat -e
rm a.out
