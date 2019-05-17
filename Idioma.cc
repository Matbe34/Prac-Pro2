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
    taulacodis.clear();
    map<string,int> taulafreq1 = taulafreq.consultar_taula_freq();
    map<string,int>::iterator it = taulafreq1.begin();
    while(it != taulafreq1.end()){
        string s = treecode.consultar_codi(it->first);
        pair<string,string> a (it->first,s);
        taulacodis.insert(a);
        ++it;
    }
}

Taula_de_freq Idioma::consultar_taula_freq(){
    return taulafreq;
}

void Idioma::modifica_taula_freq(Taula_de_freq& tauladefreq){
    taulafreq = tauladefreq;
}

void Idioma::codifica(string& text, int& i, string& resultat){
    i = 0;
    bool b = true;
//     string resultat;
    while(text.length() > i and b){
        if(text[i] >= 0){
            if(taulacodis.find(text.substr(i,1)) == taulacodis.end()){
                cout << "El texto no pertenece al idioma; primer caracter que falla: " << text[i] << endl << endl;
                b = false;
            }
            else resultat += taulacodis.find(text.substr(i,1))->second;
        }
        else if(i+1 < text.length()){
            if(taulacodis.find(text.substr(i,2)) == taulacodis.end()){
                cout << "El texto no pertenece al idioma; primer caracter que falla: " << text.substr(i,2) << endl << endl;
                b = false;
            }
            else {
                resultat += taulacodis.find(text.substr(i,2))->second;
                ++i;
            }
        }
        ++i;
    }
    if(b) cout << resultat << endl << endl;
}

void Idioma::decodifica(string& text, int& i, string& resultat){
  i = 0;
  int count = 0;
  string codi;
  while(text.length() > i){
    codi += text[i];
    if(tauladec.find(codi) != tauladec.end()){
      resultat += tauladec.find(codi)->second;
      codi = "";
      count = i;
      ++count;
    }
    ++i;
  }
  if(not resultat.empty()) cout << resultat << endl << endl;
  else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << count << endl << endl;
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
