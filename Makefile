problem_sf:
	@gcc -std=c17 -Wall -Wextra test_problem_sf.c problem_sf.c -lcheck -lm -lpthread -o test_problem_sf
	@./test_problem_sf
	@make clean

problem_pp:
	@gcc -std=c17 -Wall -Wextra test_problem_pp.c problem_pp.c -lcheck -lm -lpthread -o test_problem_pp
	@./test_problem_pp
	@make clean

problem_mf:
	@gcc -std=c17 -Wall -Wextra test_problem_mf.c problem_mf.c -lcheck -lm -lpthread -o test_problem_mf
	@./test_problem_mf
	@make clean

clean:
	@rm -rf test_problem_pp test_problem_sf test_problem_mf
