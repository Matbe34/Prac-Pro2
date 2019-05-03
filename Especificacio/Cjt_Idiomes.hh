/** @file Cjt_Idiomes.hh
    @brief Especificació de la classe Cjt_Idiomes
 */

#ifndef _Cjt_Idiomes_HH_
#define _Cjt_Idiomes_HH_

#include "Idioma.hh"
#ifndef NO_DIAGRAM
#endif

using namespace std;

/** @class Cjt_Idiomes
    @brief Representa un Cjt_Idiomes
    */
class Cjt_Idiomes {
    
private:
    
    map<string,Idioma> cjt_idiomes;
    
public:
    
    //  Contructores
    
    
    /** @brief Crea un conjunt d'idiomes buit
      \pre <em>Cert</em>
      \post S'ha creat un conjunt d'idiomes buit
    */
    Cjt_Idiomes();
    
    
//  Destructora
    
    ~Cjt_Idiomes();
    
    
 // Modificadores
    
    /** @brief Omple un conjunt d'idiomes amb n idiomes
      \pre Conj buit, n>=0, llista d'idiomes en el canal d'entrada
      \post El conjunt d'idiomes ha quedat ple amb els n idiomes del canal d'entrada
    */
    void omplir_cjt_idiomes();
    
    /** @brief Afegeix un idioma o el modifica
      \pre <em>cert</em>
      \post El paràmetre implícit s'hi ha afegit l'idioma si no hi era, sinó, s'ha modificat l'idioma sumant les freqüències. 
    */
    void afegir_modificar_idioma (const string& idioma);
    
    
    //  CONSULTRES
    
    /** @brief Codifica un text en un idioma
      \pre L'idioma es troba al conjunt
      \post Si el text es pot codificar, retorna un string amb el text codificat, sinó, informa de que no el text no pertany a l'idioma
    */
    string codifica(string idioma, string& text);
    
    /** @brief Decodifica un text en un idioma 
      \pre L'idioma es troba al conjunt
      \post Si el text codificat pertany a l'idioma, retorna un string amb el text de codificat, sinó, informa de que no el text no pertany a l'idioma
    */
    string decodifica(string idioma, string& text);
    
    /** @brief Consulta la taula de freq del idioma en el paràmetre implícit
      \pre L'idioma es troba al conjunt
      \post Retorna la taula de freq del idioma especificat
    */
    void consultar_taula_freq (string idioma);
    
    
    /** @brief Comprva si un idioma es troba al conjunt o no
      \pre <em>Cert</em>
      \post Retorna un boleà en funció de si l'idioma es troba al paràmetre implícit o no
    */
    bool idioma_esta(string idioma);
    
    /** @brief Actualitza el treecode, la taula de codis i la taula de freqüències del idioma passat com a paràmetre.
      \pre <em>Cert</em>
      \post L'idioma ha quedat actualitzat amb les noves freqüències i codis.
    */
    void actualitza_idioma(string nomidioma);
    
    
    
    // Lectura i escriptura
    
    /** @brief Escriu el treecode del paràmetre implícit.
      \pre <em>Cert</em>
      \post S'ha escrit el treecode pel canal estàndard de sortida
    */
    void escriure_treecode(string nomidioma);
    
    /** @brief Escriu la taula de codis del paràmetre implícit.
      \pre <em>Cert</em>
      \post S'ha escrit la taula de codis pel canal estàndard de sortida
    */
    void escriure_taulacodis(string nomidioma, string s);
    
    /** @brief Escriu la taula de freqüències del paràmetre implícit
      \pre <em>Cert</em>
      \post S'ha escrit la taula de freqüències pel canal estàndard de sortida
    */
    void escriure_taulafreq(string nomidioma);
    
    

    
};
#endif
