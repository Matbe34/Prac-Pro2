/**
 * @mainpage Gestió de la codificació i la decodificació en funció de diferent idiomes.
 En aquesta pàgina hi ha l'especificació de la pràctica de PRO2 de 2019.
 
 En ella s'especifiquen els arxius on s'especifiquen les funcions que fa servir el programa principal program.cc
 

*/

/** @file program.cc
    @brief Programa principal per la gestió de codificar i descodificar.
*/

#include "Cjt_Idiomes.hh"
using namespace std;

int main() {
    
    Cjt_Idiomes conjunt;
    conjunt.omplir_cjt_idiomes();
    string op;
    string nomidioma, text;
    while(op != "fin"){
        
        if(op == "anadir/modificar"){
            cin >> nomidioma;
            conjunt.afegir_modificar_idioma (nomidioma);
        }
        
        else if(op == "codifica"){
            cin >> nomidioma >> text;
            cout << "Codifica en " << nomidioma << " el texto:" << endl << text << endl;
            if (conjunt.idioma_esta (nomidioma)) conjunt.codifica(nomidioma, text);
            else cout << "El idioma no existe" << endl << endl;
        }
        
        else if(op == "decodifica"){
            cin >> nomidioma >> text;
            cout << "Decodifica en " << nomidioma << " el texto:" << endl << text << endl;
            if (conjunt.idioma_esta (nomidioma)) conjunt.decodifica(nomidioma, text);
            else cout << "El idioma no existe" << endl << endl;
            
        }
        
        else if(op == "tabla_frec"){
            cin >> nomidioma;
            conjunt.escriure_taulafreq(nomidioma);
        }
        
        else if(op == "treecode"){
            cin >> nomidioma;
            conjunt.escriure_treecode(nomidioma);
        }
        
        else if(op == "codigos"){
            cin >> nomidioma >> text;
            conjunt.escriure_taulacodis(nomidioma, text);
        }
        
        cin >> op;
    }
}
