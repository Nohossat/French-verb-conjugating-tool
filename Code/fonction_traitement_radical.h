//traitement du radical selon terminaison du temps choisi
    
void traitement_radical_1 (int sous_groupe,int j) {
    char radical1[20]="";
    char tag[3]="";
    int long_radical_usuel = strlen(radical_usuel);
    
	switch (sous_groupe) {
		case 1: /*ex: placer*/
        if ((termin[0]=='o') || (termin[0]=='a') || strstr(termin,"â"))  
			{
                if (strstr(radical,"ç")==0) {//si la derniere lettre n'est pas un ç
                    strncpy(radical1,radical_usuel,longueur_radical - 1);
                    radical1[longueur_radical - 1]='\0';
                    strcat (radical1,"ç");
                    strcpy(radical,radical1);
                }
			}
            else {
                strcpy(radical,radical_usuel);
            }
		break;
		case 2: /*ex: manger ou protéger*/
        /*changement de radical pour protéger*/
            if (strstr(verbe.verbe,"éger")) {
                if ((strcmp(termin,"e")==0) || (strcmp(termin,"es")==0) || (strcmp(termin,"ent")==0)){
                     strncpy(radical1,radical_usuel,longueur_radical-3);
                     radical1[longueur_radical - 1]='\0';
				     strcat(radical1,"èg");
                     strcpy(radical,radical1);
                }
                else {
                     strcpy(radical,radical_usuel);
                }
            }
            else {
                strcpy(radical,radical_usuel);
            }
        /*ajout du 'e' si termin[0] == voyelle*/
			if ((termin[0]=='o') || (termin[0]=='a') || (strstr(termin,"â")))
			{
			    if (radical[longueur_radical] != 'e') {
                    strcpy(radical1,radical);
				    strcat(radical1,"e");
                    strcpy(radical,radical1);
			    }
            }
		break;
		case 3: /*ex:payer*/
                if (termin[0] == 'e' && j != 4) {
                    if((mode==1 && temps ==0) || (mode ==2 && temps == 0)) {
                        strcpy(radical1,radical_usuel);
                        radical1[longueur_radical-1] = 'i';
                        sprintf(conjugue,"%s%s/",radical1,termin);
                        strcpy(tab_conjugue[j].verbe,conjugue);
                        strcpy(radical,radical_usuel);
                    }
                }
                else if ((mode==1 && temps == 6) || (mode ==6 && temps ==0)) {
                        strncpy(radical1,radical_usuel,strlen(radical_usuel)-1);
                        radical1[strlen(radical_usuel)-1]='\0';
                        strcat(radical1,"ie");
                        sprintf(conjugue,"%s%s/",radical1,termin);
                        strcpy(tab_conjugue[j].verbe,conjugue);
                        strcpy(radical,radical_usuel);
                }
                else {
                    strcpy(radical,radical_usuel);
                } 
		break;
		case 4: /*ex: broyer ou ennuyer*/
                if (strstr(verbe.verbe,"envoyer") && termin[0]=='r') {
                    strcpy(radical,radical_usuel);
                    if ((mode == 1 && temps == 6) || (mode == 6 && temps == 0)) {
                        if (radical[longueur_radical] != 'r') {
                            radical_usuel[longueur_radical-1] ='r';
                            radical_usuel[longueur_radical-2] ='e';
                            strcpy(radical,radical_usuel);
                        }
                        //radical distinct pour le futur et le conditionnel
                    }
                }
                else if (termin[0]=='e' && j !=4) {
                    strcpy(radical1,radical_usuel);
		            radical1[longueur_radical-1] = 'i';
                    strcpy(radical,radical1);
                }
		        else {
                 strcpy(radical1,radical_usuel);
		    	 radical1[longueur_radical-1] = 'y';
                 strcpy(radical,radical1);
		        }
		    
		break;
		case 5: if (strstr(verbe.verbe,"appeler") || strstr(verbe.verbe,"jeter") || strstr(verbe.verbe,"interpeler")) 
						{
							if ((strcmp(termin,"e")==0) || (strcmp(termin,"es")==0) ||(strcmp(termin,"ent")==0)){
                                printf("%s\n",radical_usuel);
                                tag[0] = radical_usuel[longueur_radical-1];
                                strcpy(radical1,radical_usuel);
                                strcat(radical1,tag);
                                strcpy(radical,radical1);
                            }
                            else {      
				                strcpy(radical,radical_usuel);
                                }	
						} 
                        /*ex:acheter*/
						else 
                        {
                            tag[0]=radical_usuel[long_radical_usuel-1];
                            //cette transformation a lieu au présent, futur simple, conditionnel et subjonctif present
							  if ((mode == 1 && temps == 6) || (mode ==6 && temps ==0) || (mode == 2 && temps == 0 && j!=3 && j!=4) || (strcmp(termin,"e")==0) || (strcmp(termin,"es")==0) || (strcmp(termin,"ent")==0)){
                                    strncpy(radical1,radical_usuel,long_radical_usuel-2);
                                    radical1[longueur_radical - 1]='\0';
				                    strcat(radical1,"è");
                                    strcat(radical1,tag);
                                    strcpy(radical,radical1);
                              }
                              else {
                                    strncpy(radical1,radical_usuel,long_radical_usuel-2);
                                    radical1[longueur_radical - 1]='\0';
				                    strcat(radical1,"e");
                                    strcat(radical1,tag);
                                    strcpy(radical,radical1);
                              }
						}
		break;
		case 6: /*ex:céder*/
                if (strlen(ret)==5) {
                    tag[0]=radical_usuel[longueur_radical-1];
                }
                else if (strlen(ret)==6){
                    tag[0]=radical_usuel[longueur_radical-2];
                    tag[1]=radical_usuel[longueur_radical-1];
                }
                
                if ((strcmp(termin,"e")==0) || (strcmp(termin,"es")==0) || (strcmp(termin,"ent")==0)){
                                    strncpy(radical1,radical_usuel,longueur_verbe -strlen(ret));
                                    radical1[strlen(ret)]='\0';
				                    strcat(radical1,"è");
                                    strcat(radical1,tag);
                                    strcpy(radical,radical1);
                              }
                              else {
                                    strncpy(radical1,radical_usuel,longueur_verbe -strlen(ret));
                                    radical1[strlen(ret)]='\0';
                                    strcat(radical1,"é");
                                    strcat(radical1,tag);
                                    strcpy(radical,radical1); 
                              }
		break;
		default: strcpy(radical,radical_usuel);
        break;
	}
    
    //ajout du "e" pour le futur et le conditionnel
    if ((mode ==1 && temps == 6) || (mode == 6 && temps==0)) {
        if ((radical[longueur_radical] != 'e') && (ss_groupe!=4)) {
            strcat(radical,"e");
        }
    }
    printf("%s\n",radical);
}

