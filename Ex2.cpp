#include<iostream>
#include<exception>
using namespace std;

class StockInsuffisantException:public exception{
    public :
    const char* what()const  noexcept override{
        return " desole le stock est  insuffisant ";
    }
};
class Produit {
    public :
      int stock;
      Produit(){stock=10;}
      int Vendre(int quantite){
        if(quantite<=stock){
            stock-=quantite;
            return stock;
        }
        else{
           throw StockInsuffisantException(); 
        }
      }
};

int main (){
    Produit p;
    try{ 
       cout<<p.Vendre(15)<<endl;
    }catch( const StockInsuffisantException& e){
        cout<<e.what();
    }
   
}