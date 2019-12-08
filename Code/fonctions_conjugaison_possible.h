int conjugaison_possible_temps () {
    
    int flag =1;
    //flag Temps composé
    if ((verbe.temps_compose==0) && (temps == 1 || temps == 3 || temps == 5 || temps ==7)) 
    {
        flag =0;
    }

      //flag PS et subj imparfait
    if ((verbe.PS==0) && ((mode == 1 && temps == 4) || (mode == 2 && temps == 2))) 
        {
        flag =0;
        }  

        //flag gerondif
    if ((verbe.gerondif==0) && (mode == 5)) 
        {
        flag =0;
    }

    //flag participe

    if ((verbe.participe==0) && ((mode == 4))) {
        flag =0;
    }

    // flag impératif: pouvoir, pleuvoir, falloir, seoir, messeoir, échoir, déchoir
        if ((verbe.reference == 11 || verbe.reference == 14 || verbe.reference == 26 || (verbe.reference > 45 && verbe.reference < 49)) && (mode==3)) 
        {
	flag =0;
}
        
    // conjugaison impossible a l'imparfait
if ((verbe.reference == 10 || verbe.reference == 11 || verbe.reference == 25) && (mode==1 && temps ==2)) 
        {
	flag =0;
}
    
    // cas particuliers: ouïr, gésir, choir
        
        //gésir
        if ((verbe.reference == 7) && ((mode==2) || (mode == 6) || (mode == 3) || (mode==1 && temps==6))) {
	flag =0;
}
        // choir
        if (verbe.reference == 13 && ((mode==3 && temps==0) || (mode ==2 && temps ==0))) {
	flag =0;
}
    // cas particuliers: les verbes qui ne se conjuguent qu'à l'infinitif 
        //ouïr, il y a -t-il d'autre cas???
        if (verbe.reference == 16) {
            flag = 0;
        }
        
        if (flag ==0) {
            //FIN DE PROGRAMME
            printf("Le verbe %s ne peut être conjugué.\n",verbe_saisi);
            printf("\n");
            printf(" Remarques : %d\n",remarque);
        }
    
    return flag;
}
    
        
    