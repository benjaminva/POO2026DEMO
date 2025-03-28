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
#include "Clientela.h"

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
    std::cout << "Prueba 6 : Clase Clientela" << std::endl;

    std::cout << "\nPrueba 1: Cuando los arreglos están vacíos" << std::endl;

    Asignacion a;
    Clientela clientelaAsig;
    std::string vehiculos[MAXV] = {"auto", "camioneta", "especial", "auto"};
    int numClientes = 0;

    // Prueba: No se puede asignar un vehículo cuando no hay clientes.
    std::cout << " Asignar vehículo";
    int test = a.asignarVehiculo(0, vehiculos, clientelaAsig);
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
    if (ss.str() == a.mostrarAsignaciones(vehiculos, clientelaAsig)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << a.mostrarAsignaciones(vehiculos, clientelaAsig) << std::endl;
    }

    // Prueba 2: Caso normal con asignaciones posibles e imposibles.
    std::cout << "\nPrueba 2: Caso normal" << std::endl;
    numClientes = 5;

    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i);
        clientelaAsig.creaCliente(testStr, "", 1, "ninguna");
    }

    std::cout << " Asignar vehículos cuando es posible" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (a.asignarVehiculo(i, vehiculos, clientelaAsig) != -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Asignar vehículos cuando no es posible" << std::endl;
    for (int i = 2; i < 5; i++) {
        if (a.asignarVehiculo(i, vehiculos, clientelaAsig) == -1) {
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
    ss << "--- Asignaciones Actuales ---" << std::endl
      << "Vehículo auto (ID: 0)  asignado a:" << std::endl
      << " nombre : test 0" << std::endl
      << " ubicacion : " << std::endl
      << " pasajeros : 1" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 0" << std::endl << std::endl
      << "Vehículo auto (ID: 3)  asignado a:" << std::endl
      << " nombre : test 1" << std::endl
      << " ubicacion : " << std::endl
      << " pasajeros : 1" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 0" << std::endl << std::endl
      << "-----------------------------" << std::endl;

    if (ss.str() == a.mostrarAsignaciones(vehiculos, clientelaAsig)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << a.mostrarAsignaciones(vehiculos, clientelaAsig) << std::endl;
    }

    // Prueba 3: Cuando se excede el tamaño de los arreglos.
    std::cout << "\nPrueba 3: Cuando se excede el tamaño máximo permitido "
              << " de los arreglos " << std::endl;

    std::cout << " Asignar vehículo fuera del rango" << std::endl;
    if (a.asignarVehiculo(5, vehiculos, clientelaAsig) == -1) {
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
     << " pasajeros : 0" << std::endl
     << " necesidad : " << std::endl
     << " estatus : 0" << std::endl;

    if (c1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << c1.toString() << std::endl;
    }


    std::cout << " Constructor normal";
    Cliente c2("Benito Pérez", "Coyoacan", 3, "silla de ruedas");

    ss.str("");
    ss << " nombre : Benito Pérez" << std::endl
     << " ubicacion : Coyoacan" << std::endl
     << " pasajeros : 3" << std::endl
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
     << " pasajeros : 0" << std::endl
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
      << c1.getEstatus() << c1.getPasajeros();
    if (ss.str() == "andaderaAgustinLienzo Charro10") {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << ss.str() << std::endl;
    }


    // Prueba 6: Clase Clientela.
    std::cout << std::endl << "Prueba 6 : métodos clase Clientela  " << std::endl;
    std::cout << " Constructor por defecto ";

    Clientela clientela;

    ss.str("");
    ss << "Clientela : " << std::endl;

    if (clientela.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << clientela.toString() << std::endl;
    }


    std::cout << " creaCliente ";

    clientela.creaCliente("hugo", "amealco", 4, "ninguna");
    clientela.creaCliente("paco", "huimilpan", 2, "silla de ruedas");
    clientela.creaCliente("luis", "periban", 1, "caja 100 kilos");

    ss.str("");

    ss << "Clientela : " << std::endl
      << " nombre : hugo" << std::endl
      << " ubicacion : amealco" << std::endl
      << " pasajeros : 4" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 0" << std::endl
      << " nombre : paco" << std::endl
      << " ubicacion : huimilpan" << std::endl
      << " pasajeros : 2" << std::endl
      << " necesidad : silla de ruedas" << std::endl
      << " estatus : 0" << std::endl
      << " nombre : luis" << std::endl
      << " ubicacion : periban" << std::endl
      << " pasajeros : 1" << std::endl
      << " necesidad : caja 100 kilos" << std::endl
      << " estatus : 0" << std::endl;


    if (clientela.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << clientela.toString() << std::endl;
    }


    std::cout << " eliminaCliente ";

    clientela.eliminaCliente(1);

    ss.str("");

    ss << "Clientela : " << std::endl
      << " nombre : hugo" << std::endl
      << " ubicacion : amealco" << std::endl
      << " pasajeros : 4" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 0" << std::endl
      << " nombre : luis" << std::endl
      << " ubicacion : periban" << std::endl
      << " pasajeros : 1" << std::endl
      << " necesidad : caja 100 kilos" << std::endl
      << " estatus : 0" << std::endl;

    if (clientela.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << clientela.toString() << std::endl;
    }

    std::cout << " filtraNecesidad 1 cliente ";

    ss.str("");

    ss << "clientes con necesidad : caja 100 kilos" << std::endl
      << " nombre : luis" << std::endl
      << " ubicacion : periban" << std::endl
      << " pasajeros : 1" << std::endl
      << " necesidad : caja 100 kilos" << std::endl
      << " estatus : 0" << std::endl;

    if (clientela.filtraNecesidad("caja 100 kilos") == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << clientela.filtraNecesidad("caja 100 kilos");
    }

    std::cout << " filtraNecesidad 2 cliente ";

    clientela.creaCliente("magy", "pachuca", 2, "caja 100 kilos");
    clientela.creaCliente("moni", "toluca", 5, "caja 100 kilos");


    ss.str("");

    ss << "clientes con necesidad : caja 100 kilos" << std::endl
      << " nombre : luis" << std::endl << " ubicacion : periban" << std::endl
      << " pasajeros : 1" << std::endl
      << " necesidad : caja 100 kilos" << std::endl
      << " estatus : 0" << std::endl
      << " nombre : magy" << std::endl << " ubicacion : pachuca" << std::endl
      << " pasajeros : 2" << std::endl
      << " necesidad : caja 100 kilos" << std::endl
      << " estatus : 0" << std::endl
      << " nombre : moni" << std::endl << " ubicacion : toluca" << std::endl
      << " pasajeros : 5" << std::endl
      << " necesidad : caja 100 kilos" << std::endl
      << " estatus : 0" << std::endl;

    if (clientela.filtraNecesidad("caja 100 kilos") == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << clientela.filtraNecesidad("caja 100 kilos");
    }

    std::cout << " consultaCliente valido ";

    Cliente ca = clientela.consultaCliente(0);

    ss.str("");

    ss << " nombre : hugo" << std::endl << " ubicacion : amealco" << std::endl
       << " pasajeros : 4" << std::endl
       << " necesidad : ninguna" << std::endl << " estatus : 0" << std::endl;
    if (ca.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << ca.toString() << std::endl;
    }

    std::cout << " consultaCliente invalido ";

    Cliente cb = clientela.consultaCliente(7);

    ss.str("");

    ss << " nombre : " << std::endl << " ubicacion : " << std::endl
       << " pasajeros : 0" << std::endl
       << " necesidad : " << std::endl << " estatus : 0" << std::endl;
    if (cb.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << cb.toString() << std::endl;
    }


}
