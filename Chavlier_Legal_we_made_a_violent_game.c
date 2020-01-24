#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Entity {
	
	int HP;
	int MP;
	int defense;
	int poison;
	
}

int main () { 


	struct Entity player = {150, 5, 0, 0};
	struct Entity IA = {150, 5, 0, 0};
	int nAction = 0;
	
	//for(int i = 0; condition de fonctionnement; i++){}
	
	for (int i = 0;i <= 70;i++){
		
		printf ("\n");
		
	}
	
	// OR = || 		AND = &&        NO = !
	//OR vérification des 2 valeurs.
	//Conditions de défaite : dead Players or IA.
	
	while(IA.HP >0 && player.HP >0){
		
		// player turn ---------------------------------------------------------------------------------
		printf ("\n--Player Turn--\n\n");
		nAction = 0; 
		nDefense = 0;
		
		while(nAction != 1 && nAction !=2){
			
			printf ("Hp restant = %d\n", player.HP);
			printf ("Choose your actions :\n\n");
			printf (" 1) Attack\n");
			printf (" 2) Defense\n");
			
			//scanf ("%d", &nomVar); ==> l'utilisateur tape qqch dans la variable "maVar"
			scanf ("%d", &nAction);
			
		
		}
		
		//if(condition d'activation){}
		
		//Si (Players press 1 {alors nHpIa prend sa valeur actuelle -20 -=20}
		
		
		
		if (nAction == 1) {
			
			IA.HP-=50;
			printf ("Attack Player\n");
			
			
	
		}
		if (nAction == 2) {
			
			printf ("Defense Player\n");
			
			player.defense = 1;
			
		}
		
		
		//IA turn ---------------------------------------------------------------------------------------------
		printf ("IA Turn\n");

	
		
		if (player.defense == 1) {
			
			printf ("Attack in defense IA\n");
			
			player.HP-=40/4;  
			
			
		}
		else {
			
			printf ("Attack IA\n");
			
			player.HP-=40;
			
			
		}
	}






	
	return 0 ;
}
