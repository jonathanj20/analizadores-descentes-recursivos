#include<iostream>
using namespace std;

/*E -> E + T | T
  T -> T*F | F
  F -> (E)
*/

void E();
void T();
void F();

string cadena;
int pos=0;
bool cadenaValida=false;
int t=0, e=0;

int main(){
    cout<<"Ingresa una cadena"<<endl;
    cin>>cadena;

    E();
    if(cadenaValida){
        cout<<"La cadena ingresada es valida"<<endl;
    } else {
        cout<<"La cadena ingresada no es valida"<<endl;
    }

    return 0;
}

void E(){

    if(cadena.substr(pos,1)!="+"){
        cadenaValida=false;
    } else if(cadena.substr(pos,1) == "+"){
        e=1;
        cadenaValida=true;
        pos++;
        T();
    } else {
        pos++;
        T();
        E();
    }
}

void T(){
    if(cadena.substr(pos,1)!="*"){
        cadenaValida=false;
    } else if(cadena.substr(pos,1) == "*"){
        t=1;
        cadenaValida=true;
        pos++;
        F();
    } else {
        pos++;
        F();
        T();
    }
}

void F(){
    if(cadena.substr(pos,1) == "("){
        pos++;
        if(cadenaValida && cadena.substr(pos,1)==")"){
            cadenaValida=true;
        } else if(cadena.substr(pos,1) == "i") {
            cadenaValida=true;
        } else {
            cadenaValida=false;
            F();
        }
    } else {
        cadenaValida = false;
        F();
    }
}

