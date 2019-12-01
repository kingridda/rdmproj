#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define Malloc(type,VAL)   (type*)malloc(VAL*sizeof(type))
#define Mallop(type,VAL)   (type**)malloc(VAL*sizeof(type*))

char scanf_char()
{
    char A=0;
    char chaine[2]={'A','\n'};
    scanf("%s",chaine);
    A=chaine[0];
    return A;
}
float carr(float x){
	return x*x;
}
int scanf_int(){
	char A=0;
    char chaine[2]={'A','\n'};
    scanf("%s",chaine);
    A=chaine[0];
    return A-'0';
}

typedef struct chargement{
    // la strcurure de chargement
    float Px;
    float Py;
    float Xp;

}Chargement_P;

typedef struct chargementRepartie{
    // la strcurure de chargement repartie
    float Qy;
    float Xdebut;
    float Xfin;

}Chargement_repartie;

typedef struct reaction{
    // la strcurure de reaction(en KN)
    float Rya;
    float Rxb;
    float Ryb;

}reaction_appui;


void choix_1 (){
    float L ;
    int type_ch,nombreChargePonctuel;
    nombreChargePonctuel=5 ;//initialisation
    printf("### Resolution de system isostatique compose d'une poutre reposant  sur 2 appuis ###\n\n");

    printf("choisissez la longueur  de votre poutre : (0 < L < 10 (m) \n");
    	L=-1; //codition pour saisir L
		while (L>10.00 || L<0.00){
    		printf("L(m):");
    		char str_f[100]={0};
   			scanf("%s",str_f);
    		L=(float)atof(str_f); //j'ai changé ici atoi to atof:=
    }
    {
        printf("choisissez le type de chargement que vous disirez imposer a la poutre\n");
        printf("1  :  chargement ponctuel uniquement (5 chargements )\n");
        printf("2  :  chargement lineraire uniquement (2 chargements )\n");
        printf("3  :  chargement mixte (3 ponctuel et 1 lineaire \n");

        printf("\ntype de chargement:");
        type_ch=scanf_int();
        
        printf("type de chargement: %d \t poutre de longueur: %f (m) ",type_ch,L); 
    }
	
	int i=0;
	int nbChargementP=0;
	Chargement_P *tableauChargement=Malloc(Chargement_P,5);
	reaction_appui Resultat_react_appui;
	Resultat_react_appui.Rxb=0;
	Resultat_react_appui.Rya=0;
	Resultat_react_appui.Ryb=0;

	Chargement_repartie ch_repartie;

	switch(type_ch){
		case 1:
			printf("\nsaisir le nombre des chargres ponctuelles (max 5):");
			nbChargementP= scanf_int();
			
			for (i; i< nbChargementP; i++){
				char str_f[100]={0};
				printf("veillez saisir les valeurs suivants separees des espaces: coodronnee x de point %d , son charge suivant x puis suivant y \n",i+1);
				scanf("%s",str_f);
    			tableauChargement[i].Xp=(float)atof(str_f); 
   				scanf("%s",str_f);
    			tableauChargement[i].Px=(float)atof(str_f); 
    			Resultat_react_appui.Rxb-=(float)atof(str_f);
    			scanf("%s",str_f);
    			tableauChargement[i].Py=(float)atof(str_f);
    			Resultat_react_appui.Rya+=(tableauChargement[i].Py* (L-tableauChargement[i].Xp))/L;
    			Resultat_react_appui.Ryb+=(tableauChargement[i].Py* tableauChargement[i].Xp)/L;
				}
				
			break;
		case 2:
			printf("veillez saisir les valeurs suivants separees des espaces: coodronnee x de debut , de la fin , puis valeur absolue de charge lineaire en (kN/m) \n");
			char str_f[100]={0};
			scanf("%s",str_f);
    		ch_repartie.Xdebut=(float)atof(str_f); 
			scanf("%s",str_f);
    		ch_repartie.Xfin=(float)atof(str_f); 
    		scanf("%s",str_f);
    		ch_repartie.Qy=(-1)*(float)atof(str_f);
			
			Resultat_react_appui.Rxb=0;
			Resultat_react_appui.Rya=( 2*L*(ch_repartie.Xdebut-ch_repartie.Xfin)-(carr(ch_repartie.Xdebut)-carr(ch_repartie.Xfin)))/(2*L);
			Resultat_react_appui.Ryb=(ch_repartie.Qy*(carr(ch_repartie.Xdebut)-carr(ch_repartie.Xfin)))/(2*L);
			break;
		case 3:
			printf("\nsaisir le nombre des chargres ponctuelles (max 5):");
			nbChargementP= scanf_int();
			
			for (i; i< nbChargementP; i++){
				char str_f[100]={0};
				printf("veillez saisir les valeurs suivants separees des espaces: coodronnee x de point %d , son charge suivant x puis suivant y \n",i+1);
				scanf("%s",str_f);
    			tableauChargement[i].Xp=(float)atof(str_f); 
   				scanf("%s",str_f);
    			tableauChargement[i].Px=(float)atof(str_f); 
    			Resultat_react_appui.Rxb-=(float)atof(str_f);
    			scanf("%s",str_f);
    			tableauChargement[i].Py=(float)atof(str_f);
    			Resultat_react_appui.Rya+=(tableauChargement[i].Py* (L-tableauChargement[i].Xp))/L;
    			Resultat_react_appui.Ryb+=(tableauChargement[i].Py* tableauChargement[i].Xp)/L;
				}
			printf("\nveillez saisir les valeurs suivants separees des espaces: coodronnee x de debut , de la fin , puis valeur absolue de charge lineaire en (kN/m) \n");
			scanf("%s",str_f);
    		ch_repartie.Xdebut=(float)atof(str_f); 
			scanf("%s",str_f);
    		ch_repartie.Xfin=(float)atof(str_f); 
    		scanf("%s",str_f);
    		ch_repartie.Qy=(-1)*(float)atof(str_f);
			
			Resultat_react_appui.Rya+=( 2*L*(ch_repartie.Xdebut-ch_repartie.Xfin)-(carr(ch_repartie.Xdebut)-carr(ch_repartie.Xfin)))/(2*L);
			Resultat_react_appui.Ryb+=(ch_repartie.Qy*(carr(ch_repartie.Xdebut)-carr(ch_repartie.Xfin)))/(2*L);		
			
			break;
		default : printf("choix incorrect");
	}

    FILE* fichier = NULL;
    fichier = fopen("note de calcule.txt", "w");
    if (fichier != NULL)
    {
    	switch(type_ch){
			case 1:
			    fprintf(fichier,"Longueur de la poutre : %f m", L);
			    fprintf(fichier,"\n\n------- Charge ponctuelles imposees : --------\n\n");
			    fprintf(fichier,"N \tPix \t\tPiy \t\tXpi\n");
			    int i=0;
			    for( i  ; i < nbChargementP ; i++)
			    fprintf(fichier,"%d \t%f \t%f \t%f\n", i+1,tableauChargement[i].Px,tableauChargement[i].Py,tableauChargement[i].Xp);break;
			   
			    
			    // On affiche les réactions d'appuis
			    fprintf(fichier,"\n\n------- Reaction d'appui : --------\n\n");
			    fprintf(fichier,"Ray \t\tRbx \t\tRby\n");
			    fprintf(fichier,"%f \t%f \t%f\n", Resultat_react_appui.Rya, Resultat_react_appui.Rxb, Resultat_react_appui.Ryb);
			case 2:
				fprintf(fichier,"Longueur de la poutre : %f m", L);
			    fprintf(fichier,"\n\n------- Charge lineaire imposee : --------\n\n");
			    fprintf(fichier," \tdebut \t\tfin \t\t valeur \n");
			    fprintf(fichier," \t %f \t %f \t %f \n",ch_repartie.Xdebut,ch_repartie.Xfin,ch_repartie.Qy);
				// resultat
				fprintf(fichier,"\n\n------- Reaction d'appui : --------\n\n");
			    fprintf(fichier,"Ray \t\tRbx \t\tRby\n");
			    fprintf(fichier,"%f \t%f \t%f\n", Resultat_react_appui.Rya, Resultat_react_appui.Rxb, Resultat_react_appui.Ryb);break;
			case 3:
				fprintf(fichier,"Longueur de la poutre : %f m", L);
			    fprintf(fichier,"\n\n------- Charge ponctuelles imposees : --------\n\n");
			    fprintf(fichier,"N \tPix \t\tPiy \t\tXpi\n");
			    i=0;
			    for( i  ; i < nbChargementP ; i++)
			    fprintf(fichier,"%d \t%f \t%f \t%f\n", i+1,tableauChargement[i].Px,tableauChargement[i].Py,tableauChargement[i].Xp);
			    
			    
			    fprintf(fichier,"\n\n------- Charge lineaire imposee : --------\n\n");
			    fprintf(fichier," \tdebut \t\tfin \t\t valeur \n");
			    fprintf(fichier," \t %f \t %f \t %f \n",ch_repartie.Xdebut,ch_repartie.Xfin,ch_repartie.Qy);
			    	// resultat
				fprintf(fichier,"\n\n------- Reaction d'appui : --------\n\n");
			    fprintf(fichier,"Ray \t\tRbx \t\tRby\n");
			    fprintf(fichier,"%f \t%f \t%f\n", Resultat_react_appui.Rya, Resultat_react_appui.Rxb, Resultat_react_appui.Ryb);break;
				
	
	}	
    fclose(fichier);
    } ;
}

