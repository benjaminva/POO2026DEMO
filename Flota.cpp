#include "Flota.h"
#include <string>
#include <sstream>

// Crea un objeto Auto en la flota
void Flota::creaAuto(int id, std::string marca, std::string conductor,
    std::string ubicacion, float precio, int asientos) {
    if (numAutos < MAXV) {
        autos[numAutos++] = Auto(id, marca, conductor,
                                  ubicacion, precio, asientos);
    }
}

// Crea un objeto Camioneta en la flota
void Flota::creaCamioneta(int id, std::string marca, std::string conductor,
    std::string ubicacion, float precio, int asientos, float modTarifa) {
    if (numCamionetas < MAXV) {
        camionetas[numCamionetas++] = Camioneta(id, marca, conductor,
                                  ubicacion, precio, asientos, modTarifa);
    }
}

// Crea un objeto Especial en la flota
void Flota::creaEspecial(int id, std::string marca, std::string conductor,
   std::string ubicacion, float precio,
   int asientos, float modTarifa,  bool sillaRuedas,
   bool cajaMaterial, float pesoMax) {
    if (numEspeciales < MAXV) {
        especiales[numEspeciales++] = Especial(id, marca, conductor,
                                  ubicacion, precio, asientos, modTarifa,
                                  sillaRuedas, cajaMaterial, pesoMax);
    }
}

// Filtra vehículos por un atributo (ej. "marca" o "conductor") y un valor específico
std::string Flota::filtrarVehiculo(std::string atributo, std::string valor) {
    std::stringstream ss;

    ss << atributo << " " << valor << " :"<< std::endl;

    if (atributo == "tipo") {
        if (valor == "auto"){
          for (int i = 0; i < numAutos; i++) {
                  ss << autos[i].toString();
          }
        }else if (valor == "camioneta"){
          for (int i = 0; i < numCamionetas; i++) {
                  ss << camionetas[i].toString();
          }
        } else if (valor == "especial"){
          for (int i = 0; i < numEspeciales; i++) {
                  ss << especiales[i].toString();
          }
        }
    } else{

      for (int i = 0; i < MAXV; i++) {
        if(atributo == "ubicacion"){
          if( i < numAutos && autos[i].getUbicacion() == valor){
              ss << autos[i].toString();
          }
          if( i < numCamionetas && camionetas[i].getUbicacion() == valor){
              ss << camionetas[i].toString();
          }
          if( i < numEspeciales && especiales[i].getUbicacion() == valor){
              ss << especiales[i].toString();
          }
        }else if(atributo == "asientos"){
          if( i < numAutos && autos[i].getAsientos() == std::stoi(valor)){
              ss << autos[i].toString();
          }
          if( i < numCamionetas && camionetas[i].getAsientos() == std::stoi(valor)){
              ss << camionetas[i].toString();
          }
          if( i < numEspeciales && especiales[i].getAsientos() == std::stoi(valor)){
              ss << especiales[i].toString();
          }
        }
      }
    }
    return ss.str();
}


// Calcula el promedio de tarifas de todos los vehículos en la flota
float Flota::promedioTarifas() {
    float total = 0.0;
    int count = 0;
    for (int i = 0; i < numAutos; i++) {
        total += autos[i].calculaTarifa();
        count++;
    }
    for (int i = 0; i < numCamionetas; i++) {
        total += camionetas[i].calculaTarifa();
        count++;
    }
    for (int i = 0; i < numEspeciales; i++) {
        total += especiales[i].calculaTarifa();
        count++;
    }

    if (count == 0) {
      return 0.0;
    }

    return total / count;
}
