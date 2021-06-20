FLAGS=-Wall

COMPILER=g++

OBJ=format

FILE=format.cpp

build/format: $(FILE)
	$(COMPILER) $(FLAGS) -o build/$(OBJ) $(FILE)
clean: 
	rm -rf build/$(OBJ)