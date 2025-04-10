#include "Flota.h"
#include <string>
#include <sstream>


// Redimensiona el arreglo de empleados cuando se alcanza la capacidad.
void Flota::redimensionaArreglo() {
    int nuevaCapacidad = capacidad * 2;
    Vehiculo** nuevoArreglo = new Vehiculo*[nuevaCapacidad];

    for(int i = 0; i < idVehiculo; i++) {
        nuevoArreglo[i] = vehiculos[i];
    }

    delete[] vehiculos;
    vehiculos = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

// constructor por defecto
Flota::Flota(): capacidad(100), idVehiculo(0){
  vehiculos = new Vehiculo*[capacidad];
}

// Crea un objeto Auto en la flota
void Flota::creaAuto(std::string marca, std::string conductor,
    std::string ubicacion, float precio, int asientos) {
    if(idVehiculo >= capacidad){
      redimensionaArreglo();
    }
    if (idVehiculo < capacidad) {
        vehiculos[idVehiculo] = new Auto(idVehiculo, marca, conductor,
                                  ubicacion, precio, asientos);
        idVehiculo++ ;
    }
}

// Crea un objeto Camioneta en la flota
void Flota::creaCamioneta(std::string marca, std::string conductor,
    std::string ubicacion, float precio, int asientos, float modTarifa) {
      if(idVehiculo >= capacidad){
        redimensionaArreglo();
      }
      if (idVehiculo < capacidad) {
          vehiculos[idVehiculo] = new Camioneta(idVehiculo, marca, conductor,
                                  ubicacion, precio, asientos, modTarifa);
          idVehiculo++;
    }
}

// Crea un objeto Camioneta en la flota
void Flota::creaCamioneta(std::string marca, std::string conductor,
    std::string ubicacion, float precio, int asientos) {
    if(idVehiculo >= capacidad){
      redimensionaArreglo();
    }
    if (idVehiculo < capacidad) {
          vehiculos[idVehiculo] = new  Camioneta(idVehiculo, marca, conductor,
                                  ubicacion, precio, asientos);
          idVehiculo++;
    }
}

// Crea un objeto Especial en la flota
void Flota::creaEspecial(std::string marca, std::string conductor,
   std::string ubicacion, float precio,
   int asientos, float modTarifa,  bool sillaRuedas,
   bool cajaMaterial, float pesoMax) {
   if(idVehiculo >= capacidad){
       redimensionaArreglo();
    }
    if (idVehiculo < capacidad) {
         vehiculos[idVehiculo] = new  Especial(idVehiculo, marca, conductor,
                                  ubicacion, precio, asientos, modTarifa,
                                  sillaRuedas, cajaMaterial, pesoMax);
        idVehiculo++;
    }
}

// Crea un objeto Especial en la flota
void Flota::creaEspecial(std::string marca, std::string conductor,
   std::string ubicacion, float precio, int asientos, bool sillaRuedas,
   bool cajaMaterial, float pesoMax) {
   if(idVehiculo >= capacidad){
       redimensionaArreglo();
   }
   if (idVehiculo < capacidad) {
        vehiculos[idVehiculo] = new  Especial(idVehiculo, marca, conductor,
                                  ubicacion, precio, asientos,
                                  sillaRuedas, cajaMaterial, pesoMax);
        idVehiculo++;
    }
}

// Devuelve el numero de vehiculos registrados en el arreglo vehiculos
int Flota::getIdVehiculo() const{
  return idVehiculo;
}

// Devuelve el apuntador al objeto vehículo en la posición i
Vehiculo* Flota::obtenVehiculo(int id){
    return vehiculos[id];
}


// Filtra vehículos por un atributo y un valor específico
std::string Flota::filtrarVehiculo(std::string atributo, std::string valor) {
    std::stringstream ss;

    ss << atributo << " " << valor << " :"<< std::endl;

    if (atributo == "tipo") {
      for (int i = 0; i < idVehiculo; i++) {

        if (vehiculos[i]->getTipo() == valor){
           ss << vehiculos[i]->toString()
             << " costo km : " << vehiculos[i]->calculaTarifa() << std::endl
             << std::endl;
        }

      }
    } else if (atributo == "ubicacion") {
      for (int i = 0; i < idVehiculo; i++) {

        if (vehiculos[i]->getUbicacion() == valor){
           ss << vehiculos[i]->toString()
           << " costo km : " << vehiculos[i]->calculaTarifa() << std::endl
           << std::endl;
        }

      }
    } else if (atributo == "asientos") {
      for (int i = 0; i < idVehiculo; i++) {

        if (vehiculos[i]->getAsientos() == stoi(valor)){
           ss << vehiculos[i]->toString()
           << " costo km : " << vehiculos[i]->calculaTarifa() << std::endl
           << std::endl;
        }

      }
    } else if (atributo == "todos"){
        for (int i = 0; i < idVehiculo; i++) {
           ss << vehiculos[i]->toString()
           << " costo km : " << vehiculos[i]->calculaTarifa() << std::endl
           << std::endl;
        }
    }
    return ss.str();
}


// Calcula el promedio de tarifas de todos los vehículos en la flota
float Flota::promedioTarifas() {
    float total = 0.0;
    int count = 0;
    for (int i = 0; i < idVehiculo; i++) {
        total += vehiculos[i]->calculaTarifa();
        count++;
    }
    if (count == 0) {
      return 0.0;
    }

    return total / count;
}
