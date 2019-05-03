/** @file Treecode.cc
    @brief Implementació de la classe Treecode
 */
#include "Treecode.hh"
#ifndef NO_DIAGRAM
#include <set>
#endif
using namespace std;

Treecode::Treecode(){}

Treecode::Treecode(const pair<string, int>& a){
    treecode = BinTree <pair<string, int> > (a);
}

Treecode::Treecode(const pair<string, int>& a, const BinTree<pair<string, int> >& left, const BinTree<pair<string, int> >& right){
    treecode = BinTree <pair<string, int> > (a,left,right);
}

struct comp {
    bool operator() (const Treecode& a, const Treecode& b) const{
        if(a.consultar_arbre().value().second != b.consultar_arbre().value().second)return a.consultar_arbre().value().second < b.consultar_arbre().value().second;
        else return a.consultar_arbre().value().first < b.consultar_arbre().value().first;
    }
};


Treecode::~Treecode(){}

void Treecode::actualitzar_treecode (Taula_de_freq& taula){
    
    set<Treecode, comp> cjarbres;
    map<string,int> taulafreq = taula.consultar_taula_freq();
    map<string,int>::iterator it = taulafreq.begin();
    
    while(it != taulafreq.end()){
        Treecode a(pair<string,int> ((*it).first, it->second));
        cjarbres.insert(a);
        ++it;
    }
    while(cjarbres.size()>1){
        set<Treecode,comp>::iterator it = cjarbres.begin();
        BinTree<pair<string,int> > left = (*it).treecode;
        cjarbres.erase(it);
        it = cjarbres.begin();
        BinTree<pair<string,int> > right = (*it).treecode;
        cjarbres.erase(it);
        int n;
        string s;
        if(not left.empty() and not right.empty()){
            n = left.value().second;
            int ni = right.value().second;
            n += ni;
            s = left.value().first;
            string se = right.value().first;
            if(s < se)s = s + se;
            else s = se + s;
        }
        Treecode aux1 (pair<string,int> (s,n),left,right);
        aux1.treecode.right() = right;
        pair<set<Treecode,comp>::iterator,bool> ret;
        ret = cjarbres.insert(aux1);
    }
    set<Treecode,comp>::iterator it3 = cjarbres.begin();
    treecode = (*it3).treecode;
}

BinTree<pair<string,int> > Treecode::consultar_arbre() const{
    return treecode;
}    

void Treecode::consultar_paraula(string& codi){
    codi = "a";
}

void Treecode::escriure_treecode(const Treecode& arbre)const{    
    cout << "recorrido en preorden:" << endl;
    escriure_BinTree_preordre(arbre.treecode);
    cout << "recorrido en inorden:" << endl;
    escriure_BinTree_inordre(arbre.treecode);
}

void Treecode::escriure_BinTree_preordre(const BinTree <pair<string, int> >& a)const{
    if(not a.empty()){
        pair<string,int> x = a.value();
        cout << x.first << " " << x.second<< endl;
        escriure_BinTree_preordre(a.left());
        escriure_BinTree_preordre(a.right());
    }
}

void Treecode::escriure_BinTree_inordre(const BinTree <pair<string, int> >& a)const{
    if(not a.empty()){
        escriure_BinTree_inordre(a.left());
        pair<string,int> x = a.value();
        cout << x.first << " " << x.second<< endl;
        escriure_BinTree_inordre(a.right());        
    }
}

bool string_esta(const string& gran, const string& busca){
    if(gran.find(busca) == -1) return false;
    return true;
}

string Treecode::consultar_codi(const string& paraula){
    bool b;
    string codi,aux;
    b = cerca_aux(treecode,paraula,b,codi);
    int n = codi.length();
    for(int i = 0; i < n/2; ++i){
        aux[0] = codi[i];
        codi[i] = codi[n-1-i];
        codi[n-1-i] = aux[0];
    }
    return codi;
}
            
            
            
            
bool Treecode::cerca_aux(const BinTree<pair<string,int> >& t, const string& petita, bool& b, string& codi){
    if(t.empty())b = false;
    else if(t.value().first == petita) {
        b = true;
    }
    else {
        if(string_esta(t.left().value().first,petita)){
            cerca_aux(t.left(),petita,b,codi);
            if(b)codi += "0";
        }
        else if(string_esta(t.right().value().first,petita)){
            cerca_aux(t.right(),petita,b,codi);
            if(b)codi += "1";
        }
    }
    return false;
}
            
    
    
    
    
    
    
    
    
    
