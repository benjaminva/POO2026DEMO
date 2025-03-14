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

#include "Vehiculo.h"
#include "Cliente.h"
#include "Asignacion.h"


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
 * - **Prueba 4:** Uso y acceso de la clase Vehiculo.
 */
int main() {
    std::cout << "\nPrueba 1: Cuando los arreglos están vacíos" << std::endl;

    Asignacion a;
    Cliente clientes[MAXC];
    std::string vehiculos[MAXV] = {"auto", "camioneta", "especial", "auto"};
    int asignaciones[MAXV] = {-1, -1, -1, -1};
    int numClientes = 0;

    // Prueba: No se puede asignar un vehículo cuando no hay clientes registrados.
    std::cout << "Asignar vehículo";
    if (a.asignarVehiculo(0, vehiculos, clientes, asignaciones) == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba: Verificar que una asignación no existe en un arreglo vacío.
    std::cout << "Verificar si ya está asignado";
    if (!a.revisaYaAsignada(0, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba: Mostrar asignaciones en un sistema sin clientes ni asignaciones.
    std::cout << "Mostrar asignaciones";
    std::stringstream ss;
    ss << "--- Asignaciones Actuales ---\n-----------------------------\n";
    if (ss.str() == a.mostrarAsignaciones(vehiculos, clientes, asignaciones)) {
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
        if (a.asignarVehiculo(i, vehiculos, clientes, asignaciones) != -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Asignar vehículos cuando no es posible" << std::endl;
    for (int i = 2; i < 5; i++) {
        if (a.asignarVehiculo(i, vehiculos, clientes, asignaciones) == -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Verificar asignaciones cuando sí están asignadas"
              << std::endl;
    for (int i = 0; i < 2; i++) {
        if (a.revisaYaAsignada(i, asignaciones)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << "Verificar asignaciones cuando no están asignadas"
              << std::endl;
    for (int i = 2; i < 5; i++) {
        if (!a.revisaYaAsignada(i, asignaciones)) {
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

    if (ss.str() == a.mostrarAsignaciones(vehiculos, clientes, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba 3: Cuando se excede el tamaño de los arreglos.
    std::cout << "\nPrueba 3: Cuando se excede el tamaño de los arreglos"
              << std::endl;

    std::cout << "Asignar vehículo fuera del rango" << std::endl;
    if (a.asignarVehiculo(5, vehiculos, clientes, asignaciones) == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    std::cout << "Verificar asignación fuera del rango" << std::endl;
    if (!a.revisaYaAsignada(5, asignaciones)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    std::cout << std::endl << "Prueba clase Vehiculo : " << std::endl;
    std::cout << "Constructor por Defecto ";

    Vehiculo v1;
    ss.str(""); // borra el contenido del stream
    ss << v1.getId() << v1.getMarca() << v1.getConductor();
    if (ss.str() == "0"){
      std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    std::cout << "Prueba Setters ";

    v1.setMarca("Honda");
    v1.setConductor("Ramiro");

    ss.str(""); // borra el contenido del stream
    ss << v1.getId() << v1.getMarca() << v1.getConductor();
    if (ss.str() == "0HondaRamiro"){
      std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    std::cout << "Constructor normal";
    Vehiculo v2(1,"Mitsubishi","Eduardo Palomo","Sedan");
    ss.str(""); // borra el contenido del stream
    ss << v2.getId() << v2.getMarca() << v2.getConductor() << v2.getTipo();
    if (ss.str() == "1MitsubishiEduardo PalomoSedan"){
      std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso"  << std::endl;
    }

}
