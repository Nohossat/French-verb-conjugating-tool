void regles_generales (char mot[30],int j) {
    
    //il faut ajuster la regle pour le verbe avoir subjonctif present pluriel --> ayons / ayez
    
    int i,fin=0;
    int trouve = 0;
    char voyelles[6];
    char radical1[30];
    char conjugue1[30];
    
    int long_conjugue = strlen(mot);
    //on regarde par quelle lettre commence la terminaison
    strcpy(voyelles,"aoiu");
    for (i=0;i<4;i++) {
        if (termin[0] == voyelles[i]) {
            fin =1;
        }
        // on regarde l'avant derniere lettre du verbe conjugué
        if (mot[long_conjugue-2] ==voyelles[i]) {
            trouve = 1;
        }
    }
    
      //regle1: si le radical se termine par une voyelle (a,o,u,i) et que la terminaison commence par a, o, u ou i alors i devient y exception pour rire et les verbes en _ier , exception pour les auxiliaires au subjonctif present et imperatif present
        if ((fin == 1) && (mot[longueur_radical-1]=='i') && (verbe.reference != 15) && (verbe.groupe != 1)) {
            mot[longueur_radical-1]='y';
    }
    
    if ((verbe.reference==55 || verbe.reference==56) && (mode == 2 || mode == 3)) {//être et avoir
        if (j==3 || j==4) {
            strcpy(conjugue1,mot);
            strncpy(mot,conjugue1,longueur_radical);
            mot[longueur_radical]='\0';
            lecture_fichier_temps(1);
            strcat(mot,terminaison[0][j].term);
            printf("%d",longueur_radical);
        }
    }
     
    //regle 2: avt derniere lettre de tabconjugue est une voyelle et la derniere lettre est un --> la voyelle aura un accent circonflexe
    
    if ((mot[long_conjugue-1] == 't') && (trouve ==1)) {
        switch(mot[long_conjugue -2]) {
            case 'a': strncpy(conjugue1,mot,long_conjugue - 2);
                      strcat (conjugue1,"ât");
                      strcpy(mot,conjugue1);
            break;
            case 'o':strncpy(conjugue1,mot,long_conjugue - 2);
                     strcat (conjugue1,"ôt");
                     strcpy(mot,conjugue1);
            break;
            case 'u':
                    if (mode==2 && temps == 2) {
                     strncpy(conjugue1,mot,long_conjugue - 2);
                     strcat (conjugue1,"ût");
                     strcpy(mot,conjugue1);
                    }
            break;
            case 'i'://le î n'est pas à tous les temps- imparfait 
                    //ça vaut pour le present, futur, conditionnel et subj imparfait 
                    if (mode == 2 && temps == 2) { //subj present
                        strncpy(conjugue1,mot,long_conjugue - 2);
                        strcat (conjugue1,"ît");
                        strcpy(mot,conjugue1);
                    }
                    else if (mode == 1 && temps == 0) {
                        if (verbe.reference == 7 || (verbe.reference > 38 && verbe.reference < 44 )) {
                            strncpy(conjugue1,mot,long_conjugue - 2);
                            strcat (conjugue1,"ît");
                            strcpy(mot,conjugue1);
                        }
                    }
            break;
            default: printf("RAS");
        }
    } 
}