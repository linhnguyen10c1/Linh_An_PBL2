build : compile
	g++ login.o -o login -L"E:\bin\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
compile :
	g++ -c login.cpp -I"E:\bin\SFML-2.6.1\include"