 void affichage () {
  int j=0;
  int i=0;
  char reponse[5];
  int impossible=0;


printf("\n"); 
        printf("--------------Table de conjugaison du verbe %s--------------\n",verbe_saisi);
        printf("\n");
        printf("  Mode: %s\n",mode_string);
        printf("  Temps: %s\n",temps_string);
        printf("\n");
        
      
     
        switch(mode){
        case 0:
         //infinitif - RAS
        
            if (temps % 2 == 0) { //present
                printf("  %s\n",verbe_saisi);
            }
            else {//passe
                if (reflechi == 1) {
                    printf("  s'%s %s\n",verbe.aux,tab_conjugue[0].verbe);
                }
                else {
                    printf("  %s %s\n",verbe.aux,tab_conjugue[0].verbe);
                }
            }
        break;
        case 1: case 6:
         //indicatif et conditionnel
            j=0;
            for (i=0;i<6;i++) {
                 // affectation des pronoms perso que selon les temps simples
                if (reflechi==0) {
                    if (i != 0) {
                        strcpy(tab_conjugue[i].pronom, pronoms_personnels[i].pronom);
                    } 
                    else {
                        if (temps %2 == 0){//simple
                            if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                            strcpy(tab_conjugue[0].pronom, "j'");
                            }
                            else {
                                strcpy(tab_conjugue[0].pronom, pronoms_personnels[0].pronom);
                            }
                        }
                        else {//composé
                            if (tab_conjugue[i].auxiliaire[0] == 'a' || tab_conjugue[i].auxiliaire[0] == 'e' || tab_conjugue[i].auxiliaire[0] == 'o' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'y') {
                            strcpy(tab_conjugue[0].pronom, "j'");
                            }
                            else {
                                strcpy(tab_conjugue[0].pronom, pronoms_personnels[0].pronom);
                            }
                        }
                    }
                }
                else {// si reflechi
                    strcpy(tab_conjugue[i].pronom, pronoms_personnels[i].pronom);
                    if (temps % 2 == 0) {//simple
                        if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                        strcpy(tab_conjugue[i].pronom_reflechi, pronominal[0][i].word);
                        }
                    else {
                        strcpy(tab_conjugue[i].pronom_reflechi, pronominal[1][i].word);
                    }
                }
                    else {//composé
                        if (tab_conjugue[i].auxiliaire[0] == 'a' || tab_conjugue[i].auxiliaire[0] == 'e' || tab_conjugue[i].auxiliaire[0] == 'o' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'y') {
                            if (i==1) {
                                strcpy(tab_conjugue[i].pronom_reflechi, "t'");
                            }
                            else if (i==2) {
                                strcpy(tab_conjugue[i].pronom_reflechi, "s'");
                            }
                            else {
                                 strcpy(tab_conjugue[i].pronom_reflechi, pronominal[1][i].word);
                            }
                        }
                        else {
                            strcpy(tab_conjugue[i].pronom_reflechi, pronominal[1][i].word);
                        }
                    }   
                }
                //affichage selon le pronom réfléchi et si le temps est simple ou composé
                if ((reflechi == 0) && (temps % 2 == 0)){
                    printf("  |%s %s\n",tab_conjugue[i].pronom,tab_conjugue[i].verbe);
                }
                else if ((reflechi == 1) && (temps % 2 == 0)){
                    printf("  |%s %s %s\n",tab_conjugue[i].pronom, tab_conjugue[i].pronom_reflechi,tab_conjugue[i].verbe);
                }
                else if ((reflechi == 1) && (temps % 2 != 0)){
                    printf("  |%s %s %s %s\n",tab_conjugue[i].pronom, tab_conjugue[i].pronom_reflechi,tab_conjugue[i].auxiliaire, tab_conjugue[i].verbe);
                }
                else {
                    printf("  |%s %s %s\n",tab_conjugue[i].pronom,tab_conjugue[i].auxiliaire, tab_conjugue[i].verbe);
                }
            }
        break;
         case 2: //subjonctif
         j=0;
            for (i=0;i<6;i++) {
                if (i==2 || i==5){
                     strcpy(tab_conjugue[i].conjonction, "qu'");
                }
                else {
                    strcpy(tab_conjugue[i].conjonction, "que");
                }
                
                if (reflechi==0) {
                if (i != 0) {
                    strcpy(tab_conjugue[i].pronom, pronoms_personnels[i].pronom);
                } 
                else {
                    if (temps %2 == 0){//simple
                        if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                            strcpy(tab_conjugue[0].pronom, "j'");
                        }
                        else {
                            strcpy(tab_conjugue[0].pronom, pronoms_personnels[0].pronom);
                        }
                    }
                    else {//composé
                        if (tab_conjugue[i].auxiliaire[0] == 'a' || tab_conjugue[i].auxiliaire[0] == 'e' || tab_conjugue[i].auxiliaire[0] == 'o' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'y') {
                            strcpy(tab_conjugue[0].pronom, "j'");
                        }
                        else {
                            strcpy(tab_conjugue[0].pronom, pronoms_personnels[0].pronom);
                        }
                    }    
                }
            }
            else {// si reflechi
                    strcpy(tab_conjugue[i].pronom, pronoms_personnels[i].pronom);
                    if(temps %2==0) {//simple
                        if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                        strcpy(tab_conjugue[i].pronom_reflechi, pronominal[0][i].word);
                        }
                        else {
                            strcpy(tab_conjugue[i].pronom_reflechi, pronominal[1][i].word);
                        }    
                    }
                else {//composé
                    if (tab_conjugue[i].auxiliaire[0] == 'a' || tab_conjugue[i].auxiliaire[0] == 'e' || tab_conjugue[i].auxiliaire[0] == 'o' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'i' || tab_conjugue[i].auxiliaire[0] == 'y') {
                           
                                 strcpy(tab_conjugue[i].pronom_reflechi, pronominal[1][i].word);
                    }
                    else {
                        strcpy(tab_conjugue[i].pronom_reflechi, pronominal[1][i].word);
                    }   
               }
           }
                //affichage
                if (reflechi == 0 && (temps % 2 == 0)){
                    printf("  |%s %s %s\n",tab_conjugue[i].conjonction,tab_conjugue[i].pronom,tab_conjugue[i].verbe);
                }
                else if (reflechi == 1 && (temps % 2 == 0)){
                    printf("  |%s %s %s %s\n",tab_conjugue[i].conjonction, tab_conjugue[i].pronom, tab_conjugue[i].pronom_reflechi,tab_conjugue[i].verbe);
                }
                else if (reflechi == 1 && (temps % 2 != 0)){
                    printf("  |%s %s %s %s %s\n",tab_conjugue[i].conjonction, tab_conjugue[i].pronom, tab_conjugue[i].pronom_reflechi,tab_conjugue[i].auxiliaire, tab_conjugue[i].verbe);
                }
                else {
                    printf("  |%s %s %s %s\n",tab_conjugue[i].conjonction, tab_conjugue[i].pronom,tab_conjugue[i].auxiliaire, tab_conjugue[i].verbe);
                }
            }
         break;
         case 3: //imperatif
         j=0;
            for (i=0;i<6;i++) {
                // affectation des pronoms perso
                 if (reflechi==0) {
                if (i != 0) {
                    strcpy(tab_conjugue[i].pronom, pronoms_personnels[i].pronom);
                } 
                else {
                        if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                            strcpy(tab_conjugue[0].pronom, "j'");
                        }
                        else {
                            strcpy(tab_conjugue[0].pronom, pronoms_personnels[0].pronom);
                        }
                    }
                }
                else {// si reflechi
                    strcpy(tab_conjugue[i].pronom, pronoms_personnels[i].pronom);
                    strcpy(tab_conjugue[i].pronom_reflechi, pronominal[2][i].word);
                }
                
                if ((i==0) || (i==3) ||(i==4)) {
                    if ((reflechi == 0) && (temps % 2 == 0)){
                        printf("  |%s\n",tab_conjugue[i].verbe);
                    }
                    else if ((reflechi == 1) && (temps % 2 == 0)){
                        printf("  |%s - %s\n",tab_conjugue[i].verbe,tab_conjugue[i].pronom_reflechi);
                    }
                    else if ((reflechi == 1) && (temps % 2 != 0)){
                        // il n'y a pas d'impératif passé pour les verbes pronominaux
                        impossible = 1;
                    }
                    else {
                        printf("  |%s %s\n",tab_conjugue[i].auxiliaire, tab_conjugue[i].verbe);
                    }
                }
            }
            if (impossible == 1) {
                printf("  Le verbe %s ne peut être conjugué à l'impératif passé.\n",verbe_saisi);
            }
         break;
        case 4://Participe
         
            if (reflechi == 1) {
                if (temps % 2 == 0){//simple
                    if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                            printf(" | s' %s\n",tab_conjugue[0].verbe);
                        }
                        else {
                            printf(" | se %s\n",tab_conjugue[0].verbe);
                        }
                   }
                else {//passe
                    printf(" | s' %s %s\n",tab_conjugue[0].auxiliaire, tab_conjugue[0].verbe);
                } 
            }
            else {
                if (temps % 2 == 0){
                    printf(" | %s\n",tab_conjugue[0].verbe);
                }
                else {
                    printf(" | %s %s\n",tab_conjugue[0].auxiliaire, tab_conjugue[0].verbe);
                }
            }
        break;
        default://gerondif
            if (reflechi == 1) {
                if (temps % 2 == 0){//simple
                    if (verbe.verbe[0] == 'a' || verbe.verbe[0] == 'e' || verbe.verbe[0] == 'o' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'i' || verbe.verbe[0] == 'y') {
                            printf(" |en s' %s\n",tab_conjugue[0].verbe);
                        }
                        else {
                            printf(" |en se %s\n",tab_conjugue[0].verbe);
                        }
                   }
                else {//passe
                    printf(" |en s' %s %s\n",tab_conjugue[0].auxiliaire, tab_conjugue[0].verbe);
                } 
            }
            else {
                if (temps % 2 == 0){
                    printf(" |en %s\n",tab_conjugue[0].verbe);
                }
                else {
                    printf(" |en %s %s\n",tab_conjugue[0].auxiliaire, tab_conjugue[0].verbe);
                }
            }
            
    if (remarque == 1) {
            //on peut ici ajouter des remarques sur certaines verbes particuliers, on peut avoir un fichier remarques, lié aux verbes par leurs id
            printf("Remarques: \n");
        }
     }
    
    //poursuite ou fin de programme 
     reponse[0]='a';
     while ((reponse[0]!='o') && (reponse[0]!='n')) {
        printf("Voulez-vous conjuguer un autre verbe? (o/n)\n");
        printf("Choix: ");
        scanf("%s",reponse);
        reponse[0] = tolower(reponse[0]);  

        if (reponse[0]=='o') {
            actif ++;
        }
        else if (reponse[0]=='n') {
            actif = 0;
        }
        else {
            printf("Veuillez indiquer si vous souhaitez continuer ou non.\n");
        } 
     }
    getchar();
}
