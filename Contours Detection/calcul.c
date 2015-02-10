#include "bmp.h"
#include "calcul.h"



/* cette fonction perment d'obtenir les voisins d'un pixel sur un tableau de monodimension*/
/* on lui don comme parametre X , Y et la longeur de l'image */
int calculXY(int x,int y,int SizeX) {
    return  ((SizeX*y)+(x));
}

/* la fonction qui modifier les pixeles qui sont toutes seules pour que le resultat soit plus clair.
 CAD leur voisins sont differentes. pour le modifier on calcul la moyenne des couleurs des voisins
 et on change la couleur de pixel par la moyenne .
par exemple un pixel  que  ses voisins sont noir.*/
void nettoyer(Image * i){
    int  size,x,y,longeur,moyR,moyV,moyB;
    GLubyte *im;
    size =i->sizeY * i->sizeX;
    im = i->data; /* les données de l'image (les couleurs) */
    longeur=i->sizeX; /* la longeur */

    for(x=0 ; x<i->sizeX; x++)
        for(y=0 ; y<i->sizeY; y++)
        {
            if(x-1>=0 && y-1>=0 && x+1<i->sizeX && y+1<i->sizeY){ /* avec cette condition on évite de débordement de la boucle */

    /* cette fonction marche si et seulment si toutes les voisins sont different */
    /* donc on essaye de verifier toutes les voisins */

                if(im[calculXY(x,y,longeur)*3]==0 &&
                im[(calculXY(x,y,longeur)*3)+1]==0&&
                im[(calculXY(x,y,longeur)*3)+2]==0)   /* si le pixel est noir */

                if(im[calculXY(x+1,y,longeur)*3]!=0 &&
                im[(calculXY(x+1,y,longeur)*3)+1]!=0&&
                im[(calculXY(x+1,y,longeur)*3)+2]!=0) /*  si le pixel qui est à l'est n'est pas noir */

                if(im[calculXY(x,y+1,longeur)*3]!=0 &&
                im[(calculXY(x,y+1,longeur)*3)+1]!=0&&
                im[(calculXY(x,y+1,longeur)*3)+2]!=0)  /*  si le pixel qui est au nord n'est pas noir */

                if(im[calculXY(x-1,y,longeur)*3]!=0 &&
                im[(calculXY(x-1,y,longeur)*3)+1]!=0&&
                im[(calculXY(x-1,y,longeur)*3)+2]!=0)  /*  si le pixel qui est au sud n'est pas noir */

                if(im[calculXY(x,y-1,longeur)*3]!=0 &&
                im[(calculXY(x,y-1,longeur)*3)+1]!=0&&
                im[(calculXY(x,y-1,longeur)*3)+2]!=0)   /*  si le pixel qui est à l'ouest n'est pas noir */

                if(im[calculXY(x+1,y+1,longeur)*3]!=0 &&
                im[(calculXY(x+1,y+1,longeur)*3)+1]!=0&&
                im[(calculXY(x+1,y+1,longeur)*3)+2]!=0)  /*  si le pixel qui est au nord-est n'est pas noir */

                if(im[calculXY(x-1,y-1,longeur)*3]!=0 &&
                im[(calculXY(x-1,y-1,longeur)*3)+1]!=0&&
                im[(calculXY(x-1,y-1,longeur)*3)+2]!=0)  /*  si le pixel qui est au sud-ouest n'est pas noir */

                if(im[calculXY(x+1,y-1,longeur)*3]!=0 &&
                im[(calculXY(x+1,y-1,longeur)*3)+1]!=0&&
                im[(calculXY(x+1,y-1,longeur)*3)+2]!=0)   /*  si le pixel qui est au sud-est n'est pas noir */

                if(im[calculXY(x-1,y+1,longeur)*3]!=0 &&
                im[(calculXY(x-1,y+1,longeur)*3)+1]!=0&&
                im[(calculXY(x-1,y+1,longeur)*3)+2]!=0){   /*  si le pixel qui est au nord-ouest n'est pas noir */


                    moyB=(im[(calculXY(x+1,y-1,longeur)*3)+2]+im[(calculXY(x+1,y,longeur)*3)+2]+
                    im[(calculXY(x,y+1,longeur)*3)+2]+im[(calculXY(x-1,y,longeur)*3)+2]+
                    im[(calculXY(x,y-1,longeur)*3)+2]+im[(calculXY(x-1,y-1,longeur)*3)+2]+
                    im[(calculXY(x+1,y+1,longeur)*3)+2]+im[(calculXY(x-1,y+1,longeur)*3)+2])/8; /* on calcul la couleur blue des voisins */

                    moyV=(im[(calculXY(x-1,y+1,longeur)*3)+1]+im[(calculXY(x+1,y-1,longeur)*3)+1]+
                    im[(calculXY(x-1,y-1,longeur)*3)+1]+im[(calculXY(x+1,y+1,longeur)*3)+1]+
                    im[(calculXY(x,y-1,longeur)*3)+1]+im[(calculXY(x-1,y,longeur)*3)+1]+
                    im[(calculXY(x,y+1,longeur)*3)+1]+im[(calculXY(x+1,y,longeur)*3)+1])/8;  /* on calcul la couleur vert des voisins */

                    moyR=(im[calculXY(x+1,y-1,longeur)*3]+im[calculXY(x+1,y,longeur)*3]+
                    im[calculXY(x,y+1,longeur)*3]+im[calculXY(x-1,y,longeur)*3]+
                    im[calculXY(x,y-1,longeur)*3]+im[calculXY(x+1,y+1,longeur)*3]+
                    im[calculXY(x-1,y-1,longeur)*3]+im[calculXY(x-1,y+1,longeur)*3])/8;  /* on calcul le couleur rouge des voisins */



/* on change les compesant RVB(RGB) */
                    im[calculXY(x,y,longeur)*3]=(GLubyte) moyR;
                    /* le rouge */
                    im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) moyV;
                    /* le vert  */
                    im[(calculXY(x,y,longeur)*3)+2]=(GLubyte) moyB;
                    /* le blue  */


                }


/* maintenant on va voir les pixels qui sont pas noir et ses voisins sont noir */

                if(im[calculXY(x,y,longeur)*3]!=0 &&
                im[(calculXY(x,y,longeur)*3)+1]!=0&&
                im[(calculXY(x,y,longeur)*3)+2]!=0) /* si le pixel n'est pas noir */

                if(im[calculXY(x+1,y,longeur)*3]==0 &&
                im[(calculXY(x+1,y,longeur)*3)+1]==0&&
                im[(calculXY(x+1,y,longeur)*3)+2]==0) /*  si la pixel qui est à l'est est noir */

                if(im[calculXY(x,y+1,longeur)*3]==0 &&
                im[(calculXY(x,y+1,longeur)*3)+1]==0&&
                im[(calculXY(x,y+1,longeur)*3)+2]==0) /*  si la pixel qui est au nord est noir */

                if(im[calculXY(x-1,y,longeur)*3]==0 &&
                im[(calculXY(x-1,y,longeur)*3)+1]==0&&
                im[(calculXY(x-1,y,longeur)*3)+2]==0) /*  si la pixel qui est à l'ouest est noir */

                if(im[calculXY(x,y-1,longeur)*3]==0 &&
                im[(calculXY(x,y-1,longeur)*3)+1]==0&&
                im[(calculXY(x,y-1,longeur)*3)+2]==0)  /*  si la pixel qui est au sud est noir */

                if(im[calculXY(x+1,y+1,longeur)*3]==0 &&
                im[(calculXY(x+1,y+1,longeur)*3)+1]==0&&
                im[(calculXY(x+1,y+1,longeur)*3)+2]==0)  /*  si la pixel qui est au nord-est est noir */

                if(im[calculXY(x-1,y-1,longeur)*3]==0 &&
                im[(calculXY(x-1,y-1,longeur)*3)+1]==0&&
                im[(calculXY(x-1,y-1,longeur)*3)+2]==0)    /*  si la pixel qui est sud-ouest est noir */

                if(im[calculXY(x+1,y-1,longeur)*3]==0 &&
                im[(calculXY(x+1,y-1,longeur)*3)+1]==0&&
                im[(calculXY(x+1,y-1,longeur)*3)+2]==0)  /*  si la pixel qui est au sud-est est noir */

                if(im[calculXY(x-1,y+1,longeur)*3]==0 &&
                im[(calculXY(x-1,y+1,longeur)*3)+1]==0&&
                im[(calculXY(x-1,y+1,longeur)*3)+2]==0){ /*  si la pixel qui est au nord-ouest est noir */

/*si toutes les condition sont vrai on  change la couleur et on la met en noir */

                    im[calculXY(x,y,longeur)*3]=(GLubyte) 0;

                    im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) 0;

                    im[(calculXY(x,y,longeur)*3)+2]=(GLubyte) 0;


                }
            }
        }

}



