/** @file Idioma.hh
    @brief Especificació de la classe Idioma
 */

#ifndef _Idioma_HH_
#define _Idioma_HH_

#include "Taula_de_freq.hh"
#ifndef NO_DIAGRAM
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
    BinTree <pair <string, int> > treecode;
    map <char, string> taulacodis;
    
    
public:
    
    // Constructores
    
    /** @brief Crea un Idioma amb el seu nom.
      \pre <em>cert</em>
      \post S'ha creat un idioma amb el nom.
    */
    Idioma ( string nom );
    
    ~Idioma ();

    
    // Modificadores
    
    /** @brief Actualitza el treecode de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post S'ha actualitzat el treecode del paràmetre implícit 
    */
    void actualitza_treecode();
    
    /** @brief Actualitza la taula de codis de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post S'ha actualitzat la taula de codis del paràmetre implícit 
    */
    void actualitza_taulacodis();
    
    
    //  CONSULTRES
    
    /** @brief Consulta la taula de freqüències de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna la taula de freqüències del paràmetre implícit
    */
    Taula_de_freq consultar_taula_freq();
    
    // Lectura i escriptura
    
    /** @brief Escriu el treecode de l'idioma del paràmetre implícit.
      \pre <em>Cert</em>
      \post S'ha escrit el treecode pel canal estàndard de sortida
    */
    void escriure_treecode();
    
    /** @brief Escriu la taula de codis de l'idioma del paràmetre implícit.
      \pre <em>Cert</em>
      \post S'ha escrit la taula de codis pel canal estàndard de sortida
    */
    void escriure_taulacodis(string s);
    
    
};
#endif
