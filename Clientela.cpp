#include "Clientela.h"

#include <sstream>
#include <iostream>

Clientela::Clientela(): indCliente(0){};

//Crea un objeto cliente y lo agrega al arreglo clientes.
void Clientela::creaCliente(std::string nom, std::string ubi,
                                      int pas, std::string nec){

  if( indCliente < MAXC ){
    clientes[ indCliente ] = Cliente(nom, ubi, pas, nec);
    indCliente++ ;
  }else{
    std::cout<< " no es posible crear cliente";
  }
}

//Crea un objeto cliente y lo agrega al arreglo clientes.
void Clientela::creaCliente(std::string nom, std::string ubi,
                                      int pas){

  if( indCliente < MAXC ){
    clientes[ indCliente ] = Cliente(nom, ubi, pas);
    indCliente++ ;
  }else{
    std::cout<< " no es posible crear cliente";
  }
}



// elimina el objeto cliente y recorre los demás.
void Clientela::eliminaCliente(int indice){
  if (indice < indCliente) {
    for (int i = indice; i < indCliente; i++){
          clientes[i] = clientes[i + 1];
    }

    clientes[indCliente] = Cliente();
    indCliente-- ;
  }else{
    std::cout<< " no es posible borrar cliente";
  }
}

//Muestra los clientes con necesidades específicas.
std::string Clientela::filtraNecesidad(std::string necesidad){

  std::stringstream ss;
  ss << "clientes con necesidad : "<< necesidad << std::endl;

  for (int i = 0; i < indCliente; i++){
    if(clientes[i].getNecesidad() == necesidad){
      ss << clientes[i].toString();
    }
  }

  return ss.str();
}

// Devuelve el objeto en esa posición del arreglo.
Cliente Clientela::consultaCliente(int indice){
  if(indice < indCliente && indice < MAXC){
    return clientes[indice];
  }
  return Cliente();
}


// modifica el objeto en esa posición del arreglo.
void Clientela::modificaCliente(int indice, std::string at, std::string val){
  if(at == "estatus"){
      if (val == "true"){
        clientes[indice].setEstatus(true);
      }else{
        clientes[indice].setEstatus(false);
      }
  }else if (at == "nombre"){
    clientes[indice].setNombre(val);
  }else if (at == "ubicacion"){
    clientes[indice].setUbicacion(val);
  }else if (at == "necesidad"){
    clientes[indice].setNecesidad(val);
  }
}



//Devuelve la información de los clientes en formato string
std::string Clientela::toString(){
  std::stringstream ss;

  ss << "Clientela : " << std::endl;
  for (int i = 0; i < indCliente; i++){
    ss << clientes[i].toString();
  }
  return ss.str();
}
