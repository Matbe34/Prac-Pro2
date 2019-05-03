/**
 * @mainpage Gestió de la codificació i la decodificació en funció de diferents idiomes.
 En aquesta pàgina hi ha l'especificació de la pràctica de PRO2 de 2019.
 
 En ella apareixen els arxius on s'especifiquen les funcions que fa servir el programa principal program.cc
 

*/

/** @file program.cc
    @brief Programa principal per la gestió de codificar i descodificar.
*/

#include "Cjt_Idiomes.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

int main() {
    
    Cjt_Idiomes conjunt;
    conjunt.omplir_cjt_idiomes();
    
    string op;
    string nomidioma, text;
    while(op != "fin"){
        
        if(op == "añadir" or op == "modificar"){
            cin >> nomidioma;
            conjunt.afegir_modificar_idioma (nomidioma);
        }
        
        else if(op == "codifica"){
            cin >> nomidioma >> text;
            if (conjunt.idioma_esta (nomidioma)) conjunt.codifica(nomidioma, text);
        }
        
        else if(op == "decodifica"){
            cin >> nomidioma >> text;
            if (conjunt.idioma_esta (nomidioma)) conjunt.decodifica(nomidioma, text);
        }
        
        else if(op == "tabla_frec"){
            cin >> nomidioma;
            if (conjunt.idioma_esta (nomidioma)) conjunt.escriure_taulafreq(nomidioma);
        }
        
        else if(op == "treecode"){
            cin >> nomidioma;
            if (conjunt.idioma_esta (nomidioma)) conjunt.escriure_treecode(nomidioma);
        }
        
        else if(op == "codigos"){
            cin >> nomidioma >> text;
            if (conjunt.idioma_esta (nomidioma)) conjunt.escriure_taulacodis(nomidioma, text);
        }
        
        cin >> op;
    }
    
}
