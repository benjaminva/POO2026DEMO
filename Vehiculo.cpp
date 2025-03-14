#include "Vehiculo.h"

// Constructor por defecto
//Inicializa el vehículo con valores por defecto.
Vehiculo::Vehiculo(): id(0), marca(""),conductor(""),tipo(""){}


// Constructor con parámetros
// Inicializa el vehículo con los valores proporcionados.
Vehiculo::Vehiculo(int id, std::string marca,
              std::string conductor, std::string tipo):
              id(id), marca(marca),conductor(conductor),tipo(tipo){}

// Implementación de Getters

// Devuelve  ID del vehículo
int Vehiculo::getId(){
  return id;
}

// Devuelve  Marca del vehículo
std::string Vehiculo::getMarca(){
  return marca;
}


// Devuelve  Nombre del conductor
std::string Vehiculo::getConductor(){
  return conductor;
}

// Devuelve  Tipo de vehículo
std::string Vehiculo::getTipo(){
  return tipo;
}

// Implementación de Setters

// Establece la marca del vehículo
void Vehiculo::setMarca(std::string ma){
  marca = ma;
}


// Establece el nombre del conductor
void Vehiculo::setConductor(std::string cu){
  conductor = cu;
}
