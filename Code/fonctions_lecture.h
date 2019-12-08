/*fonctions_lecture*/

//------------on accepte les espaces dans le verbe-------//
void lecture_chaine_espaces (char ch[]) {
    int present[20];
    int i=0,j=0;
    int nb=0;
    //comparaison avec cette chaine pour dire qu'un verbe ne peut avoir de chiffres
	char car=' ';
	
	while ((car=getchar()) != '\n'){
        
        ch[i++]=car;
    }
	ch[i++]='\0';

}

//---------------lecture_fichier_pronoms-----------//
void lecture_pronoms_personnels() {
    int i=0;
    FILE *f1;
	
	f1 = fopen("pronoms_personnels.txt","r");
	
	while(!feof(f1)){
		fscanf(f1,"%s",pronoms_personnels[i].pronom);
		i++;
	}
	fclose(f1);
}

//------------------chargement_fichier_temps------------//

void lecture_fichier_temps(int modal) {
    int i=0;
	FILE *f1;
	char nom_fichier[20]; 
    //modele de nom de fichier: mode_int//
    
    sprintf(nom_fichier,"mode_%d.txt",modal);
    
	f1 = fopen(nom_fichier,"r");
	
	while(!feof(f1)){
		fscanf(f1,"%s %s %s %s %s %s",terminaison[i][0].term,terminaison[i][1].term,terminaison[i][2].term,terminaison[i][3].term,terminaison[i][4].term,terminaison[i][5].term);
		i++;
	}
	fclose(f1);
}

//-----------------lecture fichier present des auxiliaires--------------------//

void lecture_fichier_present_auxiliaire ()
{
    FILE *f1;
    int l,k;
    f1 = fopen("fichier_present_auxiliaire.txt","r");
      while (!feof(f1))
      {
        for (l=0;l<2;l++){
            for (k=0;k<6;k++){
                fscanf(f1,"%s",auxiliaire_present[l][k].word);
            }
        }
      }
    fclose(f1);
}

/*-----------------lecture fichier pronom reféchi-----------*/


void lecture_fichier_pronom_reflechi () {
    FILE *f1;
    int j,k;
    f1 = fopen("fichier_pronom_reflechi.txt","r");
            while (!feof(f1)){
                for (j=0;j<3;j++) {
                    for(k=0;k<6;k++){
                        fscanf(f1,"%s",pronominal[j][k].word);
                    }
                } 
            }
        fclose(f1);
}