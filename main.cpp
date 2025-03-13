/**
 * @file main.cpp
 * @brief Programa que vincula a los usarios con el transporte de la situación
 * problema.
 *
 * Los usuarios registran se registran como cliente de viaje con sus necesidades
 * específicas el programa asigna los transportes disponibles según las
 * necesidedes y entrega un reporte final.
 *
 * @author Benjamin Valdes
 */

#include <iostream>
#include <string>
#include <sstream>

#include "Cliente.h"

#define MAXC 20  ///< Maximo numero de clientees.
#define MAXV 9   ///< Maximo numero de Vehículos.



/**
 * @brief Muestra un menu de opciones.
 *
 */
void muestraMenu(){
  std::cout << "1. Agregar petición" << std::endl;
  std::cout << "2. Asignar vehículos" << std::endl;
  std::cout << "3. Mostrar asignaciones" << std::endl;
  std::cout << "4. Salir" << std::endl;
  std::cout << " Seleccione: ";
}

/**
 * @brief Asigna los vehiculos a los viajes.
 *
 * Usando el indice de la cliente verifica que exista un vehiculo que pueda
 * atender la petición y asigna la petición al arreglo.
 *
 * @param indiceP Indice de la Petición a agergar.
 * @param vehiculos Arreglo con los vehículos.
 * @param clientes Arreglo de objetos con los clientes.
 * @param asignaciones Arreglo de asignaciones.
 *
 * @return -1 si no se pudo agregar la petición o la posición donde se asignó
 * la petición .
 */
int asignarVehiculo(int indiceP, std::string vehiculos[MAXV],
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


/**
 * @brief Cambia la letra por la descripción completa de la necesidad.
 *
 * Cambia la letra de la opción por la descripción completa de la necesidad
 * en formato string, para que pueda ser impresa en reportes.
 *
 * @param opNec String con la opcion: a b c
 *
 * @return string con la descripcion de la necesidad.
 *
 */
std::string opNecesidad(std::string opNec){

  if (opNec == "a"){
    return "4 personas o menos";
  }else if (opNec == "b"){
    return "5 a 7 personas";
  }else if (opNec == "c"){
    return "Silla de Ruedas";
  }
  return "opción no válida por favor elija entre a b c : ";
}

/**
 * @brief Revisa si el cliente acutual ya fue asignada en el arreglo de
 * asignaciones.
 *
 * recorre el arreglo de asignaciones y busca la petición, si la encuentra
 * devuelve true
 *
 * @param idCliente Int con el indice de la petición a buscar.
 * @param asignaciones Arreglo de asignaciones.
 *
 * @return boolean true si encuentra la petición en el arreglo sino false
 *
 */
bool revisaYaAsignada(int idCliente, int asignaciones[MAXV]){
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

/**
 * @brief Muestra un reporte de las asignaciones generadas.
 *
 * recorre el arreglo de asignaciones y muestra el vehiculo y al cliente
 * correspondiente
 *
 * @param vehiculos Arreglo con los vehículos.
 * @param clientes Arreglos de cleintes.
 * @param asignaciones Arreglo de asignaciones.
 *
 * @return string con el reporte de las asignaciones.
 *
 */
std::string mostrarAsignaciones(std::string vehiculos[MAXV],
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





int main() {

    Cliente clientes[MAXC];
    std::string vehiculos[MAXV] = {"auto", "camioneta", "especial", "auto",
                                    "auto", "camioneta", "especial", "auto",
                                    "camioneta"};
    int asignaciones[MAXV] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int numClientes = 0;

    int opcion;
    do {

        muestraMenu();

        std::cin >> opcion;
        std::cin.ignore();


        if (opcion == 1 && numClientes < MAXC) { // 1 crear petición
            std::cout << "Nombre del cliente: ";
            std::string nombre = "";
            getline(std::cin, nombre);
            std::cout << "Ubicación del cliente: ";
            std::string ubicacion = "";
            getline(std::cin, ubicacion);
            std::cout << "Necesidad  selcciona" << std::endl;
            std::cout << "a) 4 personas o menos" << std::endl;
            std::cout << "b) 5 a 7 personas" << std::endl;
            std::cout << "c) Silla de Ruedas " << std::endl;
            std::cout << "Necesidad :";
            std::string opNec = "";
            std::string necesidad = "";

            while (opNec != "a" && opNec != "b" && opNec != "c" ){
              std::cout << necesidad;
              std::cin >> opNec;
              necesidad = opNecesidad(opNec);
            }

            clientes[numClientes] = Cliente(nombre, necesidad, ubicacion, false);

            numClientes++;
        } else if (opcion == 2) { // 2 generar asignaciones vehículo-petición
            for (int i = 0; i < numClientes; i++) {

                if (revisaYaAsignada(i, asignaciones) ==  false) {
                    int exito = asignarVehiculo(i, vehiculos,
                                                clientes, asignaciones);
                    if(exito == -1){
                      std::cout << "No se pudo asignar petición: "
                      << clientes[i].getNombre() << std::endl;
                    }
                }
            }
            std::cout << "Proceso de asignación completado." << std::endl;
        }
        else if (opcion == 3) { // 3 mostrar asignaciones
            std::cout << mostrarAsignaciones(vehiculos, clientes,
                                              asignaciones);
        }

    } while (opcion != 4);

    return 0;
}
