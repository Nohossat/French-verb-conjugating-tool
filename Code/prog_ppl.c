#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<stdlib.h>
#include"definition_fonction.h"
#include"definition_structure.h"
#include"definition_variable.h"
#include"fonctions_choix.h"
#include"fonctions_lecture.h"
#include"fonctions_radical.h"
#include"fonction_traitement_radical.h"
#include"fonctions_verbe.h" 
#include"fonction_conjugaison.h"
#include"fonctions_regles.h"   
#include"fonctions_conjugaison_possible.h" 
#include "affichage.h"
#include"formatage_algo.h"                     
           
          
//----------------------programme principal---------------//
           
int main () {  
    char reponse1[10];      
    int possible=0;        
              
    lecture_fichier_present_auxiliaire();    
    lecture_pronoms_personnels();       
    //construction du tableau de caractères tab_caractères_acc
    strcpy(tab_caractères_acc[0].word,"Â");
    strcpy(tab_caractères_acc[1].word,"â");
    strcpy(tab_caractères_acc[2].word,"É");
    strcpy(tab_caractères_acc[3].word,"é"); 
    strcpy(tab_caractères_acc[4].word,"È");
    strcpy(tab_caractères_acc[5].word,"è");       
    strcpy(tab_caractères_acc[6].word,"Î");
    strcpy(tab_caractères_acc[7].word,"î");
    strcpy(tab_caractères_acc[8].word,"Ï");   
    strcpy(tab_caractères_acc[9].word,"ï");
    strcpy(tab_caractères_acc[10].word,"Û");
    strcpy(tab_caractères_acc[11].word,"û");   
  
    
    printf("\n");
    printf("-------------------------BIENVENUE-------------------------\n");
    printf("\n");
    printf("---------------------CONJUGATOR 5000-----------------------\n");
    printf("          Apprenez à conjuguer les verbes français!!       \n");
    
    while (actif != 0) {
           
        choix_verbe();                 
        verif_verbe();                     
               
        while (trouve == 0) {                 
            printf("\n");
            printf("     ATTENTION !!! Le verbe %s n'existe pas!\n",verbe_saisi);
            choix_verbe();
            verif_verbe();
        }            
         
        if (trouve == -1) {  
            printf("\n");   
            printf("    Le verbe %s n'existe pas sous la forme pronominale. Voulez-vous le conjuguer sans pronom réfléchi? (o/n)\n",verbe_saisi);
            printf("Choix: ");
            
            scanf("%s",reponse1);
            reponse1[0] = tolower(reponse1[0]);  
            while ((reponse1[0]!= 'o') && (reponse1[0]!= 'n')) {
                    printf("\n");
                    printf("     Choix incorrect!\n");   
                    printf("   Choix:"); 
                    scanf("%s",reponse1);  
                    reponse1[0] = tolower(reponse1[0]);  
            }

            if (reponse1[0]=='o'){
                trouve = 1; 
                strcpy(verbe_saisi,verbe.verbe); 
                longueur_verbe = strlen(verbe.verbe);
                getchar();
            }
            else {  
                getchar();  
            }
        }
          
        if (trouve == 1) {                
            printf("\n");
            printf("           BRAVO!!! Le verbe %s existe.\n",verbe_saisi); 
            printf("\n");  
            choix_mode();    
            choix_temps();
            possible = conjugaison_possible_temps();
 
            if (possible == 1) {  
                trouve_radical();         
                trouve_ss_groupe();         
                conjugaison_verbe(); 
                affichage();
            }                       
         }                                                    
    }             
        printf(" ---------------------A bientôt----------------------\n");
    }
          
//FORMATAGE: minuscule...le mm principe que le sous groupe céder...

//TESTS SUR TOUS LES RADICAUX: voir au cas par cas, les bons radicaux