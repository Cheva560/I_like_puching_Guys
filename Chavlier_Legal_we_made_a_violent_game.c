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
		if(player.HP > 0){
			printf ("\n--Player Turn--\n\n");
		}
		// regénaration des MP
		if(player.MP < 5){
		   player.MP += 1;
		}	
			
		nAction = 0; 
		player.defense = 0;
		
		//IA prend dégats poison
		if(IA.poison >= 1){
			
			// -1 turn poison
			IA.poison -=1;
			//application dégats poison
			nRandom = rand()%11 + 10;
			IA.HP -= nRandom;
			printf("The player takes %d damages from the poison.\n",nRandom);
			
			//Derniere turn poison
			if(player.poison == 0){
				printf("IA are no longer poisonned.\n");
			}
			
		}
		
		nAction == -2
		
		//We let the player play only if he is still alive ಠ◡ಠ
		if(player.HP > 0){
			
			while(nAction!=-2){
			
				while(nAction != 1 && nAction != 2 && nAction !=3 && nAction !=4){
				
					printf ("Hp restants = %d\n\n", player.HP);
					printf ("Choose your actions :\n\n");
					printf (" 1) Attack\n");
					printf (" 2) Defense\n");
					printf (" 3) Poison\n");
					printf (" 4) Antidote\n");
				
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
					
				// Poison
				if(nAction == 3) {
					
					printf("tets1/n");
				
					//reroll turn of Player not if have MP
					if(player.MP >= 5){
						
						printf("tets2/n");
						
					
						// -1 recommence le turn si IA et déja empoisonée
						if(IA.poison >= 1){
							
							printf("tets3/n");
						
							nAction = -2;
						
						}
					}
					// pas empoisonée =  poison 
					else if(IA.poison <= 0){
						
						printf("tets4/n");
						
						player.MP -= 5;
						
						
						nRandom = rand()%4 + 2;
						
						IA.poison = nRandom;
						
						printf("you casts Poison. \n IA et empoisonée.\n");
						
					}
					// pas de MP pas de sort
					else if(player.MP < 5){
						nAction = -2;
						
					}
				}
				
					// Antidote 
					if (nAction == 4){
						
					
						if(player.MP >= 2){
					
						//vérifie statut du poison du player
							if(player.poison <= 1){
						
								//reroll turn if a player n'est pas empoisonnée 
								nAction = -2;
						
							}
								
								else if(player.poison >= 1){
						
								player.poison = 0;
						
								printf("You Cure.\nYou not poisonned.\n");
								
								}
						
						}	
						
					
				
					//pas de MP pas d'antidote
					
						else if(player.MP < 2){
						
							nAction = -2;
						
						}
							
					}
			
			}
		}			
		
		
			
			
		
		
		
		
		
		
		//IA turn ---------------------------------------------------------------------------------------------
		
		//Ia defense renitialiser dans une valeur impossible
		IA.defense = 0;
		
		//The player takes damage from the poison if he is poisonned
		if(IA.poison >= 1){
			
			// reduction 1 turn poison
			IA.poison -=1;
			//apply dégats poison
			nRandom = rand()%11 + 10;
			IA.HP -= nRandom;
			printf("IA takes %d damages from the poison.\n",nRandom);
			
			if(IA.poison == 0){
				printf("IA are no longer poisonned.\n");
			}
			
		}
		
		if(IA.poison >= 1){
			
			// We reduce of 1 turn the duration of the poison
			IA.poison -=1;
			
			//Then we apply the damage
			
			nRandom = rand()%11 + 10;
			IA.HP -= nRandom;
			printf("The IA takes %d damages from the poison.\n",nRandom);
			
			//If this is the last turn of the player's poison
			
			if(IA.poison == 0){
				printf("IA are no longer poisonned.\n");
			}
		}
		//We regenerate 1 MP per turn except if he is already at the maximum
		if(IA.MP < 5){
			IA.MP += 1;
		}
		//sert a initialiser le while
		nAction = -1;
		
		if(IA.HP > 0){
			printf ("\n--IA Turn--\n");
			//I display this line just for information to the developers, it will be deleted for the final version
			printf ("MP of IA = %d\n",IA.MP);
			printf ("Hp restants DE IA = %d\n\n", IA.HP);
		}
		
		// Le while sert ici a reroll l'action de l'IA si cette dernière vient a faire une action inutile comme utiliser l'antidote alors qu'elle n'est pas empoisonée de plus on ne rentre pas dans le tour de l'IA si elle est déja morte pour éviter qu'elle joue un tour en étant décédée ﾍ(￣▽￣*)ﾉ
		while(nAction == -1 && IA.HP >0){
			
			//IA choisi entre 0 et 3	
			nAction=rand()%4;
		
			//Attack IA
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
				
				//If the IA does not have enough MP it will reroll the action
				if(IA.MP >= 5){
				
					// If the player is already poisonned, we reroll the action of the IA by putting -1 in nAction
					if(player.poison >= 1){
						
						nAction = -1;
						
					}
					else if(player.poison <= 0){
						
						//We remove 5 MP from the IA
						IA.MP -= 5;
						
						// Poison the plyer for a number of turns between 2 and 5 ⊂(ô｡◎彡)
						nRandom = rand()%4 + 2;
						
						player.poison = nRandom;
						
						printf("The IA casts Poison. \nYou are now poisonned.\n");
						
					}
				
				}
				else if(IA.MP < 5){
					nAction = -1;
				}
				
			}
			
			//Antidote
			if(nAction == 3){
				
				//We verify if the IA have enough MP to cast Cure
				if(IA.MP >= 2){
					
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
				else if(IA.MP < 2){
					nAction = -1;
				}
				
			}
		
		}
		
	
	
	}
	
	printf("\n\n\nEndgame\n\n\n");

	
	return 0 ;
}

