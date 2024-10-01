CXXFLAGS=-c

all: quad

debug: CXXFLAGS=-c -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
debug: quad

release: CXXFLAGS=-c -DNDEBUG -lm
release: quad

quad: check_double.o logging.o main.o my_input.o my_output.o print_error.o print_help.o run_test.o settings_of_program.o square_solver.o work_with_user.o
	g++ check_double.o logging.o main.o my_input.o my_output.o print_error.o print_help.o run_test.o settings_of_program.o square_solver.o work_with_user.o -o quad

main.o: main.cpp
	g++ $(CXXFLAGS) main.cpp

check_double.o: check_double.cpp
	g++ $(CXXFLAGS) check_double.cpp

logging.o: logging.cpp
	g++ $(CXXFLAGS) logging.cpp

my_input.o: my_input.cpp
	g++ $(CXXFLAGS) my_input.cpp

my_output.o: my_output.cpp
	g++ $(CXXFLAGS) my_output.cpp

print_error.o: print_error.cpp
	g++ $(CXXFLAGS) print_error.cpp

print_help.o: print_help.cpp
	g++ $(CXXFLAGS) print_help.cpp

run_test.o: run_test.cpp
	g++ $(CXXFLAGS) run_test.cpp

settings_of_program.o: settings_of_program.cpp
	g++ $(CXXFLAGS) settings_of_program.cpp

square_solver.o: square_solver.cpp
	g++ $(CXXFLAGS) square_solver.cpp

work_with_user.o: work_with_user.cpp
	g++ $(CXXFLAGS) work_with_user.cpp

clean:
	rm -rf *.o quad
