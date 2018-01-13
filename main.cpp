#include "mario.h"

using namespace std;

int main(int argc, char *argv[]){
	
	
	//Escopo de criação de janela
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("Mario");
	

	//Escopo de registro callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);


	//Pulo
	glutTimerFunc(60,timer,1);


	glutMainLoop();
	return 0;
};
