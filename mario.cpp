#include "mario.h"

//float r=0.0,g=0.0,b=0.0;
float minx = -30.0, miny =  -20.0, minz = -1.0;
float maxx =  30.0, maxy =   30.0, maxz =  1.0;

bool eixos = true;

int tecla, x, y;

float dxM = 0.0, dyM = 0.0, dzM = 0.0;

float lado = 0;

float passo = 1.0;

bool pulo = false;

bool sobe = true;

bool desce = true;

bool cai = false;

float ml = 0;
float mr = 0;

int id = 0;

int vetorColisaoL[5];
int vetorColisaoR[5];

void vetorColisao(void){
	vetorColisaoL[0] = 50.0;
	vetorColisaoR[0] = 45.0;
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	if(eixos) 
	eixosGlobal();

	desenhaFundo();
	desenhaChao();
	//desenhaLua(15,15);
	//desenhaNuvem();

	glPushMatrix();
		glTranslatef(dxM,dyM,dzM);
		desenhaMario();
	glPopMatrix();

	desenhaCano();
	vetorColisao(); 

	glutSwapBuffers();
}


void Projecao(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(minx+dxM,maxx+dxM,miny,maxy,minz,maxz);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void reshape(int w, int h){
	glViewport(0,0,w,h);
	
	Projecao();
}


void eixosGlobal(void){
	glBegin(GL_LINES);
		
		glColor3f(1,0,0);
		glVertex2f(minx,0.0);
		glVertex2f(maxx,0.0);

		glColor3f(0,1,0);
		glVertex2f(0.0,miny);
		glVertex2f(0.0,maxy);
 		
 	glEnd();
}


//cenario
void desenhaFundo(){
	glBegin(GL_QUADS);

		//ceu
		glColor3f(0.0,0.2,0.4);

		glVertex2f(100.0,100.0);
		glVertex2f(-100.0,100.0);
		glVertex2f(-100.0,1.0);
		glVertex2f(100.0,1.0);

		//caverna
		glColor3f(1.0,1.0,1.0);

		glVertex2f(62.0,0.0);
		glVertex2f(80.0,0.0);
		glVertex2f(80.0,-20.0);
		glVertex2f(62.0,-20.0);


	glEnd();
}

/*
void desenhaLua(int a, int b){
	float pi = 3.14;
	float circulo = 100.0;
	float anglulo, raioA = 27.0, raioB = 8.0;

	glBegin(GL_POLYGON);
		glColor3f(0.184314,0.309804,0.309804);
		for(int i = 0; i < circulo; i++){
			angulo = 2*pi*i/circulo;
			glVertex2f(cos(angulo)*raioA+a,sin(angulo)*raioB+b;
		}
	glEnd();
}
*/

// void desenhaNuvem(){
// 	glBegin(GL_CIRCUN);

// 	float ang, pi = 3.14;
// 	float Xc, Yc, Xo = 0, Yo = 0, raio = 1;
		
// 		for(int i = 0; i < 360, i++){
// 		 	ang = (pi*i)/180;
// 		 	Xc = cos(ang)*raio+Xo;
// 		 	Yc = sin(ang)*raio+Yo;
// 		 	glVertex2f(Xc,Yc);
// 		}		

// 	glEnd();
// }


void desenhaChao(){

	glBegin(GL_QUADS);

	glColor3f(0.6,0.4,0.2);

	glVertex2f(20.0,1.0);
	glVertex2f(-100.0,1.0);
	glVertex2f(-100.0,0.0);
	glVertex2f(20.0,0.0);	

	glVertex2f(100.0,1.0);
	glVertex2f(25.0,1.0);
	glVertex2f(25.0,0.0);
	glVertex2f(100.0,0.0);	

	glEnd();
}
		

void desenhaCano(){

	glBegin(GL_QUADS);

		//cano 1
		glColor3f(0.0,1.0,0.0);

		glVertex2f(51.0,6.0);
		glVertex2f(45.0,6.0);
		glVertex2f(45.0,4.0);
		glVertex2f(51.0,4.0);

		glVertex2f(50.0,4.0);
		glVertex2f(46.0,4.0);
		glVertex2f(46.0,1.0);
		glVertex2f(50.0,1.0);

		//cano 2
		glColor3f(0.0,1.0,0.0);

		glVertex2f(67.0,6.0);
		glVertex2f(61.0,6.0);
		glVertex2f(61.0,4.0);
		glVertex2f(67.0,4.0);

		glVertex2f(66.0,6.0);
		glVertex2f(62.0,6.0);
		glVertex2f(62.0,0.0);
		glVertex2f(66.0,0.0);

		//cano caverna
		glColor3f(0.0,1.0,0.0);

		glVertex2f(80.0,-15.0);
		glVertex2f(78.0,-15.0);
		glVertex2f(78.0,-20.0);
		glVertex2f(80.0,-20.0);

		//cano 3
		glColor3f(0.0,1.0,0.0);

		glVertex2f(90.0,22.0);
		glVertex2f(84.0,22.0);
		glVertex2f(84.0,20.0);
		glVertex2f(90.0,20.0);

		glVertex2f(89.0,20.0);
		glVertex2f(85.0,20.0);
		glVertex2f(85.0,1.0);
		glVertex2f(89.0,1.0);


	glEnd();
}


//personagem
void desenhaMario(){
	glBegin(GL_QUADS);

		
		//chapeu
		glColor3f(1,0,0);
		glVertex2f(2.0,5.0);
		glVertex2f(-2.0,5.0);
		glVertex2f(-2.0,4.5);
		glVertex2f(2.0,4.5);

		//rosto
		glColor3f(0.5,0.5,0.3);
		glVertex2f(2.0,4.5);
		glVertex2f(-2.0,4.5);
		glVertex2f(-2.0,3.5);
		glVertex2f(2.0,3.5);

		//olho
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1.7,4.2);
		glVertex2f(1.2,4.2);
		glVertex2f(1.2,3.7);
		glVertex2f(1.7,3.7);

		//camisa
		glColor3f(1,0,0);
		glVertex2f(2.0,3.5);
		glVertex2f(-2.0,3.5);
		glVertex2f(-2.0,2.0);
		glVertex2f(2.0,2.0);

		//calça
		glColor3f(0,0,1);
		glVertex2f(2.0,2.0);
		glVertex2f(-2.0,2.0);
		glVertex2f(-2.0,1.0);
		glVertex2f(2.0,1.0);

	glEnd();
}


