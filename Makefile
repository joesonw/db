FLAGS=-std=c++11 
CXX=clang++
prog:	main.cpp field.o record.o
	 $(CXX) $(FLAGS) -g main.cpp field.o record.o -o prog -lboost_system

field.o: default/field.h default/field.cpp core/field.h core/error.h
	$(CXX) -Wall -c -g default/field.cpp -o field.o
record.o: default/record.h default/record.cpp core/record.h core/error.h
	$(CXX) -Wall -c -g default/record.cpp -o record.o

clean:
	rm *.o prog
