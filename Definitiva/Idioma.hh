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
    
    string nom_idioma;
    Taula_de_freq taulafreq;
    Treecode treecode;
    map <string, string> taulacodis;
    
    
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
    void actualitzar_treecode();
    
    /** @brief Actualitza la taula de codis de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post S'ha actualitzat la taula de codis del paràmetre implícit 
    */
    void actualitza_taulacodis();
    
    void modifica_taula_freq(Taula_de_freq& tauladefreq);
    
    
    //  CONSULTRES
    
    /** @brief Consulta la taula de freqüències de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna la taula de freqüències del paràmetre implícit
    */
    Taula_de_freq consultar_taula_freq();
    
    void codifica(string& text, int& i, string& s);
    
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
    
    void escriure_taulafreq();
    
};
#endif