/*------------traitement du radical des verbes du 2eme groupe*/
void traitement_radical_2 (int i) {
    char radical1[20];
    int long_radical_usuel = strlen(radical_usuel);

    if (strcmp(verbe.verbe,"haïr") == 0) {
        if ((mode == 1) && (temps == 0) && (i<3)) {
            strcpy (radical_usuel,"hai");
        }
        else {
            strcpy (radical_usuel,"haï");
        }
    }
    if (strcmp(verbe.verbe,"maudire") == 0) {
        strcpy (radical_usuel,"maudi");
    }
    
     if (( mode == 1 && temps == 2) || ((mode == 1) && temps == 0 && i >=3) || (mode == 2 && temps == 0) || (mode == 4) || (mode == 5)) {
        if (radical_usuel[longueur_radical] != 's') {
            strcpy(radical1,radical_usuel);
            strcat(radical1,"ss");
            strcpy(radical,radical1);
        }
    }
    else if ((mode == 1) && (temps == 4)) {
        strncpy(radical,radical_usuel,long_radical_usuel-1);
    }
    else{
        strcpy(radical,radical_usuel);
    }
}

/*--------------------------traitement_radical_3------------------------*/
void traitement_radical_3(int i) {
    switch (temps) { 
        case 0 : //present 
       
        if (mode == 1) {//indicatif
            if (i<3) {//radical spécial pour les 3eres pers du SG
                strcpy (radical,radical_present);
                if (verbe.reference == 48 && i==0) {//cas particulier: pouvoir
                    strcat (tab_conjugue[i].verbe,"puis/");
                }
            }
            //les verbes qui ont un radical subj_present au pluriel
            else if (i>2 && ((verbe.reference > 27 && verbe.reference < 43) || verbe.reference == 51)) {
                    strcpy (radical,radical_subj_present);
                }  
            else if (i>=3) {
                strcpy (radical,radical_usuel);
            }
            else if (i==5) 
            {
                //aller est le seul verbe qui utilise son radical present a la derniere personne
                if (strcmp(tabverbes[i].verbe,"aller")==0) {
                    strcpy (radical,"v");
                }
                //les verbes qui ont un radical subjectif present a la derniere personne
                else if (verbe.reference > 58 || (verbe.reference > 20 && verbe.reference < 26)) {
                    strcpy (radical,radical_subj_present);
                }
                //vouloir et pouvoir ont un radical unique à la derniere personne
                else if (verbe.reference == 48 || verbe.reference == 49){
                    radical_usuel[1]='e';
                    strcpy (radical,radical_usuel);
                }
            }
            //les autres verbes utilisent leur radical usuel
            else {
                strcpy (radical,radical_usuel);
            }
            
            //cas particuliers: avoir et être
             if ((verbe.reference ==55 || verbe.reference == 56)) {
                if (strcmp(verbe.verbe,"être")==0){
                    strcpy(radical,auxiliaire_present[0][i].word);
                    strcpy(termin,"");
                }
                else {
                    strcpy(radical,auxiliaire_present[1][i].word);
                    strcpy(termin,"");
                }
            }
        }
        if (mode == 2) 
        { //subjonctif
            if ((i< 3) || (i==5)) {
                strcpy (radical,radical_subj_present);
            }
            else if (i==3 || i==4) {
                //les verbes qui ont le radical subj_present à toutes les personnes
                if (verbe.reference < 58) {
                    strcpy (radical,radical_subj_present);
                }
                else {
                    strcpy(radical,radical_usuel);
                }

            }
        }
        if (mode == 3) 
        { 
            // imperatif
            if (verbe.reference == 49) {
                //vouloir: il y a deux formes
                if (i==0 || i==4) {
                    strcat(tab_conjugue[i].verbe,radical_subj_present);
                    lecture_fichier_temps(1);
                    strcat(tab_conjugue[i].verbe,terminaison[verbe.modele_present][i].term);
                }
            }
            else if (verbe.reference == 53 || verbe.reference == 55 || verbe.reference == 56) { 
                //savoir, être, avoir
                strcpy(radical,radical_subj_present);
            }
            else { 
                // les autres verbes se conjuguent comme au présent de l'indicatif
                strcpy(radical,radical_present);
            }
        }
        if (mode == 4 || mode == 5) 
        {
            //participe et gérondif
            if (verbe.reference == 26) {
                strcpy (radical,"sé");
            }
            else if (verbe.reference == 53) {
                strcpy (radical,"sach");
            }
            else if (verbe.reference == 55) {
                strcpy (radical,"ét");
            }
            else if (verbe.reference == 56) {
                strcpy (radical,radical_subj_present);
            }
            else {
                strcpy(radical,radical_usuel);
            }
        }
        
        if (mode == 6) {
            strcpy(radical,radical_futur);
        }
        break;
        case 2://Imparfait
        
            if (mode == 1) //indicatif
            {
                if (strcmp(tabverbes[i].verbe,"fuir") == 0) {
                    strcpy(radical,radical_present);
                }
                //être à l'imparfait
                else if (verbe.reference == 55) 
                {
                    strcpy(radical,"ét");
                }
                //imparfait des verbes en aître,oître, etc
                else if (verbe.reference > 38 && verbe.reference < 43) {
                     strcpy(radical,radical_subj_present);
                }
                else {
                    strcpy(radical,radical_usuel);
                } 
            }
            else if (mode == 2) //subjonctif
            {
                if (verbe.PS == 1) {
                    //on utilise le radical du passé simple au subjonctif imparfait pour tous les verbes
                    strcpy (radical,radical_passe_simple);
                }
            }
            else 
            { 
                //les autres modes
                strcpy(radical,radical_usuel);
            }
        break;
        case 4://PS
            if (verbe.PS == 1) {
                strcpy (radical,radical_passe_simple);
            }
        break;
        case 6://Futur
            strcpy (radical,radical_futur);
        break;
        default: strcpy(radical,radical_usuel);
    }
}

