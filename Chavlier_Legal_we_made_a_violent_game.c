#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Entity {
	
	int HP;
	int MP;
	int defense;
	int poison;
	int MPmax;
	
};

int main () { 

	srand (time (NULL));
	
	struct Entity player[3] = {200, 5, 0, 0, 5,      0, 0, 0, 0, 0,       0, 0, 0, 0, 0};
	
	struct Entity IA[3] = {50, 5, 0, 0, 5,      50, 0, 0, 0, 5,       50, 0, 0, 0, 5};
	
	int nAction = 0;
	int nAim = -1;
	int nRandom = 0;
	
	
	//for(int i = 0; condition de fonctionnement; i++){}
	
	for (int i = 0;i <= 70;i++){
		
		printf ("\n");
		
	}
	
	// OR = || 		AND = &&        NO = !
	//OR vérification des 2 valeurs.
	
	
	//Tant que l'un des deux ensembles contient au moins une entité en vie, alors, la partie continue
	while((IA[0].HP >0 || IA[1].HP > 0 || IA[2].HP > 0) && (player[0].HP >0 || player[1].HP > 0 || player[2].HP > 0)){
		
		
		
		
		// player turn ---------------------------------------------------------------------------------
		if(player[0].HP > 0){
			printf ("\n---------------------------------------Player Turn  (*^-^*)\n\n");
		}
		
		// regénaration des MP
		if(player[0].MP < player[0].MPmax){
		   player[0].MP += 1;
		}	
		
		nAction = 0; 
		nAim = -1;
		player[0].defense = 0;
		
		//IA prend dégats poison
		if(player[0].poison >= 1){
			
			// -1 turn poison
			player[0].poison -=1;
			//application dégats poison
			nRandom = rand()%11 + 15;
			player[0].HP -= nRandom;
			printf("The player takes %d damages from the poison.\n",nRandom);
			
			//Derniere turn poison
			if(player[0].poison == 0){
				printf("player is no longer poisonned.\n");
			}
			
		}
		
		//We let the player play only if he is still alive ಠ◡ಠ
		if(player[0].HP > 0){
			
			while(nAction != 1 && nAction != 2 && nAction !=3 && nAction !=4){
			
				printf ("Hp restants = %d\n\n", player[0].HP);
				printf ("Choose your actions :\n\n");
				printf (" 1) Attack\n");
				printf (" 2) Defense\n");
				printf (" 3) Poison\n");
				printf (" 4) Cure\n");
			
				//scanf ("%d", &nomVar); ==> l'utilisateur tape qqch dans la variable "maVar"
				scanf ("%d", &nAction);
				printf("\n");
			
			}
			
			//if(condition d'activation){}
			
			if (nAction == 1) {
				
				//Choosing the aim
				while(nAim != 0 && nAim != 1 && nAim != 2){
					
					printf("Who will you be aiming at?\n");
					scanf("%d", &nAim);
					nAim -= 1;
					
				}
			
				// Genere un nombre aléatoire entre 33 et 50
				nRandom = rand() % 18 + 33;
			
				// defense de IA 
				if(IA[nAim].defense == 1) {
				
					nRandom = nRandom/4;
				
					IA[nAim].HP-=nRandom;
				
					printf ("The player hits IA in his defense, he makes %d damages.\n", nRandom);
					
				}
				else if (IA[nAim].defense == 0) {
		
					IA[nAim].HP-=nRandom;
				
					printf("The player hits the IA, he makes %d damages.\n", nRandom);
				
				}
			
			}
			
			if (nAction == 2) {
			
				printf ("The player defends.\n");
			
				player[0].defense = 1;
			
			}
		
			// Poison
			if(nAction == 3) {
				
				//Choosing the aim
				while(nAim != 0 && nAim != 1 && nAim != 2){
					
					printf("Who will you be aiming at?\n");
					scanf("%d", &nAim);
					nAim -= 1;
					
				}
				
				printf("The player casts Poison...\n");
			
				if(player[0].MP >= 5){
					
					printf("The IA is now poisonned\n");
					
					nRandom = rand()%6 + 2;
				
					IA[nAim].poison = nRandom;
					
					player[0].MP -=5;
					
				}
				// pas de MP pas de sort
				else if(player[0].MP < 5){
					
					printf("But the player has not enough MP...\n");
					
				}
			}
			
			// Antidote 
			if (nAction == 4){
				
				printf("The player casts Cure...\n");
			
				if(player[0].MP >= 2){
				
					player[0].MP -= 2;
			
					//vérifie statut du poison du player
					if(player[0].poison <= 0){
				
						printf("But it was useless.\n");
				
					}
					else if(player[0].poison >= 1){
			
						player[0].poison = 0;
				
						printf("You Cure.\nYou are no longer poisonned.\n");
					
					}
				
				}	
				//pas de MP pas d'antidote
				else if(player[0].MP < 2){
				
					printf("But the player has not enough MP...\n");
				
				}
		
			}
			
		}			
		
		
		
		
		
		
		
		if((IA[0].HP >0 || IA[1].HP > 0 || IA[2].HP > 0) && (player[0].HP >0 || player[1].HP > 0 || player[2].HP > 0)){
			//IA turn ---------------------------------------------------------------------------------------------
			
			printf ("\n-----------------------------------------------IA Turn    (>_<)\n");
			
			
			
			for(int i = 0; i<3; i++){
				
				if(IA[i].HP > 0){  
					printf("\n --- IA %d turn ---\n",i+1);
				}
			
				//Ia defense renitialiser dans une valeur impossible
				IA[i].defense = 0;
				
				//The player takes damage from the poison if he is poisonned
				if(IA[i].poison >= 1 && IA[i] > 0){
					
					// reduction 1 turn poison
					IA[i].poison -=1;
					//apply poison damage
					nRandom = rand()%11 + 10;
					IA[i].HP -= nRandom;
					printf("IA takes %d damages from the poison.\n",nRandom);
					
					if(IA[i].poison == 0){
						printf("IA are no longer poisonned.\n");
					}
					
				}
				
				
				//We regenerate 1 MP per turn except if he is already at the maximum
				if(IA[i].MP < IA[i].MPmax){
					IA[i].MP += 1;
				}
				//sert a initialiser le while
				nAction = -1;
				
				if(IA[i].HP > 0){
					printf ("MP restants DE IA = %d\n", IA[i].MP);
					printf ("Hp restants DE IA = %d\n\n", IA[i].HP);
				}
				
				// Le while sert ici a reroll l'action de l'IA si cette dernière vient a faire une action inutile comme utiliser l'antidote alors qu'elle n'est pas empoisonée de plus on ne rentre pas dans le tour de l'IA si elle est déja morte pour éviter qu'elle joue un tour en étant décédée ﾍ(￣▽￣*)ﾉ
				while(nAction == -1 && IA[i].HP >0){
					
					//IA choisi entre 0 et 3	
					nAction=rand()%4;
				
					//Attack IA
					if(nAction==0){
						
						// Genere un nombre aléatoire entre 35 et 45
						nRandom = rand() % 11 + 35;
						
						if (player[0].defense == 1) {
							
							nRandom = nRandom/4;
							
							player[0].HP-=nRandom;  
							
							printf ("The IA attacks the player in his defense and makes %d damages.\n", nRandom);
							
						}
						else if(player[0].defense == 0){
							
							printf ("The IA attacks the player and makes %d damages.\n", nRandom);
							
							player[0].HP-=nRandom;
							
							
							
						}
						
					}
					
					//defense IA
					if(nAction==1){
						
						printf ("The IA defends.\n");
						
						IA[i].defense = 1;
						
					}
					
					// Poison
					if(nAction == 2){
						
						//If the IA does not have enough MP it will reroll the action
						if(IA[i].MP >= 5){
						
							// If the player is already poisonned, we reroll the action of the IA by putting -1 in nAction
							if(player[0].poison >= 1){
								
								nAction = -1;
								
							}
							else if(player[0].poison <= 0){
								
								//We remove 5 MP from the IA
								IA[i].MP -= 5;
								
								// Poison the plyer for a number of turns between 2 and 5 ⊂(ô｡◎彡)
								nRandom = rand()%4 + 2;
								
								player[0].poison = nRandom;
								
								printf("The IA casts Poison. \nYou are now poisonned.\n");
								
							}
						
						}
						else if(IA[i].MP < 5){
							nAction = -1;
						}
						
					}
					
					//Antidote
					if(nAction == 3){
						
						//We verify if the IA have enough MP to cast Cure
						if(IA[i].MP >= 2){
							
							//We verify if the IA is poisonned to avoid him to cure himself while it is useless, we include the last turn of poison as a useless situation to cure ᕦ{ಠᗨರೃづ)
							if(IA[i].poison <= 1){
								
								//We reroll the action if the IA is not poisonned
								nAction = -1;
								
							}
							else if(IA[i].poison >= 2){
								
								IA[i].poison = 0;
								
								printf("The IA casts Cure.\nThe IA is no longer poisonned.\n");
								
							}
						
						}
						else if(IA[i].MP < 2){
							nAction = -1;
						}
						
					}
				
				}
				
			}
		
		}
	
	}
	
	printf("\n\n\nEndgame\n\n\n");

	
	return 0 ;
}

