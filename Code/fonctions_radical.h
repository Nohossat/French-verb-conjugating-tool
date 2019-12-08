/*fonctions_radical*/

void trouve_radical () {
    longueur_verbe = strlen(verbe.verbe);
    longueur_radical = longueur_verbe - 2;
    int n;
    FILE *f1;
    
    /*------------------------LECTURE--------------------------*/
    f1 = fopen("liste_faux_verbes.txt","r");
        n=0;
        while (!feof(f1)) {
            fscanf(f1,"%d %s %s %s %s %s %s",&tab_fx_verbe[n].id,tab_fx_verbe[n].verbe,tab_fx_verbe[n].radical_present,tab_fx_verbe[n].radical_futur,tab_fx_verbe[n].radical_subj_present,tab_fx_verbe[n].radical_passe_simple,tab_fx_verbe[n].PP);
            n++;
        }
        nombre_fx_verbe = n;
    fclose(f1);
    /*-----------------------ANALYSE--------------------*/
    if (verbe.groupe == 1) {
        //On définit le radical usuel
        strncpy(radical_usuel,verbe.verbe,longueur_radical);
        radical_usuel[longueur_radical]='\0';
        strcpy(terminaison_infinitif,"er");
        longueur_terminaison_infinitif= strlen(terminaison_infinitif);
    }
    else if (verbe.groupe == 2) {
        //On définit le radical usuel
        if (strcmp(verbe.verbe,"maudire")==0) {
            longueur_radical = longueur_verbe - 2;
            strncpy(radical_usuel,verbe.verbe,longueur_radical);
            radical_usuel[longueur_radical]='\0';
            strcpy(terminaison_infinitif,"re");
            longueur_terminaison_infinitif= strlen(terminaison_infinitif);
        }
        longueur_radical = longueur_verbe - 1;
        strncpy(radical_usuel,verbe.verbe,longueur_radical);
        radical_usuel[longueur_radical]='\0';
        strcpy(terminaison_infinitif,"ir");
        longueur_terminaison_infinitif= strlen(terminaison_infinitif);
    }
    else {
        //On définit le radical usuel
        if ((verbe.verbe[longueur_verbe-1]=='r') && (verbe.verbe[longueur_verbe-2]=='i') && (verbe.verbe[longueur_verbe-3]=='o')) {
            longueur_radical = longueur_verbe - 3;
            strncpy(radical_usuel,verbe.verbe,longueur_radical);
            radical_usuel[longueur_radical]='\0';
            strcpy(terminaison_infinitif,"oir");
            longueur_terminaison_infinitif= strlen(terminaison_infinitif);
        }
        else {
            if ((verbe.verbe[longueur_verbe-1]=='r') && (verbe.verbe[longueur_verbe-2]=='i') && (verbe.verbe[longueur_verbe-3]!='o')) {
                longueur_radical = longueur_verbe - 2;
                strncpy(radical_usuel,verbe.verbe,longueur_radical);
                radical_usuel[longueur_radical]='\0';
                strcpy(terminaison_infinitif,"ir");
                longueur_terminaison_infinitif= strlen(terminaison_infinitif);
            }
            else {
                longueur_radical = longueur_verbe - 2;
                strncpy(radical_usuel,verbe.verbe,longueur_radical);
                radical_usuel[longueur_radical]='\0';
                strcpy(terminaison_infinitif,"re");
                longueur_terminaison_infinitif= strlen(terminaison_infinitif);
            }
        }
        
        //il faut traiter le cas de boire
        if (verbe.reference == 60) {
            strcpy(radical_usuel,"buv");
        }
        
        //autres exceptions??
    }
        if (verbe.reference == 7) {
            strcpy(radical_usuel,"gi");
        }
    //radicaux selon le temps pour les verbes du 3eme groupe
   
    if (verbe.groupe == 3) {
    //le préfixe du verbe
    fx_verbe = tab_fx_verbe[verbe.reference];
    int longueur_faux_verbe = strlen(fx_verbe.verbe);
    strncpy(prefixe,verbe.verbe,longueur_verbe-longueur_faux_verbe); 
    prefixe[longueur_verbe-longueur_faux_verbe]='\0';
    
    //je concatène le préfixe et le radical 
    sprintf(radical_present,"%s%s",prefixe,fx_verbe.radical_present);
    sprintf(radical_futur,"%s%s",prefixe,fx_verbe.radical_futur);
    sprintf(radical_subj_present,"%s%s",prefixe,fx_verbe.radical_subj_present);
    if (strcmp(fx_verbe.radical_passe_simple,"_") == 0) {
        strcpy(radical_passe_simple,prefixe);
    }
    else {
        sprintf(radical_passe_simple,"%s%s",prefixe,fx_verbe.radical_passe_simple);
    }
    sprintf(participe_passe,"%s%s",prefixe,fx_verbe.PP);
        
    }
}
    
