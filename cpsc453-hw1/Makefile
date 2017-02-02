test: Triangle.o boilerplate.o Hexagon.o
	g++ -std=c++14 -o test Triangle.o boilerplate.o Hexagon.o -framework OpenGL `pkg-config --static --libs glfw3`
boilerplate.o: boilerplate.cpp
	g++ -std=c++14 -c boilerplate.cpp -framework OpenGL `pkg-config --static --libs glfw3`
Triangle.o: Triangle.cpp Triangle.hpp
	g++ -std=c++14 -c Triangle.cpp -framework OpenGL `pkg-config --static --libs glfw3 `

Hexagon.o: Hexagon.cpp Hexagon.hpp
	g++ -std=c++14 -c Hexagon.cpp -framework OpenGL `pkg-config --static --libs glfw3`
clean:
	rm test boilerplate.o Triangle.o Hexagon.o
