/** @file Taula_de_codis.hh
    @brief Especificació de la classe Taula_de_codis
 */

#ifndef _Taula_de_codis_HH_
#define _Taula_de_codis_HH_

#include "Treecode.hh"

using namespace std;

/** @class Taula_de_codis
    @brief Representa una Taula_de_codis
    */

class Taula_de_codis {
    
private:
    
    map < char, string > taula;
    
public:
    
//  Constructora
    
    /** @brief Crea una taula de codis buida
      \pre <em>Cert</em>
      \post S'ha creat una taula de codis buida
    */
    Taula_de_codis();
    
    
//  Modificadores
    
    /** @brief Actualitza una taula de codis d'un idioma després de  modificar-ne el seu Treecode
      \pre <em>Cert</em>
      \post S'ha actualitzat la taula de codis seguint l'esquema del Treecode de l'idioma
    */
    void actualitzar_taula_codis ( BinTree < pair < string, int> > & treecode);
    
    
//  Escriptura
    
    /** @brief Escriu la taula de codis que rep pel paràmetre per referència
      \pre <em>Cert</em>
      \post S'ha escrit la taula de codis pel canal estàndard de sortida
    */
    void escriure_taula_codis ( const Taula_de_codis& taula, string s) const;
    
    
};
#endif