/* cette fonction permet de contourer les taches sur l'image  */
/* il affiche les contours en noir */
void detecterSurImage(Image * i,int sens){
    int  size,r,g,b,r1,g1,b1,x,y,longeur;
    GLubyte *im;
    size =i->sizeY * i->sizeX;
    im = i->data;
    longeur =i->sizeX;


/* dans cette boucle on  calcul la diffrence de tous les pixeles par raport aux voisins de nord et l'est */
    for(y=0 ; y<i->sizeY; y++)
        for(x=0 ; x<i->sizeX; x++)
        {

            if(x+1<i->sizeX && y+1<i->sizeY ){ /* avec cette condition on évite de débordement de la boucle */
                r= abs(im[calculXY(x,y,longeur)*3]-im[calculXY(x+1,y,longeur)*3]);
                /* calculer la difference des rouges pour la voisin qui est à l'est  */
                r1= abs(im[calculXY(x,y,longeur)*3]-im[calculXY(x,y+1,longeur)*3]);
                /* calculer la difference des rouges pour la voisin qui est au nord */
                g=abs(im[(calculXY(x,y,longeur)*3)+1]-im[(calculXY(x+1,y,longeur)*3)+1]);
                /* calculer la difference des vertes pour la voisin qui est à l'est  */
                g1=abs(im[(calculXY(x,y,longeur)*3)+1]-im[(calculXY(x,y+1,longeur)*3)+1]);
                /* calculer la difference des vertes pour la voisin qui est au nord */
                b= abs(im[(calculXY(x,y,longeur)*3)+2]-im[(calculXY(x+1,y,longeur)*3)+2]);
                /* calculer la difference des blues pour la voisin qui est à l'est  */
                b1= abs(im[(calculXY(x,y,longeur)*3)+2]-im[(calculXY(x,y+1,longeur)*3)+2]);
                /* calculer la difference des blues pour la voisin qui est au nord */


                if(r< sens && r1<sens && g<sens && g1<sens && b<sens &&  b1<sens) /* si toutes les valeur qu'on vient de calculer est plus petit que la sensibilite*/
                    continue; /* on continue */

/* dans le cas ou toutes valeur de r,r1,g,g1, ... sont plus grand que la sensibilite on change la couleur de pixel */
/* et on le met en noir */
                im[calculXY(x,y,longeur)*3]=(GLubyte) 0;
                /* on met le rouge en 0*/
                im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) 0;
                /* on met le vert en 0*/
                im[(calculXY(x,y,longeur)*3)+2]=( GLubyte) 0;
                /* on met le blue en 0*/

            }
        }
    nettoyer(i); /* et à la fin on suprimme les pixels qui sont toutes seul */
}



