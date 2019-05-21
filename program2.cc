/**
 * @mainpage Gestió de la codificació i la decodificació en funció de diferent idiomes.
 En aquesta pàgina hi ha l'especificació de la pràctica de PRO2 de 2019.
 
 En ella s'especifiquen els arxius on s'especifiquen les funcions que fa servir el programa principal program.cc
 

*/

/** @file program.cc
    @brief Programa principal per la gestió de codificar i descodificar.
*/

#include "Cjt_Idiomes.hh"

int main() {
    
    Cjt_Idiomes () conjunt;
    Idioma () idioma;
    omplir_Cjt_Idiomes (conjunt);
    
    /*tipus_dada*/ op;
    string idioma, text;
    while(op != /*acabar*/){
        
        if(op == /*afegir o modificar*/){
            cin >> idioma >> text;
            afegir_modificar_idioma (idioma, text);
        }
        
        else if(op == /*codifica*/){
            cin >> idioma >> text;
            if (idioma_esta (idioma, conjunt)) codifica (idioma, text);
        }
        
        else if(op == /*decodifica*/){
            cin >> idioma >> text;
            if (idioma_esta (idioma, conjunt)) decodifica (idioma, text);
        }
        
        else if(op == /*consultar taula freq.*/){
            cin >> idioma;
            if (idioma_esta (idioma, conjunt)) consultar_taula_freq (idioma);
        }
        
        else if(op == /*consultar treecode*/){
            cin >> idioma;
            if (idioma_esta (idioma, conjunt)) consultar_Treecode (idioma);
        }
        
        else if(op == /*consultar codis*/){
            cin >> idioma;
            if (idioma_esta (idioma, conjunt)) consultar_taula_codis (idioma);
        }
        
        else op = /*acabar*/;
        
        cin >> op;
    }
    
}
