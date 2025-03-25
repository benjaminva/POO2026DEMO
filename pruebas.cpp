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
 * @brief Pruebas de la funcionalidad del programa.
 *
 * Se realizan diversas pruebas para validar el correcto funcionamiento
 * de las funciones principales del programa, incluyendo la asignación
 * de vehículos, verificación de asignaciones y generación de reportes.
 *
 */
int main() {
    std::cout << "Pruebas por clases:" << std::endl;
    std::cout << "Prueba 1 : Clase Asignacion" << std::endl;
    std::cout << "Prueba 2 : Clase Asignacion" << std::endl;
    std::cout << "Prueba 3 : Clase Asignacion" << std::endl;
    std::cout << "Prueba 4 : Clase Vehiculo" << std::endl;
    std::cout << "Prueba 5 : Clase Cliente" << std::endl;

    std::cout << "\nPrueba 1: Cuando los arreglos están vacíos" << std::endl;

    Asignacion a;
    Cliente clientes[MAXC];
    std::string vehiculos[MAXV] = {"auto", "camioneta", "especial", "auto"};
    int numClientes = 0;

    // Prueba: No se puede asignar un vehículo cuando no hay clientes.
    std::cout << " Asignar vehículo";
    int test = a.asignarVehiculo(0, vehiculos, clientes);
    if (test == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test << std::endl;
    }

    // Prueba: Verificar que una asignación no existe en un arreglo vacío.
    std::cout << " Verificar si ya está asignado";
    if (!a.revisaYaAsignada(0)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << !a.revisaYaAsignada(0) << std::endl;
    }

    // Prueba: Mostrar asignaciones en un sistema sin clientes ni asignaciones.
    std::cout << " Mostrar asignaciones";
    std::stringstream ss;
    ss << "--- Asignaciones Actuales ---\n-----------------------------\n";
    if (ss.str() == a.mostrarAsignaciones(vehiculos, clientes)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << a.mostrarAsignaciones(vehiculos, clientes) << std::endl;
    }

    // Prueba 2: Caso normal con asignaciones posibles e imposibles.
    std::cout << "\nPrueba 2: Caso normal" << std::endl;
    numClientes = 5;

    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i);
        clientes[i] = Cliente(testStr, "4 personas o menos", "", false);
    }

    std::cout << " Asignar vehículos cuando es posible" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (a.asignarVehiculo(i, vehiculos, clientes) != -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Asignar vehículos cuando no es posible" << std::endl;
    for (int i = 2; i < 5; i++) {
        if (a.asignarVehiculo(i, vehiculos, clientes) == -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Verificar asignaciones cuando sí están asignadas" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (a.revisaYaAsignada(i)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Verificar asignaciones cuando no están asignadas" << std::endl;
    for (int i = 2; i < 5; i++) {
        if (!a.revisaYaAsignada(i)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Mostrar asignaciones con clientes asignados" << std::endl;
    ss.str(""); // borra el contenido del stream
    ss << "--- Asignaciones Actuales ---\n"
       << "Vehículo auto (ID: 0)  asignado a: test 0 en dirección :"
       << "  - Necesidad: 4 personas o menos\n"
       << "Vehículo auto (ID: 3)  asignado a: test 3 en dirección :"
       << "  - Necesidad: 4 personas o menos\n"
       << "-----------------------------\n";

    if (ss.str() == a.mostrarAsignaciones(vehiculos, clientes)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << a.mostrarAsignaciones(vehiculos, clientes) << std::endl;
    }

    // Prueba 3: Cuando se excede el tamaño de los arreglos.
    std::cout << "\nPrueba 3: Cuando se excede el tamaño máximo permitido "
              << " de los arreglos " << std::endl;

    std::cout << " Asignar vehículo fuera del rango" << std::endl;
    if (a.asignarVehiculo(5, vehiculos, clientes) == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    std::cout << " Verificar asignación fuera del rango" << std::endl;
    if (!a.revisaYaAsignada(5)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    // Prueba 4: Clase Vehiculo.
    std::cout << std::endl << "Prueba 4 : métodos clase Vehiculo  " << std::endl;
    std::cout << " Constructor por defecto ";

    Vehiculo v1;

    ss.str("");
    ss << " id : 0" << std::endl
       << " marca : " << std::endl
       << " conductor : " << std::endl
       << " tipo : " << std::endl
       << " ubicacion : " << std::endl
       << " precio : 0" << std::endl
       << " asientos : 0" << std::endl;

    if (v1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << v1.toString() << std::endl;
    }


    std::cout << " Constructor normal";
    Vehiculo v2(1, "Mitsubishi", "Eduardo Palomo", "auto", "Metepec", 12.4, 4);

    ss.str("");
    ss << " id : 1" << std::endl
       << " marca : Mitsubishi" << std::endl
       << " conductor : Eduardo Palomo" << std::endl
       << " tipo : auto" << std::endl
       << " ubicacion : Metepec" << std::endl
       << " precio : 12.4" << std::endl
       << " asientos : 4" << std::endl;

    if (v2.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << v2.toString() << std::endl;
    }


    std::cout << " Setters ";

    v1.setMarca("Honda");
    v1.setConductor("Ramiro");
    v1.setUbicacion("Lomas");
    v1.setAsientos(2);
    v1.setPrecio(11.1);

    ss.str("");
    ss << " id : 0" << std::endl
       << " marca : Honda" << std::endl
       << " conductor : Ramiro" << std::endl
       << " tipo : " << std::endl
       << " ubicacion : Lomas" << std::endl
       << " precio : 11.1" << std::endl
       << " asientos : 2" << std::endl;

    if (v1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << v1.toString() << std::endl;
    }

    std::cout << " Getters ";

    ss.str(""); // borra el contenido del stream
    ss << v1.getId() << v1.getMarca() << v1.getConductor() << v1.getAsientos();
    if (ss.str() == "0HondaRamiro2") {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << ss.str() << std::endl;
    }


    std::cout << " CalculaTarifa para auto ";

    // float no se puede comparar en decimales por precision con == ,
    // para evitar esto multiplicamos por 1000 para conservar los ultimos 3
    // decimales y comparamos como enteros solo para las pruebas.
    int test2 = v2.calculaTarifa() * 1000;
    if (test2 == 12.4 * 1000) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << std::endl;
    }

    std::cout << " CalculaTarifa para camioneta ";
    Vehiculo v3(2, "M", "Edu", "camioneta", "Metepec", 20.0, 6);

    test2 = v3.calculaTarifa() * 1000;
    if (test2 == 20.0 * 1.5 * 1000) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << std::endl;
    }

    std::cout << " CalculaTarifa para especial";
    Vehiculo v4(2, "M", "Edu", "especial", "Metepec", 21.1, 6);

    test2 = v4.calculaTarifa() * 1000;
    if (test2 == 21.1 * 2.0 * 1000) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << std::endl;
    }


    // Prueba 5: Clase Cliente.
    std::cout << std::endl << "Prueba 5 : métodos clase Cliente  " << std::endl;
    std::cout << " Constructor por defecto ";

    Cliente c1;

    ss.str("");
    ss << " nombre : " << std::endl
     << " ubicacion : " << std::endl
     << " necesidad : " << std::endl
     << " estatus : 0" << std::endl;

    if (c1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << c1.toString() << std::endl;
    }


    std::cout << " Constructor normal";
    Cliente c2("Benito Pérez", "silla de ruedas", "Coyoacan", false);

    ss.str("");
    ss << " nombre : Benito Pérez" << std::endl
     << " ubicacion : Coyoacan" << std::endl
     << " necesidad : silla de ruedas" << std::endl
     << " estatus : 0" << std::endl;


    if (c2.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << c2.toString() << std::endl;
    }


    std::cout << " Setters ";

    c1.setNecesidad("andadera");
    c1.setNombre("Agustin");
    c1.setUbicacion("Lienzo Charro");
    c1.setEstatus(true);

    ss.str("");
    ss << " nombre : Agustin" << std::endl
     << " ubicacion : Lienzo Charro" << std::endl
     << " necesidad : andadera" << std::endl
     << " estatus : 1" << std::endl;

    if (c1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << c1.toString() << std::endl;
    }

    std::cout << " Getters ";

    ss.str(""); // borra el contenido del stream
    ss << c1.getNecesidad() << c1.getNombre() << c1.getUbicacion()
      << c1.getEstatus();
    if (ss.str() == "andaderaAgustinLienzo Charro1") {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << ss.str() << std::endl;
    }

}
