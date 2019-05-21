/** @file Treecode.hh
    @brief Especificació de la classe Treecode
 */

#include "Taula_de_freq.hh"
#ifndef NO_DIAGRAM
#include <utility>
#include "BinTree.hh"
#endif

/** @class Treecode
    @brief Representa una Treecode
    */

class Treecode {

private:

    /** @brief Representa l'arbre binari segons la freqüència de cada caràcter
    */
    BinTree<pair<string, int> > treecode;

    /** @brief Escriu l'arbre del paràmetre per referència en preordre
      \pre <em>Cert</em>
      \post S'ha escrit l'arbre pel canal de sortida
    */
    static void escriure_BinTree_preordre(const BinTree <pair<string, int> >& a);

    /** @brief Escriu l'arbre a del paràmetre per referència en inordre
      \pre <em>Cert</em>
      \post S'ha escrit l'arbre pel canal de sortida
    */
    static void escriure_BinTree_inordre(const BinTree <pair<string, int> >& a);

    /** @brief Busca la codificació d'un caràcter en un arbre
      \pre <em>Cert</em>
      \post Codi = a la codificaió del caràcter que s'ha passat per referència a petita, el booleà b indica quan s'ha arribat a la fulla de l'arbre per aturar la recursivitat.
    */
    void cerca_aux(const BinTree<pair<string,int> >& t, const string& petita, bool& b, string& codi);

    /** @brief Retorna l'arbre de l'objecte Treecode del paràmetre implícit
      \pre <em>Cert</em>
      \post Retorna un BinTree que és l'arbre de l'objecte del paràmetre implícit.
    */
    BinTree<pair<string,int> > consultar_arbre() const;

public:

//  Constructora i destructora

    /** @brief Crea un Treecode
      \pre <em>Cert</em>
      \post S'ha creat un Treecode
    */
    Treecode();

    /** @brief Crea un Treecode a partir del valor de l'arrel
      \pre <em>Cert</em>
      \post S'ha creat un Treecode on l'arrel té per valor el parell a.
    */
    Treecode(const pair<string, int>& a);

    /** @brief Crea un Treecode a partir del valor de l'arrel i dels seus dos fills
      \pre <em>Cert</em>
      \post S'ha creat un Treecode on l'arrel té per valor el parell a, el seu fill esquerre és igual a left i el seu fill dret és igual a right.
    */
    Treecode(const pair<string, int>& a, const Treecode& left, const Treecode& right);


//  Destructora

    /** @brief És la destructora de la classe.
    */
    ~Treecode();


//  Modificodores

    /** @brief Actualitza un Treecode a partir d'una taula de freqüències
      \pre El Treecode existeix
      \post S'ha actualitzat el Treecode
    */
    void actualitzar_treecode (Taula_de_freq& taula);

    /** @brief Decodifica un codi en una sequència de caràcters de l'idioma
      \pre <em>Cert</em>
      \post A resposta hi ha la sequència text decodificada si es pot decodificar i sinó queda buida
    */
    void decodifica(const Treecode& arbre, string& text, int& i, string& resposta);


//  Consultores

    /** @brief Consulta el codi associat a una sequència de caràcters
      \pre <em>Cert</em>
      \post Retorna una string amb la sequència paraula codificada, si paraula no es pot codificar retorna una string buida.
    */
    string consultar_codi(const string& paraula);

    /** @brief Indica l'ordre d'un conjunt de Treecodes
      \pre <em>Cert</em>
      \post Retorna "cert" si la freqüència del primer Treecode és més petita que la del segon, si son iguals retorna cert si el caràcter del primer és més petit lexicogràficament que el segon..
    */
    struct comp;


//  Escriptura

    /** @brief Escriu el Treecode
      \pre El Treecode existeix
      \post S'ha escrit pel canal estàndard de sortida el Treecode
    */
    void escriure_treecode (const Treecode& arbre)const;

};
