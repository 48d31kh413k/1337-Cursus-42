#!/bin/sh
make all
make bonus
make clean
gcc -Wall -Wextra -Werror main.c libft.a
./a.out
make fclean
rm a.out
