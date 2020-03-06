#!/bin/bash
make > /dev/null
clang -Werror -Wall -Wextra tests/main_1.c libftprintf.a -o tests/test_sys_ptf
./tests/test_sys_ptf > tests/printf_out
clang -Werror -Wall -Wextra tests/main_2.c gnl/get_next_line.c libftprintf.a -o tests/test_my_ptf
./tests/test_my_ptf > tests/printf_ft_out
diff tests/printf_out tests/printf_ft_out > tests/errors.diff
#if [[ -s tests/errors.diff ]]
if [[ -z $(grep '[^\n]' tests/errors.diff) ]]
		then echo "No errors. Congrats!"
else
		bat tests/errors.diff
fi