/* cette fonction permet de detecter les taches de couleur et les modifier */
void detecterLesTaches(Image * i,int sens){
    int  size,r,g,b,r1,g1,b1,longeur,x,y;
    GLubyte *im;
    size =i->sizeY * i->sizeX;
    im = i->data;
    longeur=i->sizeX;

/* dans cette boucle on  calcul la diffrence de tous les pixeles par raport aux voisins de nord et l'est */

    for(y=0 ; y<i->sizeY; y++)
        for(x=0 ; x<i->sizeX; x++)
        {

            if(x+1<i->sizeX && y+1<i->sizeY ){
                /* avec cette condition on évite de débordement de la boucle */
                r= abs(im[calculXY(x,y,longeur)*3]-im[calculXY(x+1,y,longeur)*3]);
                /* calculer la difference des rouges pour la voisin qui est à l'est  */
                r1= abs(im[calculXY(x,y,longeur)*3]-im[calculXY(x,y+1,longeur)*3]);
                /* calculer la difference des rouges pour la voisin qui est au nord */
                g=abs(im[(calculXY(x,y,longeur)*3)+1]-im[(calculXY(x+1,y,longeur)*3)+1]);
                /* calculer la difference des vertes pour la voisin qui est à l'est  */
                g1=abs(im[(calculXY(x,y,longeur)*3)+1]-im[(calculXY(x,y+1,longeur)*3)+1]);
                /* calculer la difference des vertes pour la voisin qui est au nord */
                b= abs(im[(calculXY(x,y,longeur)*3)+2]-im[(calculXY(x+1,y,longeur)*3)+2]);
                /* calculer la difference des blues pour la voisin qui est à l'est  */
                b1= abs(im[(calculXY(x,y,longeur)*3)+2]-im[(calculXY(x,y+1,longeur)*3)+2]);
                /* calculer la difference des blues pour la voisin qui est au nord */


                if(r< sens && r1<sens && g<sens && g1<sens && b<sens &&  b1<sens){/* si toutes les valeur qu'on vient de calculer sont plus petit que la sensibilite*/
                    /* on met le pixel en noir */

                    im[calculXY(x,y,longeur)*3]=(GLubyte) 0;

                    im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) 0;

                    im[(calculXY(x,y,longeur)*3)+2]=(GLubyte) 0;

                }

/* sinon on continue */
                continue;

            }
        }
    nettoyer(i); /* et à la fin on supprime les pixels qui sont toutes seul */
}

