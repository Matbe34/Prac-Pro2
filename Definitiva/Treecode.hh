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
    
    BinTree<pair<string, int> > treecode;
    
    static void escriure_BinTree_preordre(const BinTree <pair<string, int> >& a); 
    
    static void escriure_BinTree_inordre(const BinTree <pair<string, int> >& a); 
    
    bool cerca_aux(const BinTree<pair<string,int> >& t, const string& petita, bool& b, string& codi);
    
    
public:
    
//  Constructora i destructora
    
    /** @brief Crea un Treecode
      \pre <em>Cert</em>
      \post S'ha creat un Treecode
    */
    Treecode();
    
    Treecode(const pair<string, int>& a);
    
    Treecode(const pair<string, int>& a, const Treecode& left, const Treecode& right);
    
    ~Treecode();
    
    
//  Modificodores
    
    /** @brief Actualitza un Treecode
      \pre El Treecode existeix
      \post S'ha actualitzat el Treecode
    */
    void actualitzar_treecode (Taula_de_freq& taula);
    
    void decodifica(const Treecode& arbre, string& text, int& i, string& resposta, bool& b);
    
//  Consultores
    
//     bool operator<(const Treecode& a, const Treecode& b);
    
    BinTree<pair<string,int> > consultar_arbre() const;
        
    void consultar_paraula(string& codi);
    
    string consultar_codi(const string& paraula);
    
//     bool string_esta(string& gran, string& busca);
    
    
//  Escriptura
    
    /** @brief Escriu el Treecode
      \pre El Treecode existeix
      \post S'ha escrit pel canal estàndard de sortida el Treecode
    */
    void escriure_treecode (const Treecode& arbre)const;
    
};
