/**
 * @file main.cpp
 * @author Benjamin Valdés
 * @title Solucion a Situación Problema DEMO POO 2026
 * @brief Programa principal para la solución de la situación problema
 *  sobre la gestión de viajes.  El programa permite registrar nuevos viajes
 *  y que estos se asignene a vehículos previamente registrados en el Programa
 *  Los vehículos y las ubicaciones solo se pueden cambiar en el código, pero
 *  los clientes y las asignaciones se registran en la ejecución.
 */

#include <iostream>
#include <string>
#include "Cliente.h"
#include "Clientela.h"
#include "Flota.h"
#include "Asignacion.h"

/**
 * @brief Muestra el menú principal del programa.
 *
 * @return void
 */
void mostrarMenu() {
    std::cout << "1. Agregar petición" << std::endl;
    std::cout << "2. Asignar vehículos" << std::endl;
    std::cout << "3. Mostrar asignaciones" << std::endl;
    std::cout << "4. Generar reportes vehículos" << std::endl;;
    std::cout << "5. Ver clientes" << std::endl;
    std::cout << "6. Salir" << std::endl;
}

/**
 * @brief Crea y agrega vehículos a la flota.
 *
 * @param flota Referencia a un objeto de tipo Flota.
 * @return void
 */
void crearVehiculos(Flota& flota){

      flota.creaAuto("Mazda", "Mijares","Centro", 7.4, 4);
      flota.creaAuto("Mazda", "Juan Gabriel","La Cruz", 8.0, 4);
      flota.creaAuto("Honda", "Rigo Tobar","Centro", 7.4, 4);
      flota.creaAuto("Honda", "Ana Gabriel","Las Campanas", 8.0, 4);
      flota.creaAuto("Nissan", "Yuriria","Las Campanas", 7.4, 4);
      flota.creaAuto("Toyota", "Ricky Marty","La Cruz", 8.0, 4);
      flota.creaCamioneta("Ford", "Chayan","La Cruz", 10.4, 6);
      flota.creaCamioneta("Honda", "Lucia Mendez","Calesa", 10.4, 6);
      flota.creaCamioneta("Ford", "Verónica Castro","Rincón de San Andrés",
                            10.4, 6);
      flota.creaEspecial("Chrisler", "Alejandro Fernandez","Centro", 20.4, 2,
                            true, false, 0);
      flota.creaEspecial("Toyota", "Alejandra Guzman","Calesa", 25.0, 4,
                            true, false, 0);
      flota.creaEspecial("Nissan", "Lupita Dalesio","Rincón de San Andrés",
                            20.4, 2, false, true, 500);
      flota.creaEspecial("Chrisler", "Daniela Romo","Karina", 15, 2, false,
                            true, 500);
      flota.creaEspecial("Chrisler", "Laura Pausini","Centro", 18, 2, false,
                            true, 1000);

}

/**
 * @brief Agrega una nueva petición de cliente.
 *
 * @param clientela Referencia a un objeto de tipo Clientela.
 * @param asig Referencia a un objeto de tipo Asignacion.
 * @return void
 */
void agregarPeticion(Clientela& clientela, Asignacion& asig) {
    std::string nombre, ubicacion, necesidad;
    int pasajeros;

    // ignore Limpia el buffer de entrada después de leer un número en el menu
    std::cin.ignore();
    std::cout << "Ingrese el nombre del cliente: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese una ubicación de la lista donde se "
              << "encuentra el cliente: "<< std::endl;
    std::cout << asig.muestraUbicaciones();
    std::getline(std::cin, ubicacion);

    std::cout << "Ingrese el número de pasajeros: ";
    std::cin >> pasajeros;
    std::cin.ignore();

    std::cout << "Ingrese la necesidad: " << std::endl;
    std::cout << "a) ninguna" << std::endl;
    std::cout << "b) caja 500 kilos" << std::endl;
    std::cout << "c) caja 1000 kilos" << std::endl;
    std::cout << "d) silla de ruedas" << std::endl;
    std::cin >> necesidad;

    necesidad = asig.opNecesidad(necesidad);

    clientela.creaCliente(nombre, ubicacion, pasajeros, necesidad);

}

/**
 * @brief Asigna vehículos a los clientes según sus necesidades.
 *
 * @param asignacion Referencia a un objeto de tipo Asignacion.
 * @param flota Referencia a un objeto de tipo Flota.
 * @param clientela Referencia a un objeto de tipo Clientela.
 * @return void
 */
void asignarVehiculos(Asignacion& asignacion, Flota& flota,
                                          Clientela& clientela) {

    for (int i = 0; i < clientela.getIndCliente(); ++i) {
        int pos = asignacion.asignarVehiculo(i, flota, clientela);

        if (pos != -1){
          std::cout << i << " Cliente asignado exitosamente en vehiculo : "
          << pos <<  std::endl;
        }else{
          std::cout << i << " No se pudo asignar, verifique que "
                    << "el cliente este bien creado : " << std::endl;
          std::cout << clientela.consultaCliente(i).toString() << std::endl;
        }

    }
}

/**
 * @brief Muestra las asignaciones de vehículos a los clientes.
 *
 * @param asignacion Referencia a un objeto de tipo Asignacion.
 * @param flota Referencia a un objeto de tipo Flota.
 * @param clientela Referencia a un objeto de tipo Clientela.
 * @return void
 */
void mostrarAsignaciones(Asignacion& asignacion, Flota& flota,
                                            Clientela& clientela) {

    std::cout << asignacion.mostrarAsignaciones(flota, clientela) << std::endl;
}

/**
 * @brief Genera reportes de vehículos filtrados por atributo y valor.
 *
 * @param flota Referencia a un objeto de tipo Flota.
 *
 * @return void
 */
void generarReportes(Flota& flota) {

    std::string atributo = "";
    std::string valor = "";
    std::cout << "Ingrese el atributo para filtrar "
              <<  "(tipo, ubicacion, asientos, todos): ";
    std::cin.ignore();
    std::cin >> atributo;
    if (atributo != "todos"){
      std::cout << "Ingrese el valor del atributo: ";
      std::cin >> valor;
    }

    std::cout << flota.filtrarVehiculo(atributo, valor) << std::endl;
}

/**
 * @brief consultar el estatus de todos los clientes.
 *
 * @param clientela Referencia a un objeto de tipo Clientela.
 * @return void
 */
void verClientes(Clientela& clientela) {

    std::cout << clientela.toString() << std::endl;
}

/**
 * @brief Función principal del programa.
 *
 * @return int
 */
int main() {

    Clientela clientela;
    Flota flota;
    Asignacion asignacion;

    crearVehiculos(flota);

    int opcion;
    do {
        std::cout << std::endl;
        mostrarMenu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPeticion(clientela, asignacion);
                break;
            case 2:
                asignarVehiculos(asignacion, flota, clientela);
                break;
            case 3:
                mostrarAsignaciones(asignacion, flota, clientela);
                break;
            case 4:
                generarReportes(flota);
                break;
            case 5:
                verClientes(clientela);
                break;
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 6);

    return 0;
}
