/** @file Cjt_Idiomes.cc
    @brief Implementació de la classe Cjt_Idiomes
 */
#include "Cjt_Idiomes.hh"
using namespace std;

Cjt_Idiomes::Cjt_Idiomes() {}

Cjt_Idiomes::~Cjt_Idiomes() {}

void Cjt_Idiomes::omplir_cjt_idiomes(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        string nom;
        cin >> nom;
        Idioma idioma(nom);
        cjt_idiomes.insert(pair <string,Idioma> (nom, idioma));
    }
}

void Cjt_Idiomes::actualitza_idioma(string nomidioma){
    Taula_de_freq taula;
    taula.llegir_taula_freq();
    map<string,Idioma> ::iterator it = cjt_idiomes.find(nomidioma);
    it->second.consultar_taula_freq().sumar_taules(taula);
    it->second.actualitzar_treecode();
    it->second.actualitza_taulacodis();
}

void Cjt_Idiomes::afegir_modificar_idioma (const string& nomidioma) {
    if ( not idioma_esta(nomidioma) ) {
        Idioma idioma (nomidioma);
        cjt_idiomes.insert(pair <string,Idioma> (nomidioma, idioma));
    }
    else actualitza_idioma(nomidioma);
}
        
        
bool Cjt_Idiomes::idioma_esta(string idioma) {
    map<string,Idioma>::iterator it = cjt_idiomes.find(idioma);
    return (it!=cjt_idiomes.end());
}

void Cjt_Idiomes::escriure_treecode(string nomidioma){
    map<string,Idioma> ::iterator it = cjt_idiomes.find(nomidioma);
    cout << "Treecode de " << nomidioma << ":" << endl;
    if(it != cjt_idiomes.end()){
        it->second.escriure_treecode();
    }
    else {
        cjt_idiomes.erase(nomidioma);
        cout << "El idioma no existe" << endl;
    }
    cout << endl;
}

void Cjt_Idiomes::escriure_taulacodis(string nomidioma, string s){
    map<string,Idioma>::iterator it = cjt_idiomes.find(nomidioma);
    if(s != "todos"){
        cout << "Codigo de " << s << " en " << nomidioma << ":" << endl;
        if(it != cjt_idiomes.end())it->second.escriure_taulacodis(s);
        else {
            cjt_idiomes.erase(nomidioma);
            cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
        }
    }
    else if(it != cjt_idiomes.end()){
        if (s == "todos") cout << "Codigos de " << nomidioma << ":" << endl;
        it->second.escriure_taulacodis(s);
    }
    else {
        cjt_idiomes.erase(nomidioma);
        cout << "Codigos de " << nomidioma << ":" << endl;
        cout << "El idioma no existe" << endl;
    }
    cout << endl;
}

void Cjt_Idiomes::escriure_taulafreq(string nomidioma){
    map<string,Idioma> ::iterator it = cjt_idiomes.find(nomidioma);
    cout << "Tabla de frecuencias de " << nomidioma << ":" << endl;
    if(it != cjt_idiomes.end()){
        (*it).second.escriure_taulafreq();
    }
    else {
        cjt_idiomes.erase(nomidioma);
        cout << "El idioma no existe" << endl;
    }
    cout << endl;    
}

void Cjt_Idiomes::escriure_cjt(){
    map<string,Idioma>::iterator it;
    for(it = cjt_idiomes.begin(); it != cjt_idiomes.end(); ++it){
        cout << it->first << " " << it->second.consultar_taula_freq().Taula_de_freq::consultar_taula_freq().size() << endl;
    }
}

string Cjt_Idiomes::decodifica(string idioma, string& text) {
    idioma = "a";
    text = "a";
    return 0;
}

string Cjt_Idiomes::codifica(string idioma, string& text) {
    idioma = "a";
    text = "a";
    return 0;
}
