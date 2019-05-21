/** @file Taula_de_freq.cc
    @brief Implementació de la classe Taula_de_freq
 */
#include "Taula_de_freq.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

Taula_de_freq::Taula_de_freq() {}

Taula_de_freq::~Taula_de_freq() {}

void Taula_de_freq::sumar_taules (Taula_de_freq& b){
    
    map<string,int>::iterator it1;
    map<string,int>::iterator it2 = b.consultar_taula_freq().begin();
    for(it1 = taula.begin(); it1 != taula.end(); ++it1){
        it1->second = it1->second + it2->second;
        ++it2;
    }
}

void Taula_de_freq::llegir_taula_freq (){
    int n;
    cin >> n;
    string a;
    int p;
    for(int i = 0; i < n; ++i){
        cin >> a >> p;
        taula.insert(pair <string,int> (a,p));
    }
}

map <string, int> Taula_de_freq::consultar_taula_freq(){
    return taula;
}

void Taula_de_freq::escriure_taulafreq(Taula_de_freq& taulafreq){
    map<string,int>::iterator it1; 
    
    for(it1 = taulafreq.taula.begin(); it1 != taulafreq.taula.end(); ++it1){
        cout << it1->first << " " << it1->second << endl;
    }
}
