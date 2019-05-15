OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_Idiomes.o Idioma.o Treecode.o Taula_de_freq.o
	g++ -o program.exe *.o $(OPCIONS)
	rm -f *.o
	
program.o: program.cc Cjt_Idiomes.hh Idioma.hh Treecode.hh Taula_de_freq.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)
	
Cjt_Idiomes.o: Cjt_Idiomes.cc Cjt_Idiomes.hh
	g++ -c Cjt_Idiomes.cc $(OPCIONS)
	
Idioma.o: Idioma.cc Idioma.hh
	g++ -c Idioma.cc $(OPCIONS)
	
Treecode.o: Treecode.cc Treecode.hh
	g++ -c Treecode.cc $(OPCIONS)
	
Taula_de_freq.o: Taula_de_freq.cc Taula_de_freq.hh
	g++ -c Taula_de_freq.cc $(OPCIONS)
	
clean:
	rm -f *.o
	
superclean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar
	
practica.tar:
	tar -cvf practica.tar program.cc Cjt_Idiomes.cc Cjt_Idiomes.hh Idioma.cc Idioma.hh Treecode.cc Treecode.hh Taula_de_freq.cc Taula_de_freq.hh Makefile
	
compara: program.exe
	./program.exe < sample_intermedia.inp > sample_intermedia.out
	kompare sample_intermedia.out sample_intermedia.cor
	rm -f sample_intermedia.out
