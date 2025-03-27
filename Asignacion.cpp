#include "Asignacion.h"

Asignacion::Asignacion(){
  for (int i = 0; i < MAXV; i++ ){
    asignaciones[i] = -1;
  }
}

// @brief Asigna los vehiculos a los viajes.
int Asignacion::asignarVehiculo(int indiceP, std::string vehiculos[MAXV],
                        Clientela clientela) {

    std::string necesidad = clientela.consultaCliente(indiceP).getNecesidad();
    int pasajeros = clientela.consultaCliente(indiceP).getPasajeros();

    std::string tipoRequerido = "";
    if (necesidad != ""){
      if (necesidad == "ninguna" && pasajeros < 5) {
          tipoRequerido = "auto";
      }else if (necesidad == "ninguna" && pasajeros < 8) {
          tipoRequerido = "camioneta";
      } else if (necesidad == "caja 100 kilos") {
          tipoRequerido = "especial";
      } else if (necesidad == "caja 500 kilos") {
          tipoRequerido = "especial";
      } else if (necesidad == "Silla de Ruedas") {
          tipoRequerido = "especial";
      }

      for (int i = 0; i < MAXV; i++) {
          if (vehiculos[i] == tipoRequerido && asignaciones[i] == -1) {
              asignaciones[i] = indiceP;
              return i;
          }
      }
    }
    return -1;
}

//Cambia la letra por la descripción completa de la necesidad.
std::string Asignacion::opNecesidad(std::string opNec){

  if (opNec == "a"){
    return "ninguna";
  }else if (opNec == "b"){
    return "caja 100 kilos";
  }else if (opNec == "c"){
    return "caja 500 kilos";
  }else if (opNec == "d"){
    return "silla de ruedas";
  }
  return "opción no válida por favor elija entre a b c d: ";
}

// Revisa si el cliente acutual ya fue asignada en el arreglo de
bool Asignacion::revisaYaAsignada(int idCliente){
  bool yaAsignada = false;
  int j = 0;
  while ( j < MAXV && !yaAsignada) {
      if (asignaciones[j] == idCliente) {
          yaAsignada = true;
      }
      j++ ;
  }
  return yaAsignada;
}

//@brief Muestra un reporte de las asignaciones generadas.
std::string Asignacion::mostrarAsignaciones(std::string vehiculos[MAXV],
                          Clientela clientela)  {

    std::stringstream aux;
    aux << "--- Asignaciones Actuales ---" << std::endl;
    for (int i = 0; i < MAXV; i++) {
        if (asignaciones[i] != -1) {
            int indice = asignaciones[i];
            aux << "Vehículo " << vehiculos[i]
                 << " (ID: " << i << ") "  << " asignado a:" << std::endl
                 << clientela.consultaCliente(indice).toString() << std::endl;
        }
    }
    aux << "-----------------------------" << std::endl;
    return aux.str();
}
