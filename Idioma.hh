/** @file Idioma.hh
    @brief Especificació de la classe Idioma
 */

#ifndef _Idioma_HH_
#define _Idioma_HH_

// #include "Taula_de_freq.hh"
// #include "Treecode.hh"
#include "Taula_de_codis.hh"
#ifndef NO_DIAGRAM
// #include<iostream>
#include<map>
#include<utility>
#include "BinTree.hh"
#endif

using namespace std;

/** @class Idioma
    @brief Representa un Idioma
    */
class Idioma {

private:
    
    string nom_idioma;
    Taula_de_freq taulafreq;
    Treecode treecode;
    Taula_de_codis taulacodis;
    
    
public:
    
    // Constructores
    
    /** @brief Crea un Idioma
      \pre <em>cert</em>
      \post S'ha creat un idioma buit
    */
    Idioma();

    
    // Modificadores
    
    /** @brief Afegeix un idioma o el modifica
      \pre <em>cert</em>
      \post El paràmetre implícit s'hi ha afegit l'idioma si no hi era, sinó, s'ha modificat l'idioma sumant les freqüències. 
    */
    void afegir_modificar_idioma();
    
    
//  CONSULTRES
    
    /** @brief Consulta la taula de freqüències del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna la taula de freqüències del paràmetre implícit
    */
    map<string,int> consultar_taula_freq();
    
    /** @brief Consulta el Treecode del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna un BinTree del Treecode del paràmetre implícit
    */
    BinTree< pair < string, int> > consultar_Treecode();
    
    /** @brief Consulta la taula de codis del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna un map amb la taula de codis del paràmetre implícit
    */
    map<string,string> consultar_taula_codis();

    
    // Lectura i escriptura

    
};
#endif
