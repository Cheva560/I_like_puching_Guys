#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main () { 

	int nHpPlayer=150;
	int nHpIa=150;
	int nAction=0;
	
	//for(int i = 0; condition de fonctionnement; i++){}
	
	for (int i = 0;i <= 70;i++){
		
		printf ("\n");
		
	}
	
	// OR = || 		AND = &&        NO = !
	//OR vérification des 2 valeurs
	//Conditions de défaite : dead Players or IA
	
	while(nHpIa >0 && nHpPlayer >0){
		
		nAction = 0;
		while(nAction != 1){
		
			printf ("Choose your actions\n");
			printf (" 1) Attack\n");
			
			//scanf ("%d", &nomVar); ==> l'utilisateur tape qqch dans la variable "maVar"
			scanf ("%d", &nAction);
		
		}
		
		//if(condition d'activation){}
		
		//Si (Players press 1 {alors nHpIa prend sa valeur actuelle -20 -=20}
		
		
		
		if (nAction == 1) {
			
			nHpIa-=50;
			printf("texte %d texte", nHpIa);
			
		}
		
		
	}






	
	return 0 ;
}
