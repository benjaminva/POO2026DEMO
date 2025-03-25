#include "Vehiculo.h"
#include <sstream>



// Constructor por defecto
//Inicializa el vehículo con valores por defecto.
Vehiculo::Vehiculo(): id(0), marca(""),conductor(""),tipo(""), ubicacion(""),
                      precio(0.0), asientos(0){}


// Constructor con parámetros
// Inicializa el vehículo con los valores proporcionados.
Vehiculo::Vehiculo(int id, std::string marca,
              std::string conductor, std::string tipo,
              std::string ubicacion, float precio, int asientos):
                id(id), marca(marca), conductor(conductor), tipo(tipo),
                ubicacion(ubicacion), precio(precio), asientos(asientos){}

// Implementación de Getters

// Devuelve  ID del vehículo
int Vehiculo::getId(){
  return id;
}

// Devuelve Marca del vehículo
std::string Vehiculo::getMarca(){
  return marca;
}

// Devuelve Nombre del conductor
std::string Vehiculo::getConductor(){
  return conductor;
}

// Devuelve Tipo de vehículo
std::string Vehiculo::getTipo(){
  return tipo;
}

// Devuelve ubicación
std::string Vehiculo::getUbicacion(){
  return ubicacion;
}

// Devuelve número de asientos
int Vehiculo::getAsientos(){
  return asientos;
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

// Establece la Ubicacion del vehículo
void Vehiculo::setUbicacion(std::string ubi){
  ubicacion = ubi;
}

// Esstablece el precio del vehículo
void Vehiculo::setPrecio(float pre){
  precio = pre;
}

// Esstablece el número de asientos del vehículo
void Vehiculo::setAsientos(int asi){
  asientos = asi;
}

// Calclula el costo del tipo de auto
float Vehiculo::calculaTarifa(){

  float modificador = 1;

  if (tipo == "camioneta"){
    modificador = 1.5;
  }else if (tipo == "especial"){
    modificador = 2.0;
  }

  return  precio * modificador;
}

// Devuelve la información del objeto en formato string
std::string Vehiculo::toString(){
  std::stringstream ss;
  ss << " id : " << id << std::endl
   << " marca : " << marca << std::endl
   << " conductor : "<< conductor << std::endl
   << " tipo : " << tipo << std::endl
   << " ubicacion : " << ubicacion << std::endl
   << " precio : " << precio << std::endl
   << " asientos : " << asientos  << std::endl;

   return ss.str();
}
