#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Entity {
	
	int HP;
	int MP;
	int defense;
	int poison;
	int MPmax;
	int XP;
	int lvl;
	
	
};

int main () { 

	int nEndgame = 0;
	
	struct Entity playerMemory[3] = {250, 3, 0, 0, 5, 0, 0,      180, 6, 0, 0, 10, 0, 0,       200, 5, 0, 0, 7, 0, 0};
	
	while(nEndgame == 0){

		srand (time (NULL));
		int IAHP = 100;
		int nAction = 0;
		int nDifficulty = 0;
		
		while(nDifficulty != 1 && nDifficulty != 2 && nDifficulty != 3 && nDifficulty != 4 && nDifficulty != 666){
			
			//choix diffilculté
			printf ("Choose your actions :\n\n");
			printf (" 1) EASY\n");
			printf (" 2) NORMAL\n");
			printf (" 3) HARD\n");
			printf (" 4) SATAN\n");

			
			scanf ("%d", &nDifficulty);
			printf("\n");
		
		}
		if (nDifficulty == 1){

			IAHP = 150; 
		
			printf ("Hp IA= %d\n\n", IAHP);
		}
		
		if (nDifficulty == 2){
			
			IAHP = 200;
			
			printf ("Hp IA = %d\n\n", IAHP);
		}
		
		if (nDifficulty == 3){
			
			IAHP = 300; 
			
			printf ("Hp IA = %d\n\n", IAHP);
		}
		
		if (nDifficulty == 4){
		
			IAHP = 400;
			
			printf ("Hp IA = %d\n\n", IAHP);

		}
		
		
		//test chuuuuut
		if (nDifficulty == 666){


			IAHP = 10; 
		
			
		}
		
		

		struct Entity player[3] = {playerMemory[0].HP, playerMemory[0].MP, 0, 0, playerMemory[0].MPmax,0, 0,     playerMemory[1].HP, playerMemory[1].MP, 0, 0, playerMemory[1].MPmax,0, 0,       playerMemory[2].HP, playerMemory[2].MP, 0, 0, playerMemory[2].MPmax,0, 0};
		
		struct Entity IA[3] = {IAHP, 4, 0, 0, 7,      IAHP, 3, 0, 0, 10,       IAHP, 5, 0, 0, 5};
		
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
			if(player[0].HP >0 || player[1].HP > 0 || player[2].HP > 0){
				printf ("\n-------------------------------------------Player Turn  (*^-^*)\n");
			}
			
			for(int i = 0; i<3; i ++){
				
				if (player[i].HP > 0){
					printf("\n --- player %d ---\n",i+1);
				}
				else if(player[i].HP <= 0){
					printf("\n -- The player %d is dead --\n", i+1);
				}
				
				// regénaration des MP
				if(player[i].MP < player[i].MPmax){
				   player[i].MP += 1;
				}	
				
				nAction = 0; 
				nAim = -1;
				player[i].defense = 0;
				
				//IA prend dégats poison
				if(player[i].poison >= 1 && player[i].HP > 0){
					
					// -1 turn poison
					player[i].poison -=1;
					//application dégats poison
					nRandom = rand()%11 + 15;
					player[i].HP -= nRandom;
					printf("The player %d takes %d damages from the poison.\n", i+1, nRandom);
					
					//Derniere turn poison
					if(player[i].poison == 0){
						printf("player %d is no longer poisonned.\n",i+1);
					}
					
				}
				
				//We let the player play only if he is still alive ಠ◡ಠ
				if(player[i].HP > 0 && (IA[0].HP >0 || IA[1].HP > 0 || IA[2].HP > 0)){
					
					while(nAction != 1 && nAction != 2 && nAction !=3 && nAction !=4){
					
						printf ("HP left = %d\n", player[i].HP);
						printf ("MP left = %d\n\n", player[i].MP);
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
						
							printf ("The player %d hits IA %d in his defense, he makes %d damages.\n", i+1, nAim+1, nRandom);
							
						}
						else if (IA[nAim].defense == 0) {
				
							IA[nAim].HP-=nRandom;
						
							printf("The player %d hits the IA %d, he makes %d damages.\n", i+1, nAim+1, nRandom);
						
						}
					
					}
					
					if (nAction == 2) {
					
						printf ("The player %d defends.\n", i+1);
					
						player[i].defense = 1;
					
					}
				
					// Poison
					if(nAction == 3) {
						
						//Choosing the aim
						while(nAim != 0 && nAim != 1 && nAim != 2){
							
							printf("Who will you be aiming at?\n");
							scanf("%d", &nAim);
							nAim -= 1;
							
						}
						
						printf("The player %d casts Poison...\n", i+1);
					
						if(player[i].MP >= 5){
							
							printf("The IA %d is now poisonned\n", nAim+1);
							
							nRandom = rand()%6 + 2;
						
							IA[nAim].poison = nRandom;
							
							player[i].MP -=5;
							
						}
						// pas de MP pas de sort
						else if(player[i].MP < 5){
							
							printf("But the player %d has not enough MP...\n", i+1);
							
						}
					}
					
					// Antidote 
					if (nAction == 4){
						
						printf("The player %d casts Cure...\n", i+1);
					
						if(player[i].MP >= 2){
						
							player[i].MP -= 2;
					
							//vérifie statut du poison du player
							if(player[i].poison <= 0){
						
								printf("But it was useless.\n");
						
							}
							else if(player[i].poison >= 1){
					
								player[i].poison = 0;
						
								printf("The player %d is no longer poisonned!", i+1);
							
							}
						
						}	
						//pas de MP pas d'antidote
						else if(player[i].MP < 2){
						
							printf("But the player %d has not enough MP...\n", i+1);
						
						}
				
					}
					
				}
				
				if (nAction == 5){
				
					if (player[i].MP >= 2){
						
						player[i].MP -=2;
				
						nRandom =rand()%31+30 ;
						
						player[i].HP += nRandom;    

						printf("Players Heal HP up of %d\n\n", nRandom );
						
					}
				
				
				else if(player[i].MP < 5){
						
						printf("But the player has not enough MP...\n\n");
						
					}
				}
			}			
			
			
			
			
			
			
			
			//IA turn ---------------------------------------------------------------------------------------------
			if((IA[0].HP >0 || IA[1].HP > 0 || IA[2].HP > 0) && (player[0].HP >0 || player[1].HP > 0 || player[2].HP > 0)){
				
				printf ("\n-----------------------------------------------IA Turn    (>_<)\n");

			
				//sert a initialiser le while
				nAction = -1;{
					
					for(int i = 0; i<3; i++){
						
						if(IA[i].HP > 0){  
							printf("\n --- IA %d turn ---\n",i+1);
						}
						else{
							printf("\n -- The IA %d is dead --\n",i+1);
						}
					
						//Ia defense renitialiser dans une valeur impossible
						IA[i].defense = 0;
						
						//The player takes damage from the poison if he is poisonned
						if(IA[i].poison >= 1 && IA[i].HP > 0){
							
							// reduction 1 turn poison
							IA[i].poison -=1;
							//apply poison damage
							nRandom = rand()%11 + 10;
							IA[i].HP -= nRandom;
							printf("IA %d takes %d damages from the poison.\n", i+1, nRandom);
							
							if(IA[i].poison == 0){
								printf("IA %d is no longer poisonned.\n", i+1);
							}
							
						}
						
						
						//We regenerate 1 MP per turn except if he is already at the maximum
						if(IA[i].MP < IA[i].MPmax){
							IA[i].MP += 1;
						}
						//sert a initialiser le while
						nAction = -1;
						
						if(IA[i].HP > 0){
							printf ("HP left of IA %d = %d\n\n", i+1, IA[i].HP);
						}
						
						// Le while sert ici a reroll l'action de l'IA si cette dernière vient a faire une action inutile comme utiliser l'antidote alors qu'elle n'est pas empoisonée de plus on ne rentre pas dans le tour de l'IA si elle est déja morte pour éviter qu'elle joue un tour en étant décédée ﾍ(￣▽￣*)ﾉ
						while(nAction == -1 && IA[i].HP >0){
							
							//IA choisi entre 0 et 3	
							nAction=rand()%4;
							nAim = rand()%3;
						
							//Attack IA
							if(nAction==0 && player[nAim].HP > 0){
								
								// Genere un nombre aléatoire entre 35 et 45
								nRandom = rand() % 11 + 35;
								
								if (player[nAim].defense == 1) {
									
									nRandom = nRandom/4;
									
									player[nAim].HP-=nRandom;  
									
									printf ("The IA %d attacks the player %d in his defense and makes %d damages.\n", i+1, nAim+1, nRandom);
									
								}
								else if(player[nAim].defense == 0){
									
									printf ("The IA %d attacks the player %d and makes %d damages.\n", i+1, nAim+1, nRandom);
									
									player[nAim].HP-=nRandom;
									
									
									
								}
								
							}
							else if ( player[nAim].HP <= 0 ){
								nAction = -1;
							}
							
							//defense IA
							if(nAction==1){
								
								printf ("The IA %d defends.\n", i+1);
								
								IA[i].defense = 1;
								
							}
							
							// Poison
							if(nAction == 2 && player[nAim].HP > 0){
								
								//If the IA does not have enough MP it will reroll the action
								if(IA[i].MP >= 5){
								
									// If the player is already poisonned, we reroll the action of the IA by putting -1 in nAction
									if(player[nAim].poison >= 1){
										
										nAction = -1;
										
									}
									else if(player[nAim].poison <= 0){
										
										//We remove 5 MP from the IA
										IA[i].MP -= 5;
										
										// Poison the plyer for a number of turns between 2 and 5 ⊂(ô｡◎彡)
										nRandom = rand()%4 + 2;
										
										player[nAim].poison = nRandom;
										
										
										printf("The IA %d casts Poison. \nThe player %d is now poisonned.\n", i+1, nAim+1);
										
									}
								
								}
								else if(IA[i].MP < 5 || player[nAim].HP <= 0){
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
										
										printf("The IA %d casts Cure.\nThe IA %d is no longer poisonned.\n", i+1, i+1);
										
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
		
		}
		
		
		// Qui gagne qui perd 
		
		//Si les HP de IA est a 0 le players gagne
		if(IA[0].HP <=0 && IA[1].HP <= 0 && IA[2].HP <= 0){
			
			printf ("\n\n\n YOU WIN\n\n\n");
			
			// player [0][1][2] doivent gagner par rappoet a valeur de nDifficulty + random 
			
			//quand xp atteint une certaine valeurs alors lvl + 1
			
			
		}
		//Si les palyer.HP est a 0 players perd
		if(player[0].HP <0 && player[1].HP < 0 && player[2].HP < 0){
			
			printf ("\n\n\n YOU LOSE\n\n\n");
			
			
			
		}
	
		printf("\n                 If you want to play again type 1 else type 0 :\n");
		
		nEndgame = 2;
		while (nEndgame !=0 && nEndgame != 1){
			scanf("%d",&nEndgame);
		}
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	}
	
	return 0 ;
}

