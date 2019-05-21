/** @file Taula_de_freq.hh
    @brief Especificació de la classe Taula_de_freq
 */

#ifndef _Taula_de_freq_HH_
#define _Taula_de_freq_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include <iostream>
#endif

using namespace std;

/** @class Taula_de_freq
    @brief Representa una Taula_de_freq
    */
class Taula_de_freq {
    
private:
    
    map <string, int> taula;
    
    
public:
    
//  Constructora
    
    /** @brief Crea una taula de freqüències buida
      \pre <em>Cert</em>
      \post S'ha creat una taula de freqüències buida
    */
    Taula_de_freq();
    
    ~Taula_de_freq();
    
//  Modificadores
    
    /** @brief Suma dues taules de freqüències, una que rep pel paràmetre per referència i l'altre la llegeix del canal estàndard d'entrada
      \pre <em>Cert</em>
      \post S'han sumat les taules del paràmetre per referència i la llegida del canal d'entrada
    */
    void sumar_taules (Taula_de_freq& b);
    
    
//  Consultores
    
    /** @brief Consulta la taula de freqüències de l'idioma del paràmetre implícit
      \pre <em>cert</em>
      \post Retorna la taula de freqüències del paràmetre implícit
    */
    map <string, int> consultar_taula_freq();
    
    
//  Lectura
    
    /** @brief Llegeix una taula de freqüències del canal estàndard d'entrada
      \pre <em>Cert</em>
      \post S'ha llegit una taula de freqüències del canal d'entrada
    */
    void llegir_taula_freq ();
    
    /** @brief Escriu la taula de freqüències del paràmetre implícit
      \pre <em>Cert</em>
      \post S'ha escrit la taula de freqüències pel canal estàndard de sortida
    */
    void escriure_taulafreq(Taula_de_freq& taula);
    
};
#endif