void choix_2 (){
    printf("### Resolution de system isostatique compose d'une poutre reposant  sur 1 appuis ###\n\n");
	


}

void choix_3 (){
    printf("### Resolution de system isostatique Complexe compose d'un assemblage  de poutre isostatique ###\n\n");




}



void main(){
    char expression ;

    printf("######### \"Logiciel d’etude de poutre isostatique\" ##########\n\n");
    printf("Bonjour\n\n");
	printf("Choisissez le type de systeme que vous desirez resoudre :\n\n");
	printf("0  :  Quitter le programme :\n");
	printf("1  :  Resolution de system isostatique compose d'une poutre reposant  sur 2 appuis ( un appui double et un appui simple )\n");
	printf("2  :  Resolution de system isostatique compose d'une poutre reposant  sur 1 appuis un encastrement a gauche  et libre  a l'autre extremite\n");
	printf("3  :  Resolution de system isostatique Complexe compose d'un assemblage  de poutre isostatique\n\n");
    printf("Entrez votre choix:");
    expression=scanf_char();
    switch (expression)
{
    case '0':
      break;
    case '1':
      choix_1();
      break;
    case '2':
      choix_2();
      break;
    case '3':
      choix_3();
      break;
    default:
      break;
}
    printf("################## Fin de Calcule #####################\n\n");
    getchar();
	}