//botoes de acao
void special(int tecla, int x, int y){

	switch(tecla){
		case GLUT_KEY_F1: 
			eixos = !eixos;
		break;

		//case GLUT_KEY_RIGHT:
		//	dxM += passo;
		//	Projecao();
		//break;

		case GLUT_KEY_RIGHT:
				mr = dxM + 1.0;
				if(mr != vetorColisaoR[id]){
					dxM += passo;
					Projecao();
				}else{
					dxM += 8.0;
					Projecao();
					id++;
				}
		break;

		//case GLUT_KEY_LEFT:
		//	dxM -= passo;
		//	Projecao();
		//break;

		case GLUT_KEY_LEFT:
				ml = dxM - 1.0;
				if(ml != vetorColisaoL[id - 1]){
					dxM -= passo;
					Projecao();
				}else{
					dxM -= 8.0;
					Projecao();
					id--;
				}
		break;

		case GLUT_KEY_UP:
			pulo = true;
			//dyM += passo;
			Projecao();
		break;

		case GLUT_KEY_DOWN:
			cai = true;
			//dyM -= passo;
			Projecao();
		break;
	}

	glutPostRedisplay();
}


//pula e cai
void timer (int i){
	if(pulo){
		if(sobe){
			dyM+=passo+9;
			if(dyM>=0.5){
				sobe = false;
			}
		}else{
			dyM-=passo;
			if(dyM<=0.0){
				sobe = true;
				pulo = false;
				dyM = 0.0;
			}
		}

		glutPostRedisplay();
	}

	
	if(dxM > 20.0 && dxM < 25.0 || dxM > 62 && dxM < 66){
		//dyM-=passo;
		cai = true;
	}else{
		cai = false;
	}


	if(cai){
		if(desce){
			dyM-=passo;
			//for(dyM = 0; dyM > -21.0; dyM-=passo){
				glutPostRedisplay();
			//}
		}
	}
	

	glutTimerFunc(120,timer,1);
}




/*
float colisao(float dMx){

	float id;
	Vd[id];

	dMx++;

	if(Md >= Vd[id]){
		dMx += lado;
		id++;
	}

return ;
}
*/