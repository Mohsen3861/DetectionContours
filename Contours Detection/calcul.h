#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int  calculXY(int x,int y , int sizeX);
void engris (Image *);
void netoiyer(Image *);
void detecterClair(Image *, int sens);
void detecterColor(Image *);
void detecterLesTaches(Image *,int sens);
void detecterSurImage(Image *,int sens);

