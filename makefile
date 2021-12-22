userInterface: userInterface.o linkedList.o implement.o
	gcc -o userInterface userInterface.o linkedList.o implement.o

userInterface.o: userInterface.cpp linkedList.cpp implement.cpp res.h
	gcc -c userInterface.cpp