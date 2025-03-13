/**
 * @file pruebas.cpp
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

#define MAXC 5  ///< Maximo numero de clientees.
#define MAXV 4   ///< Maximo numero de Vehículos.



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

/**
 * @brief Pruebas de la funcionalidad del programa.
 *
 * Se realizan diversas pruebas para validar el correcto funcionamiento
 * de las funciones principales del programa, incluyendo la asignación
 * de vehículos, verificación de asignaciones y generación de reportes.
 *
 * ### Pruebas Implementadas:
 * - **Prueba 1:** Cuando los arreglos están vacíos.
 * - **Prueba 2:** Caso normal con asignaciones posibles e imposibles.
 * - **Prueba 3:** Cuando se excede el tamaño de los arreglos.
 */
int main() {
    std::cout << "\nPrueba 1: Cuando los arreglos están vacíos" << std::endl;

    Cliente clientes[MAXC];
    std::string vehiculos[MAXV] = {"auto", "camioneta", "especial", "auto"};
    int asignaciones[MAXV] = {-1, -1, -1, -1};
    int numClientes = 0;

    // Prueba: No se puede asignar un vehículo cuando no hay clientes registrados.
    std::cout << "Asignar vehículo";
    if (asignarVehiculo(0, vehiculos, clientes, asignaciones) == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba: Verificar que una asignación no existe en un arreglo vacío.
    std::cout << "Verificar si ya está asignado";
    if (!revisaYaAsignada(0, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba: Mostrar asignaciones en un sistema sin clientes ni asignaciones.
    std::cout << "Mostrar asignaciones";
    std::stringstream ss;
    ss << "--- Asignaciones Actuales ---\n-----------------------------\n";
    if (ss.str() == mostrarAsignaciones(vehiculos, clientes, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba 2: Caso normal con asignaciones posibles e imposibles.
    std::cout << "\nPrueba 2: Caso normal" << std::endl;
    numClientes = 5;

    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i);
        clientes[i] = Cliente(testStr, "4 personas o menos", "", false);
    }

    std::cout << "Asignar vehículos cuando es posible" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (asignarVehiculo(i, vehiculos, clientes, asignaciones) != -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Asignar vehículos cuando no es posible" << std::endl;
    for (int i = 2; i < 5; i++) {
        if (asignarVehiculo(i, vehiculos, clientes, asignaciones) == -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Verificar asignaciones cuando sí están asignadas"
              << std::endl;
    for (int i = 0; i < 2; i++) {
        if (revisaYaAsignada(i, asignaciones)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Verificar asignaciones cuando no están asignadas"
              << std::endl;
    for (int i = 2; i < 5; i++) {
        if (!revisaYaAsignada(i, asignaciones)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Mostrar asignaciones con clientes asignados" << std::endl;
    ss.str(""); // borra el contenido del stream
    ss << "--- Asignaciones Actuales ---\n"
       <<"Vehículo auto (ID: 0)  asignado a: test 0 en dirección :"
       <<"  - Necesidad: 4 personas o menos\n"
       <<"Vehículo auto (ID: 3)  asignado a: test 3 en dirección :"
       <<"  - Necesidad: 4 personas o menos\n"
       <<"-----------------------------\n";

    if (ss.str() == mostrarAsignaciones(vehiculos, clientes, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba 3: Cuando se excede el tamaño de los arreglos.
    std::cout << "\nPrueba 3: Cuando se excede el tamaño de los arreglos"
              << std::endl;

    std::cout << "Asignar vehículo fuera del rango" << std::endl;
    if (asignarVehiculo(5, vehiculos, clientes, asignaciones) == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    std::cout << "Verificar asignación fuera del rango" << std::endl;
    if (!revisaYaAsignada(5, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }
}
