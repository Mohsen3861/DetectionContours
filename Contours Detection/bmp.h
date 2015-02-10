
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
struct Image {
    int sizeX;
    int  sizeY;
    GLubyte *data;
};

typedef struct Image Image;

int ImageLoad(char *filename, Image *image);
int ImageSave(char *filename, Image *image);
