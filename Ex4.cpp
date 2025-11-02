#include<iostream>
#include <exception>
using namespace std ;
class SoldeInsuffisantException: public exception{
    public:
    const char* what() const noexcept override {
       return "solde insufisant introduire un autre montant";
    }
};
class MontantInvalideException: public exception{
    public:
    const char* what() const noexcept override {
        return "impossible de deposer ce montant !! ";
    }
};
class Compte{
    public:
    int solde;
    Compte(int s):solde(s){}
    int retirer(int montant){
       if(solde>=montant){
        solde -=montant;
        return solde;
       }else{
        throw SoldeInsuffisantException();
       }
    }
    int deposer(int montant){
        if(montant>=0){
            solde+=montant;
            return solde;
        } else{
        throw MontantInvalideException();
       
    }
}
};
int main(){
    Compte c1(3500);
    try{
    cout<<c1.retirer(4000)<<endl;
    }catch(SoldeInsuffisantException& e1){
     cout<<e1.what()<<endl;
    }

    try{
     cout<<c1.deposer(-15000)<<endl;
    }catch(MontantInvalideException& e2){
     cout<<e2.what()<<endl;
    }

}