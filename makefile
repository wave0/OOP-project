# OOP-project

VPATH = ./include;./src
CXXFLAGS = -Wall -std=c++11 -I ./include
obj = main.o dict.o wordlist.o wordstatus.o

main.exe: $(obj)
	g++ -o main.exe $(obj)

main.o: main.cpp dict.h

dict.o: dict.cpp dict.h

wordlist.o: wordlist.cpp wordlist.h wordstatus.h

wordstatus.o: wordstatus.cpp wordstatus.h

.PHONY: clean
clean:
	-rm main.exe $(obj)
