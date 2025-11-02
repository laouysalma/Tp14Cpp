#include<iostream>
#include <fstream>
#include <exception>
using namespace std;

class FichierIntrouvableException:public exception{
    public:
    const char* what()const  noexcept override{
        return " Lecture impossible fichier introuvable!!!";
    }
};
void lireFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {  
        throw FichierIntrouvableException();
    }

string ligne;
    while (getline(fichier, ligne)) {  
        cout << ligne << endl;
    }
 fichier.close();

}
int main(){
   string nom = "test.txt";
   string nom2="test2.txt";
   try{
       lireFichier(nom);
   }catch(FichierIntrouvableException& e){
    cout<<e.what()<<endl;
   }
  try{
       lireFichier(nom2);
   }catch(FichierIntrouvableException& e){
    cout<<e.what()<<endl;
   }

}

