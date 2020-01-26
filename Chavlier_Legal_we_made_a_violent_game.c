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
	
	struct Entity player = {200, 5, 0, 0};
	struct Entity IA = {200, 5, 0, 0};
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
		
		//The player takes damage from the poison if he is poisonned
		if(player.poison >= 1){
			
			// We reduce of 1 turn the duration of the poison
			player.poison -=1;
			//Then we apply the damage
			nRandom = rand()%11 + 10;
			player.HP -= nRandom;
			printf("The player takes %d damages from the poison.\n",nRandom);
			//If this is the last turn of the player's poison
			if(player.poison == 0){
				printf("You are no longer poisonned.\n");
			}
			
		}
		
		
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
		
		if (nAction == 1) {
			
			// Genere un nombre aléatoire entre 33 et 50
			nRandom = rand() % 18 + 33;
			
			// defense de IA 
			if(IA.defense == 1) {
				
				nRandom = nRandom/4;
				
				IA.HP-=nRandom;
				
				printf ("The player hits IA in his defense, he makes %d damages.\n", nRandom);
				
			}
			else if (IA.defense == 0) {
		
				IA.HP-=nRandom;
				
				printf("The player hits the IA, he makes %d damages.\n", nRandom);
				
			}
			
		}
		if (nAction == 2) {
			
			printf ("The player defends.\n");
			
			player.defense = 1;
			
		}
		
		
		//IA turn ---------------------------------------------------------------------------------------------
		
		//Ia defense renitialiser dans une valeur impossible
		IA.defense = 0;
		
		//We regenerate 1 MP per turn except if he is already at the maximum
		if(IA.MP < 5){
			IA.MP += 1;
		}
		//sert a initialiser le while
		nAction = -1;
		
		printf ("\n--IA Turn--\n");
		printf ("Hp restants DE IA = %d\n\n", IA.HP);
		
		// Le while sert ici a reroll l'action de l'IA si cette dernière vient a faire une action inutile comme utiliser l'antidote alors qu'elle n'est pas empoisonée de plus on ne rentre pas dans le tour de l'IA si elle est déja morte pour éviter qu'elle joue un tour en étant décédée ﾍ(￣▽￣*)ﾉ
		while(nAction == -1 && IA.HP >0){
			
			//IA choisi entre 0 et 3	
			nAction=rand()%4;
		
			//Attack
			if(nAction==0){
				
				// Genere un nombre aléatoire entre 35 et 45
				nRandom = rand() % 11 + 35;
				
				if (player.defense == 1) {
					
					nRandom = nRandom/4;
					
					player.HP-=nRandom;  
					
					printf ("The IA attacks the player in his defense and makes %d damages.\n", nRandom);
					
				}
				else if(player.defense == 0){
					
					printf ("The IA attacks the player and makes %d damages.\n", nRandom);
					
					player.HP-=nRandom;
					
					
				}
				
			}
			
			//defense IA
			if(nAction==1){
				
				printf ("The IA defends.\n");
				
				IA.defense = 1;
				
			}
			
			// Poison
			if(nAction == 2){
				
				// If the player is already poisonned, we reroll the action of the IA by putting -1 in nAction
				if(player.poison >= 1){
					
					nAction = -1;
					
				}
				else if(player.poison <= 0){
					
					// Poison the plyer for a number of turns between 2 and 5 ⊂(ô｡◎彡)
					nRandom = rand()%4 + 2;
					
					player.poison = nRandom;
					
					printf("The IA casts Poison. \nYou are now poisonned.\n");
					
				}
				
			}
			
			//Antidote
			if(nAction == 3){
				
				//We verify if the IA is poisonned to avoid him to cure himself while it is useless, we include the last turn of poison as a useless situation to cure ᕦ{ಠᗨರೃづ)
				if(IA.poison <= 1){
					
					//We reroll the action if the IA is not poisonned
					nAction = -1;
					
				}
				else if(IA.poison >= 2){
					
					IA.poison = 0;
					
					printf("The IA casts Cure.\nThe IA is no longer poisonned.\n");
					
				}
				
			}
		
		}
		
	}
	
	printf("\n\n\nEndgame\n\n\n");

	
	return 0 ;
}

