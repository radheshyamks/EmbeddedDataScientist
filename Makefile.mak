#comment
OBJ=file.o test.o
CFLAGS= -fprofile-arcs -ftest-coverage
BRANCH= --branch-coverage
SRC1=file.c
SRC2=test.cpp
INC=../hdr
VALGRIND=valgrind --log-file=out.txt --leak-check=full --tool=memcheck
VERS=--version
LINK_LIB= -lgtest -lpthread -lgmock
CC=g++
cc=gcc
all:target
target: $(OBJ)
	$(CC) -o $@ $^ $(LINK_LIB) $(CFLAGS)
test.o: $(SRC2)
	$(CC) -c $^ -I $(INC)
file.o: $(SRC1)
	$(cc) -c $^ -I $(INC) $(CFLAGS)
.PHONY: clean run gcov genhtml coverage open
run:
	@echo "\e[1;33mRunning the file...\e[0m"
	@echo "\e[1;35m$(shell date +"%d-%m-%y")\e[0m"
	@$(VALGRIND) ./target
	@echo $(VERS)
clean:
	@echo "cleaning files..."
	@rm -rf *.o target *.txt *.g* out *.info
gcov:
	@gcov -b -c file.c
coverage:
	@lcov -c -d . -o file_result.info
genhtml:
	@genhtml $(BRANCH) file_result.info -o out
open:
	@xdg-open out/index.html
#genhtml_branch_coverage=1
#genhtml_function_coverage=1 
#lcov_branch_coverage=1
#lcov_function_coverage=1
#