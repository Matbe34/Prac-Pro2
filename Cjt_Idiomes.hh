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
    
    void cerca_dicot (const Cjt_Idiomes& conj, const string& nomidioma);
    
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
      \pre L'idioma es triba en el conjunt
      \post Si el text es pot codificar, retorna un string amb el text codificat, sinó, informa de que no el text no pertany a l'idioma
    */
    string codifica(string idioma, string& text);
    
    /** @brief Decodifica un text en un idioma 
      \pre L'idioma es troba al conjunt
      \post Si el text codificat pertany a l'idioma, retorna un string amb el text de codificat, sinó, informa de que no el text no pertany a l'idioma
    */
    string decodifica(string idioma, string& text);
    
    /** @brief Consulta la taula de freq del idioma
      \pre L'idioma es troba al conjunt
      \post Retorna la taula de freq del idioma especificat
    */
    map<string,int> consultar_taula_freq (string idioma);
    
    /** @brief Consulta el Treecode del idioma especificat
      \pre L'idioma es troba al conjunt
      \post Retorna un BinTree del Treecode del idioma especificat
    */
    BinTree< pair < string, int> > consultar_Treecode (string idioma);
    
    /** @brief Consulta la taula de codis del idioma especificat
      \pre L'idioma es troba al conjunt
      \post Retorna un map amb la taula de codis del idioma especificat
    */
    map<string,string> consultar_taula_codis (string idioma, string lletres);
    
    /** @brief Comprva si un idioma es troba al conjunt o no
      \pre <em>Cert</em>
      \post Retorna un boleà en funció de si l'idioma es troba al paràmetre implícit o no
    */
    bool idioma_esta(const string& idioma, const Cjt_Idiomes& conjunt);
    

    
};
#endif
