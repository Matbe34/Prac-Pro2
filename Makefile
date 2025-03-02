OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o 
	g++ -o program.exe *.o 
	
program.o: program.cc
	g++ -c *.cc
	
clean:
	rm -f *.o
	rm -f *.exe
