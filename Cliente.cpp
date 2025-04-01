#include "Cliente.h"
#include <sstream>

// Constructor con por defecto
// Inicializa los atributos de la clase Cliente con los valores por defecto.
Cliente::Cliente() : nombre(""), ubicacion(""), pasajeros(0),
                     necesidad(""), estatus(false) {}


// Constructor con lista de inicialización
// Inicializa los atributos de la clase Cliente con los valores proporcionados.
Cliente::Cliente(std::string nom, std::string ubi, int pas,
                  std::string nec) :
                    nombre(nom), ubicacion(ubi), pasajeros(pas),
                    necesidad(nec), estatus(false) {}

// Constructor con lista de inicialización
// Inicializa los atributos de la clase Cliente con los valores proporcionados.
Cliente::Cliente(std::string nom, std::string ubi, int pas) :
                    nombre(nom), ubicacion(ubi), pasajeros(pas),
                    necesidad(""), estatus(false) {}

// Implementación de Getters

// Devuelve el nombre del cliente.
std::string Cliente::getNombre() const {
    return nombre;
}

// Devuelve la ubicación del cliente.
std::string Cliente::getUbicacion() const {
    return ubicacion;
}

// Devuelve la necesidad del cliente.
std::string Cliente::getNecesidad() const {
    return necesidad;
}

// Devuelve la necesidad del cliente.
int Cliente::getPasajeros() const {
    return pasajeros;
}

// Devuelve el estado del cliente (activo/inactivo).
bool Cliente::getEstatus() const {
    return estatus;
}

// Implementación de Setters
// Modifica la necesidad del cliente.
void Cliente::setNecesidad(std::string nuevaNec) {
    necesidad = nuevaNec;
}

// Modifica el nombre del cliente.
void Cliente::setNombre(std::string nuevoNom) {
    nombre = nuevoNom;
}

// Modifica la ubicación del cliente.
void Cliente::setUbicacion(std::string nuevaUbi) {
    ubicacion = nuevaUbi;
}

// Modifica el estado del cliente.
void Cliente::setEstatus(bool nuevoEst) {
    estatus = nuevoEst;
}

// Devuelve la información del objeto en formato string
std::string Cliente::toString(){
  std::stringstream ss;
  ss << " nombre : " << nombre << std::endl
   << " ubicacion : " << ubicacion << std::endl
   << " pasajeros : " << pasajeros << std::endl
   << " necesidad : "<< necesidad << std::endl
   << " estatus : " << estatus << std::endl;

   return ss.str();
}
