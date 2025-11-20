coverage:
	@gcc -std=c17 -Wall -Wextra --coverage tests.c problem_hwf.c problem_sf.c problem_fm.c problem_pp.c problem_rps.c problem_mf.c -lcheck -lm -lpthread -o tests_cov
	@./tests_cov
	@lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch,unsupported
	@lcov --remove coverage.info '/usr/*' '*/tests.c' '*/test_*' --output-file coverage.info --ignore-errors unused
	@genhtml coverage.info --output-directory cov_report
	@open cov_report/index.html
	@rm -f tests_cov *.gcda *.gcno coverage.info

manual:
	@gcc -std=c17 -Wall -Wextra -DTEST_MODE problem_hwf.c -o manual
	-@./manual
	@make clean

tests:
	@gcc -std=c17 -Wall -Wextra tests.c problem_hwf.c problem_sf.c problem_fm.c problem_pp.c problem_rps.c problem_mf.c -lcheck -lm -lpthread -o tests
	-@./tests
	@make clean

clean:
	@rm -rf tests manual cov_report