/* dans cette fonction on essaye de trouver les contours mais cette fois en couleur */
/* apres detecter les contours , les lignes qui sont plus lumineus ( ex : blanc ) CAD qu'il y a une gros diffrence de couleur */
/* et à l'inverse si une  ligne est moins lumineuse ou c'est noir ça veut dire soit il y a aucune difference */
/* soit il y a une contour qui n'est pas trop visible */
void detecterColor(Image * i){
    int  size,r,g,b,r1,g1,b1,x,y,longeur;
    GLubyte *im;
    size =i->sizeY * i->sizeX;
    im = i->data;
    longeur=i->sizeX;

/* dans cette boucle on  calcul la diffrence de tous les pixeles par raport aux voisins de nord et l'est */


    for(x=0 ; x<i->sizeX; x++)
        for(y=0 ; y<i->sizeY; y++)
        {
            if(x+1<i->sizeX && y+1<i->sizeY){

                r= abs(im[calculXY(x,y,longeur)*3]-im[calculXY(x+1,y,longeur)*3]);
                /* calculer la difference des rouges pour la voisin qui est à l'est  */
                r1= abs(im[calculXY(x,y,longeur)*3]-im[calculXY(x,y+1,longeur)*3]);
                /* calculer la difference des rouges pour la voisin qui est au nord */
                g=abs(im[(calculXY(x,y,longeur)*3)+1]-im[(calculXY(x+1,y,longeur)*3)+1]);
                /* calculer la difference des vertes pour la voisin qui est à l'est  */
                g1=abs(im[(calculXY(x,y,longeur)*3)+1]-im[(calculXY(x,y+1,longeur)*3)+1]);
                /* calculer la difference des vertes pour la voisin qui est au nord */
                b1= abs(im[(calculXY(x,y,longeur)*3)+2]-im[(calculXY(x,y+1,longeur)*3)+2]);
                /* calculer la difference des blues pour la voisin qui est à l'est  */
                b= abs(im[(calculXY(x,y,longeur)*3)+2]-im[(calculXY(x+1,y,longeur)*3)+2]);
                /* calculer la difference des blues pour la voisin qui est au nord */


               /* on compare les valeur de b, b1 , g , g1 ,r, r1 ;
               /*on cherche la valeur maximum entre chaque un des b,b1  et r,r1 et g,g1 */
                if(r>r1)
                    im[calculXY(x,y,longeur)*3]=(GLubyte) r;
                    /* si le r est plus grand que r1 donc on change la veleur de rouge */
                else
                    im[calculXY(x,y,longeur)*3]=(GLubyte) r1;
                    /* si c'est l'inverse on met le r1  */
                if(g>g1)
                    im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) g;
                    /* si le g est plus grand que g1 donc on change la veleur de vert */
                else
                    im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) g1;
                    /* si c'est l'inverse on met le g1  */
                if(b>b1)
                    im[(calculXY(x,y,longeur)*3)+2]=(GLubyte) b;
                    /* si le b est plus grand que b1 donc on change la veleur de blue */
                else
                    im[(calculXY(x,y,longeur)*3)+2]=( GLubyte) b1;
                    /* si c'est l'inverse on met le b1  */

            }

        }

}

