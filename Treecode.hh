/** @file Treecode.hh
    @brief Especificació de la classe Treecode
 */

#ifndef _Treecode_HH_
#define _Treecode_HH_

#include "Taula_de_freq.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <utility>
#endif

using namespace std;

/** @class Treecode
    @brief Representa un Treecode
    */

class Treecode {
    
private:
    
    BinTree < pair < string, int> > treecode;
    
public:
    
//  Constructora
    
    /** @brief Crea un Treecode buit
      \pre <em>Cert</em>
      \post S'ha creat un Treecode buit
    */
    Treecode();
    
    
//  Modificodores
    
    /** @brief Actualitza el Treecode que s'ha passat per referènica després de que es modifiquessin les freqüències
      \pre <em>Cert</em>
      \post S'ha actualitzat el Treecode amb la suma de les freqüències de les dues taules
    */
    void actualitzar_treecode (Treecode& treecode);
    
    
//  Escriptura
    
    /** @brief Escriu el Treecode en (preordre/inordre/postordre) pel canal estàndard de sortida
      \pre <em>Cert</em>
      \post S'ha escrit pel canal estàndard de sortida el Treecode en (preordre/inordre/postordre)
    */
    void escriure_treecode (Treecode& treecode) const;
    
    
};
#endif
