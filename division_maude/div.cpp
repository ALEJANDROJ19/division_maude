/*
 * ALEJANDROJ19
 * Division de dos números con solo suma, producto y igualdad
 * 
 * Este código esta pensado para emular una sintaxis del lenguaje
 * Maude. Las funciones privadas carecen de los métodos usados
 * en ese lenguaje.
 */

#include <iostream>
#include <string>

using namespace std;

typedef unsigned int nat ;

// Funciones privadas del lenguaje (sinonimos)
bool esIgual(nat i, nat j){
  return i == j;
}
bool esDistinto(nat i, nat j){
  return !esIgual(i,j);
}
nat cero(){
  return 0;
}
nat suma(nat i, nat j){
  return i+j;
}
bool esCero(nat i){
  return i == 0;
}
nat producto(nat i, nat j){
  return i*j;
}
nat sucesor(nat i){
  return i+1;
}


// Funciones privadas recursivas para el problema
bool comp_div_i(nat x, nat d, nat D){
  if(esIgual(x,D)) return true;
  else if(esIgual(sucesor(x), d)) return false;
  else return comp_div_i(sucesor(x),d,D);
}

nat comp_div(nat q, nat d, nat D){
  if( comp_div_i(producto(q,d),producto(d,sucesor(q)),D)) return q;
  else return comp_div(sucesor(q),d,D);
}

// Función de la Division
nat div(nat D, nat d)
//WARN: Returns 0 when x/0 !
{
  if(esIgual(D,d)) return sucesor(cero());
  else return comp_div(cero(),d,D);
}



int main(){
  cout << " 6/2 = " << div(6,2) << endl;
  cout << " 7/2 = " << div(7,2) << endl;
  
  cout << " 8/4 = " << div(8,4) << endl;
  cout << " 9/4 = " << div(9,4) << endl;
  cout << "10/4 = " << div(10,4) << endl;
  cout << "11/4 = " << div(11,4) << endl;
  cout << "12/4 = " << div(12, 4) << endl;
  
  cout << " 8/0 = " << div(8,0) << endl;
  cout << " 7/0 = " << div(7,0) << endl;
  cout << " 1/1 = " << div(1,1) << endl;
  cout << " 0/2 = " << div(0,2) << endl;
  
  cout << "\nKappa" << endl;
}