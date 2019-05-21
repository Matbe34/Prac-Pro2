/** @file Idioma.hh
    @brief Especificació de la classe Idioma
 */

#ifndef _Idioma_HH_
#define _Idioma_HH_

#include "Taula_de_freq.hh"
#include "Treecode.hh"
using namespace std;

/** @class Idioma
    @brief Representa un Idioma
    */
class Idioma {

private:

    /** @brief Representa el nom de l'idioma
    */
    string nom_idioma;

    /** @brief Representa la taula de freqüències de l'idioma
    */
    Taula_de_freq taulafreq;

    /** @brief Representa el Treecode de l'idioma
    */
    Treecode treecode;

    /** @brief Representa la taula de decodificació de l'idioma
    */
    map <string, string> taulacodis;


public:

// Constructores

    /** @brief Crea un Idioma amb el seu nom.
      \pre <em>cert</em>
      \post S'ha creat un idioma amb el nom.
    */
    Idioma ( string nom );


//  Destructora

    /** @brief És la destructora de la classe.
    */
    ~Idioma ();


// Modificadores

    /** @brief Actualitza el treecode de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post S'ha actualitzat el treecode del paràmetre implícit
    */
    void actualitzar_treecode();

    /** @brief Actualitza la taula de codis de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post S'ha actualitzat la taula de codis del paràmetre implícit
    */
    void actualitza_taulacodis();

    /** @brief Modifica la taula de freqüències del paràmetre implícit canviant-la per la del paràmetre per referència.
      \pre <em>cert</em>
      \post S'ha canviat la taula de codis del paràmetre implícit per la taula tauladefreq.
    */
    void modifica_taula_freq(Taula_de_freq& tauladefreq);


//  CONSULTRES

    /** @brief Consulta la taula de freqüències de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna la taula de freqüències del paràmetre implícit
    */
    Taula_de_freq consultar_taula_freq();

    /** @brief Codifica una sequència passada per referència
      \pre <em>cert</em>
      \post A "s" hi ha la codificació de "text", si no es pot codificar "text" en l'idioma llavors "s" és buida i "i" indica la posició del l'últim caràcter que s'ha pogut codificar.
    */
    void codifica(string& text, int& i, string& s);

    /** @brief Deodifica una sequència passada per referència
      \pre <em>cert</em>
      \post A "resultat" hi ha la decodificació de "text", si no es pot codificar "text" en l'idioma llavors "resultat" és buit i "i" indica la posició del l'últim caràcter que s'ha pogut decodificar.
      A "b" indiquem amb "false" si no s'ha pogut fer la decodificació.
    */
    void decodifica(string& text, int& i, string& resultat, bool& b, int& ultim);


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

    /** @brief Escriu la taula de freqüències de l'idioma del paràmetre implícit.
      \pre <em>Cert</em>
      \post S'ha escrit la taula de freqüència pel canal estàndard de sortida
    */
    void escriure_taulafreq();

};
#endif
