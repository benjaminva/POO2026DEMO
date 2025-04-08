#include <iostream>
#include <string>
#include "Cliente.h"
#include "Clientela.h"
#include "Flota.h"
#include "Asignacion.h"

void mostrarMenu() {
    std::cout << "1. Agregar petición" << std::endl;
    std::cout << "2. Asignar vehículos" << std::endl;
    std::cout << "3. Mostrar asignaciones" << std::endl;
    std::cout << "4. Generar reportes" << std::endl;
    std::cout << "5. Salir" << std::endl;
}

void crearVehiculos(Flota& flota){

      flota.creaAuto("Mazda", "Mijares","Centro", 7.4, 4);
      flota.creaAuto("Mazda", "Juan Gabriel","La Cruz", 8.0, 4);
      flota.creaAuto("Honda", "Rigo Tobar","Centro", 7.4, 4);
      flota.creaAuto("Honda", "Ana Gabriel","Las Campanas", 8.0, 4);
      flota.creaAuto("Nissan", "Yuriria","Las Campanas", 7.4, 4);
      flota.creaAuto("Toyota", "Ricky Marty","La Cruz", 8.0, 4);
      flota.creaCamioneta("Ford", "Chayan","La Cruz", 10.4, 6);
      flota.creaCamioneta("Honda", "Lucia Mendez","Calesa", 10.4, 6);
      flota.creaCamioneta("Ford", "Verónica Castro","Rincón de San Andrés", 10.4, 6);
      flota.creaEspecial("Chrisler", "Alejandro Fernandez","Centro", 20.4, 2, true, false, 0);
      flota.creaEspecial("Nissan", "Lupita Dalesio","Rincón de San Andrés", 20.4, 2, false, true, 500);
      flota.creaEspecial("Chrisler", "Daniela Romo","Karina", 20.4, 2, false, true, 500);
      flota.creaEspecial("Chrisler", "Laura Pausini","Centro", 20.4, 2, false, true, 1000);

}

void agregarPeticion(Clientela& clientela, Asignacion& asig) {
    std::string nombre, ubicacion, necesidad;
    int pasajeros;

    std::cin.ignore();  // Limpia el buffer de entrada después de leer un número
    std::cout << "Ingrese el nombre del cliente: ";
    std::getline(std::cin, nombre);  // Lee la línea completa para el nombre

    std::cout << "Ingrese una ubicación de la lista donde se encuentra el cliente: "<< std::endl;
    std::cout << asig.muestraUbicaciones();
    std::getline(std::cin, ubicacion);  // Lee la línea completa para la ubicación

    std::cout << "Ingrese el número de pasajeros: ";
    std::cin >> pasajeros;
    std::cin.ignore();  // Limpia el buffer de entrada después de leer un número

    std::cout << "Ingrese la necesidad: " << std::endl;
    std::cout << "a) ninguna" << std::endl;
    std::cout << "b) caja 500 kilos" << std::endl;
    std::cout << "c) caja 1000 kilos" << std::endl;
    std::cout << "d) silla de ruedas" << std::endl;
    std::cin >> necesidad;

    necesidad = asig.opNecesidad(necesidad);

    clientela.creaCliente(nombre, ubicacion, pasajeros, necesidad);

}

void asignarVehiculos(Asignacion& asignacion, Flota& flota, Clientela& clientela) {
    for (int i = 0; i < clientela.getIndCliente(); ++i) {
        int pos = asignacion.asignarVehiculo(i, flota, clientela);
        if (pos != -1){
          std::cout << i << " Cliente asignado exitosamente en vehiculo : " << pos <<  std::endl;
        }else{
          std::cout << i << " No se pudo asignar, verifique que el cliente este bien creado : " << std::endl;
          std::cout << clientela.consultaCliente(i).toString() << std::endl;
        }
    }
}

void mostrarAsignaciones(Asignacion& asignacion, Flota& flota, Clientela& clientela) {
    std::cout << asignacion.mostrarAsignaciones(flota, clientela) << std::endl;
}

void generarReportes(Flota& flota, Clientela& clientela) {
    std::string atributo, valor;
    std::cout << "Ingrese el atributo para filtrar (tipo, ubicacion, asientos, todos): ";
    std::cin >> atributo;
    std::cout << "Ingrese el valor del atributo: ";
    std::cin >> valor;

    std::cout << flota.filtrarVehiculo(atributo, valor) << std::endl;
}

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
                generarReportes(flota, clientela);
                break;
            case 5:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 5);

    return 0;
}