//-------------------------traitement_radical-auxiliaire------------------//
void traitement_radical_aux (int i){
    //traitement des auxiliaires être et avoir
    int trouve1=0;
    int j=0;
    int temp,pos;
    FILE *f1;
    int k=0;
    int l;
    
    //on récupère les données sur l'auxiliaire dans la liste de verbes
        trouve1 = 0;
        j=0;
        while ((trouve1 == 0) && (j<nombre_fx_verbe)) 
        {
            temp = strcmp(tab_fx_verbe[j].verbe,verbe.aux);
            if (temp == 0) 
            {
                pos = j;
                trouve1 = 1;
            }
            j++;
        }
        if (trouve1 == 1) {
        auxil = tab_fx_verbe[pos];
        }
    
    // on traite le radical de l'auxiliaire selon le temps
        if (mode == 1) {
            //INDICATIF
            switch (temps) {
            case 1: //passé composé
                f1 = fopen("fichier_present_auxiliaire.txt","r");
                    while (!feof(f1)){
                        for (l=0;l<2;l++){
                            for (k=0;k<6;k++){
                                fscanf(f1,"%s",auxiliaire_present[l][k].word);
                            }
                        }
                    }
                fclose(f1);
                if (strcmp(verbe.aux,"être")==0){
                    strcpy(radical_aux,auxiliaire_present[0][i].word);
                }
                else {
                    strcpy(radical_aux,auxiliaire_present[1][i].word);
                }
            break;
                
            case 3: //PqP
                if (strcmp(verbe.aux,"être")==0){
                    strcpy(radical_aux,"ét");
                }
                else {
                    strcpy(radical_aux,"av");
                }
                lecture_fichier_temps(mode);
                strcat(radical_aux,terminaison[4][i].term);
            break;
                
            case 5: //Passé antérieur
                strcpy(radical_aux,auxil.radical_passe_simple);
                lecture_fichier_temps(mode);
                strcat(radical_aux,terminaison[7][i].term);
            break;
                
            default: //Futur antérieur
                strcpy(radical_aux,auxil.radical_futur);
                lecture_fichier_temps(mode);
                strcat(radical_aux,terminaison[9][i].term);
            }
        }
        else if (mode == 2)
        {
            //SUBJONCTIF
            if (temps == 1){//passé
                if (verbe.reference == 56) {//avoir
                    strcpy(radical_aux,auxil.radical_subj_present);
                    lecture_fichier_temps(mode);
                    strcat(radical_aux,terminaison[0][i].term);
                }
                else {
                    //être
                    strcpy(radical_aux,auxil.radical_subj_present);
                    lecture_fichier_temps(1);
                    strcat(radical_aux,terminaison[1][i].term);
                }
            }
            else if (temps == 3){//PqP
                strcpy(radical_aux,auxil.radical_passe_simple);
                lecture_fichier_temps(1);
                int lg = strlen(terminaison[7][0].term)-1;
                strncat(radical_aux,terminaison[7][0].term,lg);
                lecture_fichier_temps(mode);
                strcat(radical_aux,terminaison[1][i].term);
            }
        }
        else if (mode == 3)
        {
            //IMPERATIF
            strcpy(radical_aux,auxil.radical_subj_present);
            lecture_fichier_temps(2);
            strcat(radical_aux,terminaison[0][i].term);
        }
        else if ((mode == 4) || (mode == 5))
        {
            //PARTICIPE ET GERONDIF
            if (strcmp(verbe.aux,"être")==0){
                    strcpy(radical_aux,"étant");
                }
                else {
                    strcpy(radical_aux,"ayant");
                }
        }
        else if (mode == 6)
        {
            //CONDITIONNEL
            strcpy(radical_aux,auxil.radical_futur);
            lecture_fichier_temps(mode);
            strcat(radical_aux,terminaison[0][i].term);
        }
}
