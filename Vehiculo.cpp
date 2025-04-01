#include "Vehiculo.h"
#include <sstream>



// Constructor por defecto
// Inicializa el vehículo con valores por defecto.
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
int Vehiculo::getId() const {
  return id;
}

// Devuelve Marca del vehículo
std::string Vehiculo::getMarca() const {
  return marca;
}

// Devuelve Nombre del conductor
std::string Vehiculo::getConductor() const {
  return conductor;
}

// Devuelve Tipo de vehículo
std::string Vehiculo::getTipo() const {
  return tipo;
}

// Devuelve ubicación
std::string Vehiculo::getUbicacion() const {
  return ubicacion;
}

// Devuelve número de asientos
int Vehiculo::getAsientos() const {
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
  return  0.0;
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

//Constructor por defetco
Auto::Auto():Vehiculo(){}

//Constructor con parámetros
Auto::Auto(int id, std::string marca, std::string conductor,
    std::string ubicacion, float precio, int asientos):
      Vehiculo(id, marca, conductor, "auto", ubicacion, precio, asientos) {}

// Calclula el costo del tipo de auto
float Auto::calculaTarifa(){
  return  precio;
}

// Devuelve la información del objeto en formato string
std::string Auto::toString(){
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

// Constructor por defetco
Camioneta::Camioneta():Vehiculo(), modTarifa(0){}

// Constructor con parámetros
Camioneta::Camioneta(int id, std::string marca, std::string conductor,
          std::string ubicacion, float precio, int asientos, float modTarifa):
            Vehiculo(id, marca, conductor, "camioneta", ubicacion, precio, asientos),
            modTarifa(modTarifa) {}

// Constructor con parámetros
Camioneta::Camioneta(int id, std::string marca, std::string conductor,
          std::string ubicacion, float precio, int asientos):
            Vehiculo(id, marca, conductor, "camioneta", ubicacion, precio, asientos),
            modTarifa(1.5) {}

// Actualiza el valor del modificador de la tarifa
void Camioneta::setModTarifa( float tar){
  modTarifa = tar;
}

// Devuelve la información del objeto en formato string
std::string Camioneta::toString(){
  std::stringstream ss;
  ss << Vehiculo::toString()
    << " modificador tarifa : " << modTarifa  << std::endl;
  return ss.str();
}


// Calclula el costo del tipo de auto
float Camioneta::calculaTarifa(){
  return  precio * modTarifa;
}


//Constructor por defetco
Especial::Especial():Vehiculo(), modTarifa(0), sillaRuedas(false), cajaMaterial(false),
  pesoMax(0){}


//Constructor con parámetros
Especial::Especial(int id, std::string marca, std::string conductor,
   std::string ubicacion, float precio,
   int asientos, float modTarifa,  bool sillaRuedas,
   bool cajaMaterial, float pesoMax) :
     Vehiculo(id, marca, conductor, "especial", ubicacion, precio, asientos),
     modTarifa(modTarifa), sillaRuedas(sillaRuedas), cajaMaterial(cajaMaterial),
     pesoMax(pesoMax){}

//Constructor con parámetros
Especial::Especial(int id, std::string marca, std::string conductor,
   std::string ubicacion, float precio,
   int asientos, bool sillaRuedas,
   bool cajaMaterial, float pesoMax) :
     Vehiculo(id, marca, conductor, "especial", ubicacion, precio, asientos),
     sillaRuedas(sillaRuedas), cajaMaterial(cajaMaterial), pesoMax(pesoMax){

    if (sillaRuedas == true){
      modTarifa = 2.0;
    }else if (cajaMaterial == true){
      if(pesoMax == 500){
        modTarifa = 1.8;
      }else if(pesoMax == 1000){
        modTarifa = 2.1;
      }
    }
}

//Si el vehiculo tiene espacio para silla de ruedas o no
bool Especial::getSillaRuedas() const{
    return sillaRuedas;
}

//Si el vehiculo tiene caja trasera para carga de material
bool Especial::getCajaMaterial() const{
    return cajaMaterial;
}

//Obtiene el peso maximo que puede cargar el vehículo
float Especial::getPesoMax() const{
    return pesoMax;
}

//Actualiza el valor del modificador de la tarifa
void Especial::setModTarifa( float tar ){
    modTarifa = tar;
}

//Devuelve la información del objeto en formato string
std::string Especial::toString(){
  std::stringstream ss;
  ss << Vehiculo::toString()
  << " modificador tarifa : " << modTarifa  << std::endl
  << " espacio para silla de ruedas : " << sillaRuedas  << std::endl
  << " tiene caja de carga : " << cajaMaterial  << " capacidad kg : " << pesoMax
  << std::endl;

  return ss.str();
}

// Calclula el costo del tipo de auto
float Especial::calculaTarifa(){
  return  precio * modTarifa;
}
