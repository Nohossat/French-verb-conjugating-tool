/*definition_structures*/

struct conjugaison {
    char conjonction [5];
    char pronom[15];
    char pronom_reflechi[6];
    char auxiliaire[20];
    char verbe [30];

};

struct verbe {
    char verbe[30];
    char aux [10];
    int groupe;
    int PS;
    int gerondif;
    int participe;
    int temps_compose;
    int modele_present; 
    int modele_PS;
    int pronom_perso_3_SG_PL;
    int pronom_perso_3_SG;
    int reflechi;
    int reference;
};

struct temps {
    char term [15];
};

struct pronoms {
    char pronom [15];
};

struct mot {
    char word [30];
};

struct faux_verbe {
    int id;
    char verbe[30];
    char radical_present[20];
    char radical_futur[20];
    char radical_subj_present[20];
    char radical_passe_simple[20];
    char PP[20];
};