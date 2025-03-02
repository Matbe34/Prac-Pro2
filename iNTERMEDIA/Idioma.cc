/** @file Idioma.cc
    @brief Implementació de la classe Idioma
 */
#include "Idioma.hh"
using namespace std;

Idioma::Idioma ( string nom ){
    nom_idioma = nom;
    taulafreq.llegir_taula_freq();
    treecode.actualitzar_treecode(taulafreq);
    
    map<string,int> taulafreq1 = taulafreq.consultar_taula_freq();
    map<string,int>::iterator it = taulafreq1.begin();
    while(it != taulafreq1.end()){
        string s = treecode.consultar_codi(it->first);
        pair<string,string> a (it->first,s);
        taulacodis.insert(a);
        ++it;
    }
}

Idioma::~Idioma() {}

void Idioma::actualitzar_treecode(){
    treecode.actualitzar_treecode(taulafreq);
}

void Idioma::actualitza_taulacodis(){
    
}

Taula_de_freq Idioma::consultar_taula_freq(){
    return taulafreq;
}

void Idioma::escriure_treecode() {
    treecode.escriure_treecode(treecode);
}

void Idioma::escriure_taulacodis(string s) {
    if(s == "todos"){
        map<string,string>::iterator it;
        for(it = taulacodis.begin(); it != taulacodis.end(); ++it){
            cout << it->first << " " << it->second << endl;
        }
    }
    else {
        map<string,string>::iterator it = taulacodis.find(s);
        if(it != taulacodis.end())cout << it->first << " " << it->second << endl;
        else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    }
}

void Idioma::escriure_taulafreq(){
    taulafreq.Taula_de_freq::escriure_taulafreq(taulafreq);
}
