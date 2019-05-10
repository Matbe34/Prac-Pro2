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
    
    void escriure_BinTree_preordre(const BinTree <pair<string, int> >& a)const; //static?
    
    void escriure_BinTree_inordre(const BinTree <pair<string, int> >& a)const; //static?
    
    bool cerca_aux(const BinTree<pair<string,int> >& t, const string& petita, bool& b, string& codi); //static?
    
    
public:
    
//  Constructora i destructora
    
    /** @brief Crea un Treecode
      \pre <em>Cert</em>
      \post S'ha creat un Treecode
    */
    Treecode();
    
    Treecode(const pair<string, int>& a);
    
    Treecode(const pair<string, int>& a, const BinTree<pair<string, int> >& left, const BinTree<pair<string, int> >& right); //private
    
    ~Treecode();
    
    
//  Modificodores
    
    /** @brief Actualitza un Treecode
      \pre El Treecode existeix
      \post S'ha actualitzat el Treecode
    */
    void actualitzar_treecode (Taula_de_freq& taula);
    
    void decodifica(const BinTree <pair<string, int> >& treecode, string& text, int& i, string& resposta, bool& b); //private
    
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
