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


int main() {

    Asignacion a;
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
              necesidad = a.opNecesidad(opNec);
            }

            clientes[numClientes] = Cliente(nombre, necesidad, ubicacion, false);

            numClientes++;
        } else if (opcion == 2) { // 2 generar asignaciones vehículo-petición
            for (int i = 0; i < numClientes; i++) {

                if (a.revisaYaAsignada(i, asignaciones) ==  false) {
                    int exito = a.asignarVehiculo(i, vehiculos,
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
            std::cout << a.mostrarAsignaciones(vehiculos, clientes,
                                              asignaciones);
        }

    } while (opcion != 4);

    return 0;
}
