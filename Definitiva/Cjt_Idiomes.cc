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

void Cjt_Idiomes::actualitza_idioma(const string& nomidioma){
    Taula_de_freq taula;
    taula.llegir_taula_freq();
    map<string,Idioma> ::iterator it = cjt_idiomes.find(nomidioma);
    it->second.consultar_taula_freq().sumar_taules(taula);
    it->second.modifica_taula_freq(taula);
    it->second.actualitzar_treecode();
    it->second.actualitza_taulacodis();
}

void Cjt_Idiomes::afegir_modificar_idioma (const string& nomidioma) {
    if ( not idioma_esta(nomidioma) ) {
        Idioma idioma (nomidioma);
        cjt_idiomes.insert(pair <string,Idioma> (nomidioma, idioma));
        cout << "Anadido " << nomidioma << endl << endl;
    }
    else {
        actualitza_idioma(nomidioma);
        cout << "Modificado " << nomidioma << endl << endl;
    }
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

void Cjt_Idiomes::decodifica(string idioma, string& text) {
    map<string,Idioma>::iterator it = cjt_idiomes.find(idioma);
    int i = 0;
    string resultat;
    bool b = true;
    it->second.decodifica(text,i,resultat,b);
    if(b)cout << resultat << endl << endl;
    else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << i-1 << endl << endl;
}

void Cjt_Idiomes::codifica(string idioma, string& text) {
    map<string,Idioma>::iterator it = cjt_idiomes.find(idioma);
    int i = 0;
    bool primer = true, b = true;
    string resultat;
    string po;
    while(text.length() > i){
        if(not primer and resultat.length() == 0){
            b = false;
            break;
        }
        it->second.codifica(text,i,resultat,po);
        primer = false;
    }
    if(resultat.length() == 0 and b){
        string s;
        s += text[0];
        if(s == text)cout << "El texto no pertenece al idioma; primer caracter que falla: " << text[0] << endl << endl;
        else {
            s += text[1];
            cout << "El texto no pertenece al idioma; primer caracter que falla: " << s << endl << endl;
        }
    }
    else if(b)cout << resultat << endl << endl;
    else if(text[i] < 127 and text[i] > 32)cout << "El texto no pertenece al idioma; primer caracter que falla: " << text[i+1] << endl << endl; //Distingir entre char i char especial
    else cout << "El texto no pertenece al idioma; primer caracter que falla: " << po << endl << endl;
}
