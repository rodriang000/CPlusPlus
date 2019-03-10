# Makefile for the Rational class
CMP = g++
MAIN = life
CLASS = lifeboard
EXEC = runlife

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) -std=c++11 $(MAIN).o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c -std=c++11 $(MAIN).cpp -o $(MAIN).o

rational.o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c -std=c++11 $(CLASS).cpp -o $(CLASS).o

clean:
	rm $(MAIN).o $(CLASS).o 
	rm $(EXEC)

