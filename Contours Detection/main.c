//////////////////////////////////////////////////////////////////////
//
// OGL32TEX.C
//  by Blaine Hodge
//


//#define GLUT_DISABLE_ATEXIT_HACK

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#define ESCAPE 27
#define C 99
#define N 110
#define I 105
#define T 116
#include "bmp.h"
Image *image;

int
Init(char *s){

  image = (Image *) malloc(sizeof(Image));
  if (image == NULL) {
    fprintf(stderr, "Out of memory\n");
    return(-1);
  }
  if(strstr(s,".bmp")!=NULL){
    if (ImageLoad(s, image)==-1) return(-1);
  }

  else if(strstr(s,".sci")!=NULL){
    if (ImageLoadSCI(s, image)==-1) return(-1);
  }

  /* petit truc*/
glutReshapeWindow(5,6);

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glutReshapeWindow(image->sizeX, image->sizeY);

  return (0);
}

void
Display(void){

  GLint w, h;

  glClear(GL_COLOR_BUFFER_BIT);
  w = glutGet(GLUT_WINDOW_WIDTH);
  h = glutGet(GLUT_WINDOW_HEIGHT);
  glDrawPixels(image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE,
	       image->data);

  glFlush();
}

void
Reshape(int w, int h){

  glViewport(0, 0, (GLsizei)w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble)h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y)  {
  int sens;
  switch(key){
  case ESCAPE :
    exit(0);
    break;

    case C :
   detecterColor(image);
printf("succes ! \n");
	Display();
    break;

     case N:
    printf("Entrer la sensibilite \n");
    scanf("%d", &sens);
    detecterClair(image,sens);
    printf("succes ! \n");
	Display();
    break;

      case I:
   printf("Entrer la sensibilite \n");
    scanf("%d", &sens);
    detecterSurImage(image,sens);
    printf("succes ! \n");
	Display();
    break;
case T:
  printf("Entrer la sensibilite \n");
    scanf("%d", &sens);
detecterLesTaches(image,sens);

Display();
    break;


  default:
    fprintf(stderr, "Unused key\n");
  }
}
int ReInit() {

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glutReshapeWindow(image->sizeX, image->sizeY);

  return (0);
}

void menuFunc(int item) {


  char s[256];

int sens;
  switch(item){
  case 0:
    free(image);
    exit(0);
    break;
  case 1:
    printf("Taille de cette image : %d %d\n", (int) image->sizeX, (int) image->sizeY);
    break;

  case 2:
    printf("Gris uniforme\n");
	engris(image);
	Display();
    break;
  case 3:
    printf("Entrer le nom \n");
    scanf("%s", &s[0]);
    Init(s);

    break;
  case 4:
    printf("Entrer le nom pour l'image dans cette taille\n");
    scanf("%s", &s[0]);
    ImageSave(s, image);
    break;

    case 5:

detecterColor(image);
printf("succes ! \n");
	Display();
    break;

    case 6:
    printf("Entrer la sensibilite \n");
    scanf("%d", &sens);
    detecterClair(image,sens);
    printf("succes ! \n");
	Display();
    break;

      case 7:
   printf("Entrer la sensibilite \n");
    scanf("%d", &sens);
    detecterSurImage(image,sens);
    printf("succes ! \n");
	Display();
    break;
case 8:
  printf("Entrer la sensibilite \n");
    scanf("%d", &sens);
detecterLesTaches(image,sens);

Display();
    break;


  default:
    break;
  }
}
void Mouse(int button, int state, int x, int y) {

  switch(button){
  case GLUT_LEFT_BUTTON:
    break;
  case GLUT_MIDDLE_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    break;
  }
  glutPostRedisplay();
}
int
main(int argc, char **argv)
{
if (argc<2) {
    fprintf(stderr, "Usage : palette nom_de_fichier\n");
    exit(0);
  }


  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(480,480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("VPUP8");

  Init(argv[1]);
  glutCreateMenu(menuFunc);
  glutAddMenuEntry("Quit", 0);
  glutAddMenuEntry("Informations", 1);
  glutAddMenuEntry("EnGris", 2);
  glutAddMenuEntry("Ouvrir", 3);
  glutAddMenuEntry("Sauver", 4);
  glutAddMenuEntry("detecter les contours en couleur", 5);
  glutAddMenuEntry("detecter les contours en noir et blanc", 6);
  glutAddMenuEntry("detecter les contours sur l'image", 7);
  glutAddMenuEntry("les taches", 8);
  glutAttachMenu(GLUT_LEFT_BUTTON);

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);

  glutMouseFunc(Mouse);

  glutMainLoop();

  return 1;

    }








// Texture ///////////////////////////////////////////////////////////