/* cette fonction permet d'afficher les contours plus clair en noir et blanc */
/* les lignes blanc sont les contours de l'image */

void detecterClair(Image * i,int sens){
    int  size,longeur,x,y;
    Image * Imagetmp=i;
    GLubyte *im;
    size =Imagetmp->sizeY * Imagetmp->sizeX;
    im = Imagetmp->data;
    longeur=Imagetmp->sizeX;


    detecterColor(i);
    /* on detecte les contours en couleur */
    engris(i);
     /* on les met en gris */

    for(x=0 ; x<i->sizeX; x++)
        for(y=0 ; y<i->sizeY; y++)
        {

            if(im[calculXY(x,y,longeur)*3] <sens &&
            im[(calculXY(x,y,longeur)*3)+1]<sens &&
            im[(calculXY(x,y,longeur)*3)+2]<sens ){
                 /* si la couleur de pixel est plus petit que la sensibilité */
//continue;
                /* on le met en noir */
                /*
                im[calculXY(x,y,longeur)*3]=(GLubyte) 0;
                im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) 0;
                im[(calculXY(x,y,longeur)*3)+2]=(GLubyte) 0;
*/

            }else{
                /* si non en le met en blanc */
                im[calculXY(x,y,longeur)*3]=(GLubyte) 255;
                im[(calculXY(x,y,longeur)*3)+1]=(GLubyte) 255;
                im[(calculXY(x,y,longeur)*3)+2]=(GLubyte) 255;

            }
        }
    nettoyer(i); /* à la fin on suprimme les pixels qui sont toutes seuls */
}

/* la fonction pour mettre engirs */
void engris (Image * i) {
  int j, size, moy;
  GLubyte r, g, b, *im, *back;

  size = i->sizeY * i->sizeX;
  im = i->data;
  back = im;
  for (j = 0; j < size; j ++) {
	r = *im++ ;
	g = *im++ ;
	b = *im++ ;
	moy = r *1 + g *5 + b*0.5;
	moy >>= 3;
	*back++ = (GLubyte) moy;
	*back++ = (GLubyte) moy;
	*back++ = (GLubyte) moy;
  }



}

