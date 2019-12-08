/*fonctions_verbe*/

/*---------fonction-verif verbe------*/

void verif_verbe () {

	trouve = 0;
	int i=0,j=0;
	int temp;
    FILE *f1;
	
    //on alloue de la mémoire dynamiquement au tableau verbe
    
    tabverbes = malloc(5000 * sizeof(struct verbe));
    
    if (tabverbes == NULL) {
        printf("Allocation impossible\n");
    }
    else {
        //remplissage du tableau
        f1 = fopen("liste_verbes.txt","r");
        
        while(!feof(f1)){
        
        fscanf(f1,"%s %s %d %d %d %d %d %d %d %d %d %d %d",tabverbes[i].verbe,tabverbes[i].aux,&tabverbes[i].groupe,&tabverbes[i].PS,&tabverbes[i].gerondif,&tabverbes[i].participe,&tabverbes[i].temps_compose, &tabverbes[i].modele_present,&tabverbes[i].modele_PS,&tabverbes[i].pronom_perso_3_SG, &tabverbes[i].pronom_perso_3_SG_PL,&tabverbes[i].reflechi,&tabverbes[i].reference);
		i++;
	}
	nbverbe=i;
        
        fclose(f1);
    }
   
    //utile pour l'affichage
    strcpy(verbe_saisi,verbe.verbe); 
	//identifier si le verbe est réfléchi ou non
	presence_se = strncmp(verbe.verbe,"se ",3);
	presence_s = strncmp(verbe.verbe,"s'",2);
	reflechi = 0;
    //si le verbe entré par l'utilisateur est pronominal, on va vérifier si cette forme existe
	if (presence_se == 0 || presence_s == 0) 
    {
        while (trouve == 0 && j<nbverbe) 
        {
            // on importe les pronoms réfléchis dans un tableau pour les afficher par la suite
            lecture_fichier_pronom_reflechi ();
            if (strstr(verbe.verbe,tabverbes[j].verbe)) {
                trouve = 1;
                position = j;
            }
            j++;
        }
        
        if (trouve == 1){
            if (tabverbes[position].reflechi==1){
                reflechi = 1;
                verbe = tabverbes[position];
                longueur_verbe = strlen(verbe.verbe);
                strcpy(verbe.aux,"être"); 
            }
            else {
                reflechi = 0;
                trouve = -1; 
                verbe = tabverbes[position];
                longueur_verbe = strlen(verbe.verbe);
            }
        }
	}
    else 
    {
        //le verbe n'est pas pronominal
         while (trouve == 0 && j<nbverbe) 
        {
            temp = strcmp(verbe.verbe,tabverbes[j].verbe);
            if (temp == 0) {
                trouve = 1;
                position = j;
                verbe = tabverbes[position];
                longueur_verbe = strlen(verbe.verbe);
            }
            j++;
        }
    }
    
    //liberation de la memoire
    void free(void *tabverbes);
    tabverbes = NULL;
}


/*---------trouver sous-groupe de conjugaison------*/
void trouve_ss_groupe () {

    int taille = strlen(verbe.verbe);
    int antepenul = taille - 3;
    int ante_antepenul = taille - 4; 
    int found=0;
    
    //ne sert que pour le radical du 1er groupe
    if (verbe.groupe == 1) {
                
        /*ex:placer*/
        if(verbe.verbe[antepenul] == 'c') {
            ss_groupe = 1;
        }
        /*ex: manger*/
        else if (verbe.verbe[antepenul] == 'g'){
            ss_groupe = 2;
        }
        /*ex: payer*/
        else if (verbe.verbe[antepenul] == 'y' && verbe.verbe[ante_antepenul] == 'a'){
            ss_groupe = 3;
        }
        /*ex: broyer ou ennuyer*/
        else if ((verbe.verbe[antepenul] == 'y' && verbe.verbe[ante_antepenul] == 'o') ||(verbe.verbe[antepenul] == 'y' && verbe.verbe[ante_antepenul] == 'u')){
            ss_groupe = 4; 
        }

        /*ex:acheter,peser*/
        else if (verbe.verbe[ante_antepenul] == 'e'){
            ss_groupe = 5;
        }
        /*les verbes comme céder et les verbes sans exception*/
        else {
            //on regarde si dans l'avant derniere syllabe il y a un é
            ret = strstr(verbe.verbe,"é");
            while ((found ==0) && ret !=NULL) {
                    if (strlen(ret)<=6 && strlen(ret)>4) {
                        found = 1;//l'avant derniere syllabe contient é
                    }
                    else {
                        ret[0]='a';//on met n'importe quelle lettre, au prochain tour, elle sera effacer            
                    }
                    ret = strstr(ret,"é");
            }
            //affectation du sous groupe
            if (found == 1) {
                ss_groupe = 6;
            }
            else {
                ss_groupe = 0;
            }
        }
	 }
}
