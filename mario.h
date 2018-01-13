#ifndef MARIO_H
#define MARIO_H

#include "GL/glut.h"
#include "math.h"


void display(void);
//void Init(void);
//void keyboard(unsigned char tecla, int x, int y);
void reshape(int w, int h);
void Projecao(void);
void eixosGlobal(void);
void special(int tecla, int x, int y);
void desenhaMario();
void desenhaFundo();
void desenhaCano();
void desenhaChao();
void desenhaNuvem();
//float colisao();
void timer(int i);
void vetorColisao(void);

#endif