/*fonctions_choix*/

/*------------------------------choix du verbe-----------------------------*/
void choix_verbe () {
    printf("\n");
	printf("Veuillez entrer un verbe:");
	lecture_chaine_espaces(verbe.verbe);
    /*formatage();*/
    
}
/*------------------------------choix du mode-----------------------------*/
void choix_mode () 
{
		printf("Choisir le mode:\n");
		printf("  0 - Infinitif\n");
		printf("  1 - Indicatif\n");
		printf("  2 - Subjonctif\n");
		printf("  3 - Impératif\n");
		printf("  4 - Participe\n");
		printf("  5 - Gérondif\n");
		printf("  6 - Conditionnel\n");
		printf("Choix: ");
		scanf("%d",&mode);
        
    //contrôle de saisie
        while (mode < 0 || mode > 6) {
            printf("Ce choix n'est pas possible. Recommencez! \n");
            choix_mode();
        }
        switch (mode) {
            case 0: strcpy(mode_string,"Infinitif");
            break;
            case 1: strcpy(mode_string,"Indicatif");
            break;
            case 2: strcpy(mode_string,"Subjonctif");
            break;
            case 3: strcpy(mode_string,"Impératif");
            break;
            case 4: strcpy(mode_string,"Participe");
            break;
            case 5: strcpy(mode_string,"Gérondif");
            break;
            case 6: strcpy(mode_string,"Conditionnel");
            break;
            default:strcpy(mode_string,"");
        }
}

void choix_temps () {
    char bidon;
    
    if (mode >= 0 && mode < 7) 
    {
        if ((mode == 0) || (mode >= 3)) 
        {
            printf("Choisir le temps:\n");
            printf("  0 - Présent\n");
		    printf("  1 - Passé\n");
            printf("Choix: ");
            scanf("%d",&temps);
            scanf("%c",&bidon);
            
            if (temps < 0 || temps > 1){
                printf("Ce choix n'est pas possible. Recommencez! \n");
                scanf("%c",&bidon);
                choix_temps();
            }
        }
        else if (mode == 1) {
            printf("Choisir le temps: \n");
            printf("  0 - Présent\n");
            printf("  1 - Passé composé\n");
            printf("  2 - Imparfait\n");
            printf("  3 - Plus-que-Parfait\n");
            printf("  4 - Passé simple\n");
            printf("  5 - Passé antérieur\n");
            printf("  6 - Futur simple\n");
            printf("  7 - Futur antérieur\n");
            printf("Choix: ");
            scanf("%d",&temps);
            scanf("%c",&bidon);
            if (temps < 0 || temps > 7){
                printf("Ce choix n'est pas possible. Recommencez! \n");
                scanf("%c",&bidon);
                choix_temps();
            }
        }
        else if (mode == 2) {
            printf("Choisir le temps: \n");
            printf("  0 - Présent\n");
            printf("  1 - Passé\n");
            printf("  2 - Imparfait\n");
            printf("  3 - Plus-que-Parfait\n");
            printf("Choix: ");
            scanf("%d",&temps);
            scanf("%c",&bidon);
            
            if (temps < 0 || temps > 3){
                printf("Ce choix n'est pas possible. Recommencez! \n");
                scanf("%c",&bidon);
                choix_temps();
            }
        }
        switch (temps) {
            case 0: strcpy(temps_string,"Présent");
            break;
            case 1: 
            if (mode ==1){
                strcpy(temps_string,"Passé composé");
            }
            else {
                strcpy(temps_string,"Passé");
            }
            break;
            case 2: strcpy(temps_string,"Imparfait");
            break;
            case 3: strcpy(temps_string,"Plus-que-Parfait");
            break;
            case 4: strcpy(temps_string,"Passé simple");
            break;
            case 5: strcpy(temps_string,"Passé antérieur");
            break;
            case 6: strcpy(temps_string,"Futur simple");
            break;
            case 7: strcpy(temps_string,"Futur antérieur");
            break;
            default:strcpy(temps_string,"");
        }
    }
    else {
        printf("Ce choix n'est pas possible. Recommencez! \n");
        scanf("%c",&bidon);
        choix_mode();
        choix_temps();
    }
}