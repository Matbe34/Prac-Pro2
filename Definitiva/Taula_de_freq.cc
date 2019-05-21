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
    map<string,int> btaula = b.consultar_taula_freq();
    map<string,int> ::iterator it1 = taula.begin();
    map<string,int> ::iterator it2 = btaula.begin();
    while(not taula.empty()){
        if(it2 != btaula.end()){
            it1 = taula.find(it2->first);
            if(it1 != taula.end())it2->second = it2->second + it1->second;
            taula.erase(it2->first);
            ++it2;
        }
        else {
            it1 = taula.begin();
            btaula.insert(make_pair(it1->first,it1->second));
            taula.erase(it1->first);
        }
    }
    b.modifica_taula(btaula);
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

void Taula_de_freq::modifica_taula(const map <string, int>& btaula){
    taula = btaula;
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
