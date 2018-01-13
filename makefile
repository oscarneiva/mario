all:
	clear 
	g++ mario.cpp main.cpp -o mario -lglut -lGL -lGLU #-lstdc++ -lc -lm 	
	./mario
	

