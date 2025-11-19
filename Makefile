problem_pp:
	@gcc -std=c17 -Wall -Wextra test_problem_pp.c problem_pp.c -lcheck -lm -lpthread -o test_problem_pp
	@./test_problem_pp
	@make clean

problem_mf:
	@gcc -std=c17 -Wall -Wextra test_problem_mf.c problem_mf.c -lcheck -lm -lpthread -o test_problem_mf
	@./test_problem_mf
	@make clean

test_fibo_all:
	@gcc -std=c17 -Wall -Wextra test_fibo_all.c problem_hwf.c problem_sf.c problem_fm.c -lcheck -lm -lpthread -o test_fibo_all
	@./test_fibo_all
	@make clean

clean:
	@rm -rf test_problem_pp test_problem_mf a.out test_fibo_all