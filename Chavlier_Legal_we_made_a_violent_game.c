#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Entity {
	
	int HP;
	int MP;
	int defense;
	int poison;
	
};

int main () { 

	srand (time (NULL));
	
	struct Entity player = {150, 5, 0, 0};
	struct Entity IA = {150, 5, 0, 0};
	int nAction = 0;
	int nRandom = 0;
	
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
		player.defense = 0;
		
		
		while(nAction != 1 && nAction !=2){
			
			printf ("Hp restants = %d\n\n", player.HP);
			printf ("Choose your actions :\n\n");
			printf (" 1) Attack\n");
			printf (" 2) Defense\n");
			
			//scanf ("%d", &nomVar); ==> l'utilisateur tape qqch dans la variable "maVar"
			scanf ("%d", &nAction);
			printf("\n");
			
		
		}
		
		//if(condition d'activation){}
		
		//Si (Players press 1 {alors nHpIa prend sa valeur actuelle -20 -=20}
		
		// defense de IA 
		
		if (nAction == 1) {
			
			// Genere un nombre aléatoire entre 33 et 50
			nRandom = rand() % 18 + 33;
			
			
			if(IA.defense == 1) {
				
				nRandom = nRandom/4;
				
				IA.HP-=nRandom;
				
				printf ("The player hits IA in his defense, he makes %d damages\n", nRandom);
				
			}
			else if (IA.defense == 0) {
		
				IA.HP-=nRandom;
				
				printf("The player hits the IA, he makes %d damages\n", nRandom);
				
			}
			
		}
		if (nAction == 2) {
			
			printf ("The player defends\n");
			
			player.defense = 1;
			
		}
		
		
		//IA turn ---------------------------------------------------------------------------------------------
		
		//Ia defense renitialiser dans une valeur impossible
		
		IA.defense = 0;
		
		//sert a initialiser le while
		nAction = -1;
		
		// Le while sert ici a reroll l'action de l'IA si cette dernière vient a faire une action inutile comme utiliser l'antidote alors qu'elle n'est pas empoisonée de plus on ne rentre pas dans le tour de l'IA si elle est déja morte pour éviter qu'elle joue un tour en étant décédée ﾍ(￣▽￣*)ﾉ
		while(nAction == -1 && IA.HP >0){
			
			//IA choisi entre 0 et 1	
			nAction=rand()%2;
			
			printf ("\n--IA Turn--\n");
			printf ("Hp restants DE IA = %d\n", IA.HP);
		
			//Attack
			if(nAction==0){
				
				// Genere un nombre aléatoire entre 35 et 45
				nRandom = rand() % 11 + 35;
				
				if (player.defense == 1) {
					
					nRandom = nRandom/4;
					
					player.HP-=nRandom;  
					
					printf ("The IA attacks the player in his defense and makes %d damages\n", nRandom);
					
				}
				else if(player.defense == 0){
					
					printf ("The IA attacks the player and makes %d damages\n", nRandom);
					
					player.HP-=nRandom;
					
					
				}
				
			}
			
			//defense IA
			if(nAction==1){
				
				printf ("Defense IA\n");
				
				IA.defense = 1;
				
			}
		
		}
		
	}
	
	printf("\n\n\nendgame");

	
	return 0 ;
}

