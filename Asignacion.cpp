#include "Asignacion.h"



// Constructor por defecto
Asignacion::Asignacion(){
  for (int i = 0; i < MAXV; i++ ){
    asignaciones[i] = -1;
  }
}

int Asignacion::convUbicacionNum(std::string ubicacion){
  for (int i = 0; i < 19; i++ ){
    if(ubicacion ==  ubicaciones[i]){
      return i;
    }
  }
  return -1;
}


std::string Asignacion::muestraUbicaciones(){
  std::stringstream ss;
  for (int i = 0; i < 19; i++ ){
      ss << ubicaciones[i] << ", ";
      if (i % 3 == 0){
        ss  << std::endl;
      }
  }
  ss  << std::endl;
  return ss.str();
}

// Devuelve un valor de distancia entre 2 ubicaciones
int Asignacion::calculaDistancia(std::string v, std::string c){

  int indV = convUbicacionNum(v);
  int indC = convUbicacionNum(c);

  if (indV == -1 || indC == -1){
    return -1;
  }

  return distancias[indV][indC];
}


// Asigna los vehiculos a los viajes.
int Asignacion::asignarVehiculo(int indiceP, Flota& flota,
                        Clientela& clientela) {

    Cliente clien = clientela.consultaCliente(indiceP);
    std::string necesidad = clien.getNecesidad();
    std::string ubicacion = clien.getUbicacion();
    int pasajeros = clien.getPasajeros();


    std::string tipoRequerido = "";
    if (necesidad != ""){
      if (necesidad == "ninguna" && pasajeros < 5) {
          tipoRequerido = "auto";
      }else if (necesidad == "ninguna" && pasajeros < 8) {
          tipoRequerido = "camioneta";
      } else if (necesidad == "caja 500 kilos") {
          tipoRequerido = "especial";
      } else if (necesidad == "caja 1000 kilos") {
          tipoRequerido = "especial";
      } else if (necesidad == "silla de ruedas") {
          tipoRequerido = "especial";
      } else {
          return -1;
      }

      int pos = -1;
      int menor = 1000;
      int distancia;
      float tarifa = 1000.0;
      for (int i = 0; i < flota.getIdVehiculo(); i++) {
          distancia = 1000;
          Vehiculo *temp = flota.obtenVehiculo(i);
          if (temp->getTipo() == tipoRequerido && asignaciones[i] == -1) {
            if(temp->getTipo() == "especial"){
                Especial *esp = (Especial* )temp;
                if(necesidad == "silla de ruedas" &&
                            esp->getSillaRuedas()){
                    distancia = calculaDistancia(esp->getUbicacion(), ubicacion);
                } else if (necesidad == "caja 500 kilos" &&
                            esp->getPesoMax() == 500){
                    distancia = calculaDistancia(esp->getUbicacion(), ubicacion);
                } else if (necesidad == "caja 1000 kilos" ||
                            necesidad == "caja 500 kilos" &&
                            esp->getPesoMax() == 1000){
                    distancia = calculaDistancia(esp->getUbicacion(), ubicacion);
                }
            }else {
              distancia = calculaDistancia(temp->getUbicacion(), ubicacion);
            }

            if (distancia < menor ){
                menor = distancia;
                pos = i;
                tarifa = temp->calculaTarifa();
            }else if (distancia == menor){
                if (temp->calculaTarifa() < tarifa){
                    menor = distancia;
                    pos = i;
                    tarifa = temp->calculaTarifa();
                }
            }
          }
      }
      if (pos != -1){
        asignaciones[pos] = indiceP;
        clientela.modificaCliente(indiceP,"estatus","true");
        return pos;
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
std::string Asignacion::mostrarAsignaciones(Flota& flota,
                        Clientela& clientela)  {

    std::stringstream aux;
    aux << "--- Asignaciones Actuales ---" << std::endl;
    for (int i = 0; i < flota.getIdVehiculo(); i++) {
        if (asignaciones[i] != -1) {
            aux << " (asignacion : " << i << " )" << std::endl;
            int indice = asignaciones[i];
            Vehiculo* temp = flota.obtenVehiculo(i);
            aux << " Vehículo : " << temp->toString()
                << clientela.consultaCliente(indice).toString() << std::endl;
        }
    }
    aux << "-----------------------------" << std::endl;
    return aux.str();
}
