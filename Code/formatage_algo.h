
//explication: l'opération la plus complexe est la conversion de caractères accentués
    //avec la fonction strstr et une soustraction, on peut obtenir le rang du caractère accentué dans une chaîne
    //il suffit par la suite de dire au programme à quelle endroit remplacer le caractère accentué par le caractère souhaité

void formatage () {

struct accent {
    int pos;
    int type;
};
    
int i,j=0;
int l=0,k=0;
struct accent tab_position[10];
int nb_pos;
char valeur[30]="";
char variable[30];

    strcpy(variable,verbe.verbe);
    for(i=0;i<12;i+=2) {
        
        ret = strstr(variable,tab_caractères_acc[i].word);
        while(ret != NULL) {
            tab_position[j].pos = strlen(variable) - strlen(ret);
            tab_position[j].type = i;
            for (k=1;k<strlen(ret);k++) {
                strcpy(variable,"");
                variable[l++]= ret[k];
            }
            
            ret = strstr(variable,tab_caractères_acc[i].word);
            j++;
        }
    }
    nb_pos=i;
//on change les caractères accentués

    for (i=0;i<strlen(verbe.verbe);i++) {
        for(j=0;j<nb_pos;j++) {
            if(i != tab_position[j].pos) {
                valeur[i++] = tolower(verbe.verbe[k++]);
            }
            else {
                strcat(valeur,tab_caractères_acc[tab_position[j].type+1].word);
            }
        }
    }
    
    strcpy(verbe.verbe,valeur);
}
