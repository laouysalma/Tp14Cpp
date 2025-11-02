#include<iostream>
using namespace std ;

int division(int a , int b){
    if(b==0)
    throw "division par zero detecte";
    return a/b;
}
int main(){
    try{
        cout<<division(1,0)<<endl;
    }catch (const char* msg){
        cerr<<"Erreur !!: "<<msg<<endl;
}
}