manual:
	@gcc -std=c17 -Wall -Wextra -DTEST_MODE problem_hwf.c -o manual
	-@./manual
	@make clean

tests:
	@gcc -std=c17 -Wall -Wextra tests.c problem_hwf.c problem_sf.c problem_fm.c problem_pp.c problem_rps.c problem_mf.c -lcheck -lm -lpthread -o tests
	-@./tests
	@make clean

clean:
	@rm -rf tests manual