

int DO=523.25, //definimos las frecuencias de las notas
        DoS=554.37,
        RE=587.33,
        RES=622.25,
        MI=659.26,
        FA=698.46,
        FAS=739.99,
        SOL=783.99,
        SOLS=830.61,
        LA=880,
        LAS=932.33,
        SI=987.77,
        DO2=1046.5,
        RE2=1174.66,
        FAS2=1479.98,
        PAU=30000; 

//        int melodia[] = {SI, RE2, SI, RE2, PAU, SI, LA, SI, SI, SI, PAU, RE2, SI, SI, PAU, RE2, PAU, RE2, RE2, PAU, SI, RE2, SI, RE2, PAU,
//SI, LA, SI, SI, SI, PAU, RE2, SI, SI, PAU, RE2, PAU, RE2, RE2, PAU, RE2, PAU, SI, RE2, PAU, SI, RE2, PAU, SI, RE2,
//PAU, SI, PAU, RE2, SI, LA, SI, PAU, RE2,PAU, SI, RE2, PAU, SI, RE2, PAU, SI, RE2, PAU, SI, PAU, RE2, SI, LA, SI,
//PAU, FAS2, PAU, RE2, FAS2, PAU, RE2, FAS2, PAU, RE2 ,FAS2, PAU, RE2, FAS2, PAU, RE2, LA, SOLS, SI, PAU, FAS2, PAU,
//RE2, FAS2, PAU, RE2, FAS2, PAU, RE2, FAS2, PAU, RE2, FAS2, PAU, RE2, LA, SI, SI
//};

        int melodia[] = {SI, SI, DO2, RE2, RE2, DO2, SI, LA, SOL,  SOL, LA, SI, SI, LA, LA, SI, SI, DO2, RE2, RE2,DO2 , SI, LA, SOL,
SOL, LA, SI, LA, SOL, SOL
};
int d=1000,r=750, e=500, m=250, c=125; //definimos los tiempos de doble, entera, media y cuarta
//int duracionNota[] = {m, m, m, m, e, c, m, m, c, m, e, m, m, m, e, m, m, m, m, d, m, m, m, m, e, c, m, m, c, m, e, m, m, m, e, m, m, m, m, d,
//m, m, m, m, m, m, m, m, m, m, m, m, c, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m,
//m, m, m, m, m, m, m, m, m, m, m, m, c, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m,
//};

int duracionNota[] = {e,e,e,e,e,e,e,e,e,e,e,e,r, m, d,e,e,e,e,e,e,e,e,e,e,e,e,r, m, d};

int melod() {
    for (int notaActual = 0; notaActual < 30; notaActual++) {  //va a repetir las 112 notas
tone(buzz, melodia[notaActual]); //da el tono a la frecuencia de la nota en ese momento
delay(duracionNota[notaActual]);//se mantiene con la nota el tiempo definido para esa nota
noTone(buzz); //finaliza la melodía
}
    //return resultado;
}
