#include "Asignacion.h"

Asignacion::Asignacion(){}

// @brief Asigna los vehiculos a los viajes.
int Asignacion::asignarVehiculo(int indiceP, std::string vehiculos[MAXV],
                        Cliente clientes[MAXC],
                        int asignaciones[MAXV]) {

    std::string necesidad = clientes[indiceP].getNecesidad();
    std::string tipoRequerido = "";

    if (necesidad == "4 personas o menos") {
        tipoRequerido = "auto";
    } else if (necesidad == "5 a 7 personas") {
        tipoRequerido = "camioneta";
    } else if (necesidad == "Silla de Ruedas") {
        tipoRequerido = "especial";
    }

    for (int i = 0; i < MAXV; i++) {
        if (vehiculos[i] == tipoRequerido && asignaciones[i] == -1) {
            asignaciones[i] = indiceP;
            return i;
        }
    }
    return -1;
}

//Cambia la letra por la descripción completa de la necesidad.
std::string Asignacion::opNecesidad(std::string opNec){

  if (opNec == "a"){
    return "4 personas o menos";
  }else if (opNec == "b"){
    return "5 a 7 personas";
  }else if (opNec == "c"){
    return "Silla de Ruedas";
  }
  return "opción no válida por favor elija entre a b c : ";
}

// Revisa si el cliente acutual ya fue asignada en el arreglo de
bool Asignacion::revisaYaAsignada(int idCliente, int asignaciones[MAXV]){
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
                          Cliente clientes[MAXC],
                          int asignaciones[MAXV])  {

    std::stringstream aux;
    aux << "--- Asignaciones Actuales ---" << std::endl;
    for (int i = 0; i < MAXV; i++) {
        if (asignaciones[i] != -1) {
            int indice = asignaciones[i];
            aux << "Vehículo " << vehiculos[i]
                 << " (ID: " << i << ") "
                 << " asignado a: " << clientes[i].getNombre()
                 << " en dirección : " << clientes[i].getUbicacion()
                 << " - Necesidad: " << clientes[i].getNecesidad()
                 << std::endl;
        }
    }
    aux << "-----------------------------" << std::endl;
    return aux.str();
}
