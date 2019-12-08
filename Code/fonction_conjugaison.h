/*fonction_conjugaison*/

void conjugaison_verbe () {
    FILE *f1;
    int i,j,k,l;
    int taille;
    char deuxieme_radical[30];
    char term_subj_imparfait[15];
    struct mot pronom_reflechi[2][6];
    
    for (i=0;i<6;i++) 
    {
    	strcpy(termin,"");//on remet la terminaison à vide

    /*TEMPS SIMPLES/COMPOSÉS et GESTION DES TERMINAISONS*/
        if (temps % 2 == 0) {
/*----------------------------TEMPS SIMPLES-----------------------------*/
            
        /*---------PAS D'AUXILIAIRE--------*/
            strcpy(tab_conjugue[i].auxiliaire,"");
            
        /*-----------GESTION DES TERMINAISONS----------*/
            /*INDICATIF*/
            if (mode == 1)
            {
                /*lecture du fichier de terminaisons*/
                lecture_fichier_temps(mode);
                if (temps == 0) {//present
                    
                    //cas particuliers: être et avoir
                    if (verbe.reference ==55 || verbe.reference == 56 ||((verbe.reference ==31) && (i==2)) ) {
                        strcpy(termin,"");
                    }
                    else {
                        /*les flags vont indiquer la ligne correspondante au temps*/
                        strcpy(termin,terminaison[verbe.modele_present][i].term);
                    }
                }
                
                else if (temps == 2) {//imparfait
                    strcpy(termin,terminaison[4][i].term);
                }
                else if (temps == 4) {
                    strcpy(termin,terminaison[verbe.modele_PS][i].term);
                }
                else {//futur
                    strcpy(termin,terminaison[9][i].term);
                }
            }
            
            /*SUBJONCTIF*/
            if (mode == 2) {
                if (temps == 0) {
                    //présent
                    lecture_fichier_temps(mode);
                    strcpy(termin,terminaison[temps][i].term);
                    
                }
                else {
                    //imparfait
                    if (verbe.groupe == 1 || verbe.groupe == 3) {
                        // on importe la terminaison du PS
                        lecture_fichier_temps(1);
                        taille = strlen(terminaison[verbe.modele_PS][0].term);
                        strncpy(termin,terminaison[verbe.modele_PS][0].term,taille-1);
                        termin[taille-1] ='\0';
                        // on importe la terminaison propre au subj imparfait
                        lecture_fichier_temps(mode);
                        strcat(termin,terminaison[1][i].term);
                        
                         if ((verbe.reference == 61) && (i == 2)){
                             strcpy(termin,"înt");
                        }
                    }
                    else if (verbe.groupe == 2) {
                        lecture_fichier_temps(mode);
                        strcat(termin,terminaison[1][i].term);
                    }
                }
            }
            
            /*IMPERATIF*/
            if ((mode == 3) && (i==0 || i==3 || i==4)) {
                 lecture_fichier_temps(1);
                 strcpy(termin,terminaison[verbe.modele_present][i].term);
                if ((verbe.reference == 53) && (i==1)) {//terminaison irrégulière pour savoir
                    strcpy(termin,"e");
                }
                if (strcmp(verbe.verbe,"être")==0) {
                    lecture_fichier_temps(1);
                    strcpy(termin,terminaison[1][i].term);
                }
                if (strcmp(verbe.verbe,"avoir")==0) {
                    lecture_fichier_temps(2);
                    strcpy(termin,terminaison[0][i].term);
                }
            }
            
            /*PARTICIPE PRESENT ET GERONDIF*/
            if ((mode == 4) || (mode == 5)) {
                strcpy(termin,"ant");
            }
            
            /*CONDITIONNEL*/
            if (mode == 6) {
                 lecture_fichier_temps(mode);
                 strcpy(termin,terminaison[0][i].term);
            }
            
            /*ANALYSE DU RADICAL*/
            if (verbe.groupe == 1) {
                traitement_radical_1(ss_groupe,i);
                longueur_radical = strlen(radical);
            }
            else if (verbe.groupe == 2) {
                traitement_radical_2(i);
                longueur_radical = strlen(radical);
            }
            else {
                traitement_radical_3(i);
                longueur_radical = strlen(radical);
            } 
        }
/*-------------------------TEMPS COMPOSES--------------------------*/
        else
        {
            /*traitement du radical*/
            traitement_radical_aux(i);
            /*ajout du radical au tab_conjugue*/
            strcpy(tab_conjugue[i].auxiliaire,radical_aux);
            /*Terminaisons Participe Passé*/
            
            if (verbe.groupe == 1) {
                strcpy(radical,radical_usuel);
                strcpy(termin,"é");
                //on gère les accords selon le genre et le nombre
                if (strcmp(verbe.aux,"être")==0) {
                        strcat(termin,"(e)");
                    if (i > 2) {
                        strcat(termin,"s");
                    }
                }
                sprintf(participe_passe,"%s%s",radical,termin);
            }
            else if (verbe.groupe == 2) {
                strcpy(radical,radical_usuel);
                strcpy(termin,"");
                if ((strcmp(verbe.aux,"être")==0) && i>2) {
                    if ((i==2) || (i==5)) {
                        strcat(termin,"(e)");
                    }
                    strcat(termin,"s");
                }
                sprintf(participe_passe,"%s%s",radical,termin);
            }
            else {
                strcpy(radical,participe_passe);
                if ((strcmp(verbe.aux,"être")==0) && i>2) {
                    if ((i==2) || (i==5)) {
                        strcat(termin,"(e)");
                    }
                    strcat(termin,"s");
                }
                strcpy(termin,"");
            }
        }
        
        //PRONOMS REFLECHIS
            if (mode == 3){
                //à l'impératif, les pronoms réfléchis sont distincts
                strcpy(tab_conjugue[i].pronom_reflechi,pronom_reflechi[1][i].word);
            }
            else {
                strcpy(tab_conjugue[i].pronom_reflechi,pronom_reflechi[0][i].word);
            }
   
        //EXCEPTIONS
        if (verbe.reference == 33 || verbe.reference == 52) {
            if (mode == 1 && temps == 0 && i==4) { 
                // 2eme pers du PL au présent de l'indicatif pour les verbes faire et dire
                strcpy (radical,radical_usuel);
                strcpy(termin,"tes");
            } 
        }
            
        if ((verbe.reference == 52) && ((mode == 1) && (i==3))) {
            // 1ere pers du PL au présent de l'indicatif pour le verbe faire
                strcpy(radical,radical_usuel);
                strcpy(termin,"sons");
            }
        if (verbe.reference == 52 || verbe.reference == 54) {
            //pour aller et faire
            if ((mode ==1) && (i==5)) {// la derniere personne du present se termine par _ont
                strncpy(radical,radical_usuel,1);
                radical[1]='\0'; 
                strcpy(termin,"ont");
            }
        }
        
        //CONCATENATION DU RADICAL + TERMINAISON
        
        sprintf(conjugue,"%s%s",radical,termin);
         //ici ajoute la fonction regles_generales
        regles_generales(conjugue,i);
        strcpy(tab_conjugue[i].verbe,conjugue);
    }
    
    //DOUBLE RADICAL pour asseoir et les verbes en _ayer
        if (verbe.reference == 51 && (!(mode ==1 && temps == 4) && !(mode ==2 && temps ==2))) {
            strcpy(deuxieme_radical,"assoi");
            if (mode ==1 && temps == 0) {
                lecture_fichier_temps(mode);
                strcpy(termin,terminaison[1][i].term);
            }
            strcat(deuxieme_radical,termin);
            regles_generales(deuxieme_radical,i);
            strcat(tab_conjugue[i].verbe,"/");
            strcat(tab_conjugue[i].verbe,deuxieme_radical);
        }
}
        
    
       