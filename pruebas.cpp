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
#include "Flota.h"

/**
 * @brief Pruebas de la funcionalidad del programa.
 *
 * Se realizan diversas pruebas para validar el correcto funcionamiento
 * de las funciones principales del programa, incluyendo la asignación
 * de vehículos, verificación de asignaciones y generación de reportes.
 *
 */
int main() {
    std::cout << "Reporte de pruebas por clases:" << std::endl;
    std::cout << "Prueba 1 : Clase Vehiculo abstracta" << std::endl;
    std::cout << "Prueba 2 : Clase Cliente" << std::endl;
    std::cout << "Prueba 3 : Clase Clientela" << std::endl;
    std::cout << "Prueba 4 : Clase hija Auto" << std::endl;
    std::cout << "Prueba 5 : Clase hija Camionte" << std::endl;
    std::cout << "Prueba 6 : Clase hija Especial" << std::endl;
    std::cout << "Prueba 7 : Clase Flota" << std::endl;
    std::cout << "Prueba 8 : Clase Asignacion" << std::endl;
    std::cout << "Prueba 9 : Clase Asignacion" << std::endl;
    std::cout << "Prueba 10 : Clase Asignacion" << std::endl;


    std::cout << std::endl << "Prueba 1 : métodos clase Vehiculo  "
              << std::endl;
    std::cout << " Las pruebas de Vechiculo se eliminaron por ser  "
              << std::endl;
    std::cout << " clase abstracta para consultarlas se puede " << std::endl;
    std::cout << " ver las pruebas las clases hijas" << std::endl;
    std::cout << " o el historial de commits" << std::endl;


    // Prueba 5: Clase Cliente.
    std::cout << std::endl << "Prueba 2 : métodos clase Cliente  " << std::endl;
    std::cout << " Constructor por defecto ";

    Cliente c1;

    std::stringstream ss;
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

    std::cout << " Constructor normal corto";
    Cliente c3("Benito Pérez", "Coyoacan", 3);

    ss.str("");
    ss << " nombre : Benito Pérez" << std::endl
     << " ubicacion : Coyoacan" << std::endl
     << " pasajeros : 3" << std::endl
     << " necesidad : " << std::endl
     << " estatus : 0" << std::endl;


    if (c3.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << c3.toString() << std::endl;
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

    std::cout << std::endl << "Prueba 3 : métodos clase Clientela  "
              << std::endl;
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
    clientela.creaCliente("luis", "periban", 4);

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
      << " estatus : 0" << std::endl
      << " nombre : luis" << std::endl
      << " ubicacion : periban" << std::endl
      << " pasajeros : 4" << std::endl
      << " necesidad : " << std::endl
      << " estatus : 0" << std::endl;

    if (clientela.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << clientela.toString() << std::endl;
    }


    std::cout << " eliminaCliente ";

    clientela.eliminaCliente(1);
    clientela.eliminaCliente(2);

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

    std::cout << std::endl << "Prueba 4 : métodos clase hija Auto" << std::endl;
    std::cout << " Constructor por defecto ";

    Auto auto1;

    ss.str("");
    ss << " id : 0" << std::endl
       << " marca : " << std::endl
       << " conductor : " << std::endl
       << " tipo : " << std::endl
       << " ubicacion : " << std::endl
       << " precio : 0" << std::endl
       << " asientos : 0" << std::endl;

    if (auto1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << auto1.toString() << std::endl;
    }


    std::cout << " Constructor normal";
    Auto auto2(10, "Mazda", "Mijares","Acapulco", 7.4, 4);

    ss.str("");
    ss << " id : 10" << std::endl
       << " marca : Mazda" << std::endl
       << " conductor : Mijares" << std::endl
       << " tipo : auto" << std::endl
       << " ubicacion : Acapulco" << std::endl
       << " precio : 7.4" << std::endl
       << " asientos : 4" << std::endl;

    if (auto2.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << auto2.toString() << std::endl;
    }

    std::cout << " CalculaTarifa ";
    float test2 = auto2.calculaTarifa();
    if (test2 > (7.4 - 0.001) && test2 < (7.4 + 0.001) ){
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << std::endl;
    }

    std::cout << std::endl << "Prueba 5 : métodos clase hija Camioneta"
    << std::endl;
    std::cout << " Constructor por defecto ";

    Camioneta cam1;

    ss.str("");
    ss << " id : 0" << std::endl
       << " marca : " << std::endl
       << " conductor : " << std::endl
       << " tipo : " << std::endl
       << " ubicacion : " << std::endl
       << " precio : 0" << std::endl
       << " asientos : 0" << std::endl
       << " modificador tarifa : 0"<< std::endl;


    if (cam1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << cam1.toString() << std::endl;
    }


    std::cout << " Constructor normal";
    Camioneta cam2(18, "Ford", "Luis Mirey","Edo de Mexico", 20.4, 7, 1.8);

    ss.str("");
    ss << " id : 18" << std::endl
       << " marca : Ford" << std::endl
       << " conductor : Luis Mirey" << std::endl
       << " tipo : camioneta" << std::endl
       << " ubicacion : Edo de Mexico" << std::endl
       << " precio : 20.4" << std::endl
       << " asientos : 7" << std::endl
       << " modificador tarifa : 1.8"<< std::endl;


    if (cam2.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << cam2.toString() << std::endl;
    }

    std::cout << " setter";
    cam2.setModTarifa(120.1);

    ss.str("");
    ss << " id : 18" << std::endl
       << " marca : Ford" << std::endl
       << " conductor : Luis Mirey" << std::endl
       << " tipo : camioneta" << std::endl
       << " ubicacion : Edo de Mexico" << std::endl
       << " precio : 20.4" << std::endl
       << " asientos : 7" << std::endl
       << " modificador tarifa : 120.1"<< std::endl;


    if (cam2.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << cam2.toString() << std::endl;
    }

    std::cout << " CalculaTarifa ";

    test2 = cam2.calculaTarifa();
    float test3 = 20.4 * 120.1;
    if (test2 > (test3 - 0.001) && test2 < (test3 + .001) ){
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << " " <<test3 << std::endl;
    }


    std::cout << std::endl << "Prueba 6 : métodos clase hija Especial"
    << std::endl;
    std::cout << " Constructor por defecto ";

    Especial esp1;

    ss.str("");
    ss << " id : 0" << std::endl
       << " marca : " << std::endl
       << " conductor : " << std::endl
       << " tipo : " << std::endl
       << " ubicacion : " << std::endl
       << " precio : 0" << std::endl
       << " asientos : 0" << std::endl
       << " modificador tarifa : 0" << std::endl
       << " espacio para silla de ruedas : 0" << std::endl
       << " tiene caja de carga : 0" << " capacidad kg : 0" << std::endl;


    if (esp1.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << esp1.toString() << std::endl;
    }


    std::cout << " Constructor normal silla ruedas ";
    Especial esp2(53, "Chrisler", "Bowey","Nuevo Leon", 30.4, 3,
                    2.1, true, false, 0);

    ss.str("");
    ss << " id : 53" << std::endl
       << " marca : Chrisler" << std::endl
       << " conductor : Bowey" << std::endl
       << " tipo : especial" << std::endl
       << " ubicacion : Nuevo Leon" << std::endl
       << " precio : 30.4" << std::endl
       << " asientos : 3" << std::endl
       << " modificador tarifa : 2.1" << std::endl
       << " espacio para silla de ruedas : 1" << std::endl
       << " tiene caja de carga : 0" << " capacidad kg : 0" << std::endl;


    if (esp2.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << esp2.toString() << std::endl;
    }

    std::cout << " Constructor normal caja de carga ";
    Especial esp3(71, "Chrisler", "Dan Brown","Sonora", 20.4, 2,
                    1.8, false, true, 500);

    ss.str("");
    ss << " id : 71" << std::endl
       << " marca : Chrisler" << std::endl
       << " conductor : Dan Brown" << std::endl
       << " tipo : especial" << std::endl
       << " ubicacion : Sonora" << std::endl
       << " precio : 20.4" << std::endl
       << " asientos : 2" << std::endl
       << " modificador tarifa : 1.8" << std::endl
       << " espacio para silla de ruedas : 0" << std::endl
       << " tiene caja de carga : 1" << " capacidad kg : 500" << std::endl;


    if (esp3.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << esp3.toString() << std::endl;
    }

    std::cout << " getters";

    ss.str("");
    ss << esp3.getSillaRuedas() << esp3.getCajaMaterial() << esp3.getPesoMax();

    if (ss.str() == "01500") {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << esp3.toString() << std::endl;
    }


    std::cout << " setters";
    esp3.setModTarifa(120.1);

    ss.str("");
    ss << " id : 71" << std::endl
       << " marca : Chrisler" << std::endl
       << " conductor : Dan Brown" << std::endl
       << " tipo : especial" << std::endl
       << " ubicacion : Sonora" << std::endl
       << " precio : 20.4" << std::endl
       << " asientos : 2" << std::endl
       << " modificador tarifa : 120.1" << std::endl
       << " espacio para silla de ruedas : 0" << std::endl
       << " tiene caja de carga : 1" << " capacidad kg : 500" << std::endl;


    if (esp3.toString() == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << esp3.toString() << std::endl;
    }

    std::cout << " CalculaTarifa  ";

    test2 = esp3.calculaTarifa();
    test3 = 20.4 * 120.1;
    if (test2 > (test3 - 0.001) && test2 < (test3 + .001) ){
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << std::endl;
    }

    std::cout << std::endl << "Prueba 7 : métodos Flota"
    << std::endl;

    Flota flota;

    std::cout << " crea Auto ";

    flota.creaAuto("Mazda", "Mijares","Acapulco", 7.4, 4);
    flota.creaAuto("Mazda", "Juan Gabriel","Michoacan", 8.0, 4);


    ss.str("");
    ss << "tipo auto :"<< std::endl;
    ss << " id : 0" << std::endl
       << " marca : Mazda" << std::endl
       << " conductor : Mijares" << std::endl
       << " tipo : auto" << std::endl
       << " ubicacion : Acapulco" << std::endl
       << " precio : 7.4" << std::endl
       << " asientos : 4" << std::endl;

    ss << " id : 1" << std::endl
       << " marca : Mazda" << std::endl
       << " conductor : Juan Gabriel" << std::endl
       << " tipo : auto" << std::endl
       << " ubicacion : Michoacan" << std::endl
       << " precio : 8" << std::endl
       << " asientos : 4" << std::endl;


    if (flota.filtrarVehiculo("tipo","auto") == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << flota.filtrarVehiculo("tipo","auto") << std::endl;
    }

    std::cout << " crea Camioneta ";


    flota.creaCamioneta("Ford", "Luis Mirey","Edo de Mexico", 20.4, 7, 1.8);
    flota.creaCamioneta("Ford", "Chayan","Chiapas", 10.4, 6, 2.8);

    ss.str("");
    ss << "tipo camioneta :"<< std::endl;
    ss << " id : 2" << std::endl
       << " marca : Ford" << std::endl
       << " conductor : Luis Mirey" << std::endl
       << " tipo : camioneta" << std::endl
       << " ubicacion : Edo de Mexico" << std::endl
       << " precio : 20.4" << std::endl
       << " asientos : 7" << std::endl
       << " modificador tarifa : 1.8"<< std::endl;

    ss << " id : 3" << std::endl
        << " marca : Ford" << std::endl
        << " conductor : Chayan" << std::endl
        << " tipo : camioneta" << std::endl
        << " ubicacion : Chiapas" << std::endl
        << " precio : 10.4" << std::endl
        << " asientos : 6" << std::endl
        << " modificador tarifa : 2.8"<< std::endl;

    if (flota.filtrarVehiculo("tipo","camioneta") == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << flota.filtrarVehiculo("tipo","camioneta") << std::endl;
    }

    std::cout << " crea especial ";


    flota.creaEspecial("Chrisler", "Dan Brown","Sonora", 20.4, 2,
      1.8, false, true, 500);
    flota.creaEspecial("Chrisler", "Humberto","Italia", 40.4, 1,
      1.8, false, true, 1000);
    flota.creaEspecial("Chrisler", "Jacopo","Italia", 40.4, 4,
      1.8, true, false, 0);

    ss.str("");
    ss << "tipo especial :"<< std::endl;
    ss << " id : 4" << std::endl
       << " marca : Chrisler" << std::endl
       << " conductor : Dan Brown" << std::endl
       << " tipo : especial" << std::endl
       << " ubicacion : Sonora" << std::endl
       << " precio : 20.4" << std::endl
       << " asientos : 2" << std::endl
       << " modificador tarifa : 1.8" << std::endl
       << " espacio para silla de ruedas : 0" << std::endl
       << " tiene caja de carga : 1" << " capacidad kg : 500" << std::endl;

   ss << " id : 5" << std::endl
      << " marca : Chrisler" << std::endl
      << " conductor : Humberto" << std::endl
      << " tipo : especial" << std::endl
      << " ubicacion : Italia" << std::endl
      << " precio : 40.4" << std::endl
      << " asientos : 1" << std::endl
      << " modificador tarifa : 1.8" << std::endl
      << " espacio para silla de ruedas : 0" << std::endl
      << " tiene caja de carga : 1" << " capacidad kg : 1000" << std::endl;

   ss << " id : 6" << std::endl
      << " marca : Chrisler" << std::endl
      << " conductor : Jacopo" << std::endl
      << " tipo : especial" << std::endl
      << " ubicacion : Italia" << std::endl
      << " precio : 40.4" << std::endl
      << " asientos : 4" << std::endl
      << " modificador tarifa : 1.8" << std::endl
      << " espacio para silla de ruedas : 1" << std::endl
      << " tiene caja de carga : 0" << " capacidad kg : 0" << std::endl;

    if (flota.filtrarVehiculo("tipo","especial") == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << flota.filtrarVehiculo("tipo","especial") << std::endl;
    }


    std::cout << " crea Camioneta y crea Espacial cortos: ";

    Flota f2;
    f2.creaCamioneta("Ford", "Chayan","Chiapas", 10.4, 6);
    f2.creaEspecial("Chrisler", "Dan Brown","Sonora", 20.4, 2, false, true, 500);

    ss.str("");
    ss << "todos  :"<< std::endl;
    ss << " id : 0" << std::endl
        << " marca : Ford" << std::endl
        << " conductor : Chayan" << std::endl
        << " tipo : camioneta" << std::endl
        << " ubicacion : Chiapas" << std::endl
        << " precio : 10.4" << std::endl
        << " asientos : 6" << std::endl
        << " modificador tarifa : 1.5"<< std::endl
        << " id : 1" << std::endl
        << " marca : Chrisler" << std::endl
        << " conductor : Dan Brown" << std::endl
        << " tipo : especial" << std::endl
        << " ubicacion : Sonora" << std::endl
        << " precio : 20.4" << std::endl
        << " asientos : 2" << std::endl
        << " modificador tarifa : 1.8" << std::endl
        << " espacio para silla de ruedas : 0" << std::endl
        << " tiene caja de carga : 1" << " capacidad kg : 500" << std::endl;

    if (f2.filtrarVehiculo("todos","") == ss.str()) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << f2.filtrarVehiculo("todos","") << std::endl;
    }

    std::cout << " promedio tarifas ";
    test3 = 10.4 * 1.5 + 20.4 * 1.8;
    test3 = test3/2;
    test2 = f2.promedioTarifas();

    if (test2 > (test3 - 0.001) && test2 < (test3 + 0.001)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test2 << " " << test3 << std::endl;
    }



    std::cout << std::endl << "Prueba 8: integración en asignación "
              << "cuando no hay clientes" << std::endl;

    Asignacion a;
    Clientela clientelaAsig;
    int numClientes = 0;

    std::cout << " Asignar vehículo";
    int test = a.asignarVehiculo(0, flota, clientelaAsig);
    if (test == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << test << std::endl;
    }

    std::cout << " Verificar si ya está asignado";
    if (!a.revisaYaAsignada(0)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << !a.revisaYaAsignada(0) << std::endl;
    }

    std::cout << " Mostrar asignaciones";
    ss.str("");
    ss << "--- Asignaciones Actuales ---\n-----------------------------\n";
    if (ss.str() == a.mostrarAsignaciones(flota, clientelaAsig)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << a.mostrarAsignaciones(flota, clientelaAsig) << ss.str()
                  << std::endl;
    }

    std::cout << std::endl << "Prueba 9:integración en asignación "
              << " cuando hay clientes" << std::endl;
    numClientes = 2;

    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i);
        clientelaAsig.creaCliente(testStr, "Acapulco", 2, "ninguna");
    }
    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i+numClientes);
        clientelaAsig.creaCliente(testStr, "Chiapas", 6, "ninguna");
    }
    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i+numClientes*2);
        clientelaAsig.creaCliente(testStr, "Michoacan", 3, "silla de ruedas");
    }
    for (int i = 0; i < numClientes; i++) {
        std::string testStr = "test " + std::to_string(i+numClientes*3);
        clientelaAsig.creaCliente(testStr, "Queretaro", 4, "caja 500 kilos");
    }

    std::cout << " Asignar vehículos cuando es posible" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (a.asignarVehiculo(i, flota, clientelaAsig) != -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }
    for (int i = 6; i < 8; i++) {
        if (a.asignarVehiculo(i, flota, clientelaAsig) != -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Asignar vehículos cuando no es posible" << std::endl;
    if (a.asignarVehiculo(5, flota, clientelaAsig) == -1) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }

    for (int i = 8; i < 10; i++) {
        if (a.asignarVehiculo(i, flota, clientelaAsig) == -1) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Verificar asignaciones cuando sí están asignadas"
              << std::endl;
    for (int i = 0; i < 5; i++) {
        if (a.revisaYaAsignada(i)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }
    for (int i = 6; i < 8; i++) {
        if (a.revisaYaAsignada(i)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Verificar asignaciones cuando no están asignadas"
              << std::endl;
    if (!a.revisaYaAsignada(5)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
    }
    for (int i = 8; i < 10; i++) {
        if (!a.revisaYaAsignada(i)) {
            std::cout << "  éxito" << std::endl;
        } else {
            std::cout << "  fracaso" << std::endl;
        }
    }

    std::cout << " Mostrar asignaciones con clientes asignados" << std::endl;
    ss.str(""); // borra el contenido del stream
    ss << "--- Asignaciones Actuales ---" << std::endl
      << " (asignacion : 0 )" << std::endl
      << " Vehículo :  id : 0" << std::endl
      << " marca : Mazda" << std::endl
      << " conductor : Mijares" << std::endl
      << " tipo : auto" << std::endl
      << " ubicacion : Acapulco" << std::endl
      << " precio : 7.4" << std::endl
      << " asientos : 4" << std::endl
      << " nombre : test 0" << std::endl
      << " ubicacion : Acapulco" << std::endl
      << " pasajeros : 2" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 1 )" << std::endl
      << " Vehículo :  id : 1" << std::endl
      << " marca : Mazda" << std::endl
      << " conductor : Juan Gabriel" << std::endl
      << " tipo : auto" << std::endl
      << " ubicacion : Michoacan" << std::endl
      << " precio : 8" << std::endl
      << " asientos : 4" << std::endl
      << " nombre : test 1" << std::endl
      << " ubicacion : Acapulco" << std::endl
      << " pasajeros : 2" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 2 )" << std::endl
      << " Vehículo :  id : 2" << std::endl
      << " marca : Ford" << std::endl
      << " conductor : Luis Mirey" << std::endl
      << " tipo : camioneta" << std::endl
      << " ubicacion : Edo de Mexico" << std::endl
      << " precio : 20.4" << std::endl
      << " asientos : 7" << std::endl
      << " modificador tarifa : 1.8" << std::endl
      << " nombre : test 3" << std::endl
      << " ubicacion : Chiapas" << std::endl
      << " pasajeros : 6" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 3 )" << std::endl
      << " Vehículo :  id : 3" << std::endl
      << " marca : Ford" << std::endl
      << " conductor : Chayan" << std::endl
      << " tipo : camioneta" << std::endl
      << " ubicacion : Chiapas" << std::endl
      << " precio : 10.4" << std::endl
      << " asientos : 6" << std::endl
      << " modificador tarifa : 2.8" << std::endl
      << " nombre : test 2" << std::endl
      << " ubicacion : Chiapas" << std::endl
      << " pasajeros : 6" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 4 )" << std::endl
      << " Vehículo :  id : 4" << std::endl
      << " marca : Chrisler" << std::endl
      << " conductor : Dan Brown" << std::endl
      << " tipo : especial" << std::endl
      << " ubicacion : Sonora" << std::endl
      << " precio : 20.4" << std::endl
      << " asientos : 2" << std::endl
      << " modificador tarifa : 1.8" << std::endl
      << " espacio para silla de ruedas : 0" << std::endl
      << " tiene caja de carga : 1 capacidad kg : 500" << std::endl
      << " nombre : test 6" << std::endl
      << " ubicacion : Queretaro" << std::endl
      << " pasajeros : 4" << std::endl
      << " necesidad : caja 500 kilos" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 5 )" << std::endl
      << " Vehículo :  id : 5" << std::endl
      << " marca : Chrisler" << std::endl
      << " conductor : Humberto" << std::endl
      << " tipo : especial" << std::endl
      << " ubicacion : Italia" << std::endl
      << " precio : 40.4" << std::endl
      << " asientos : 1" << std::endl
      << " modificador tarifa : 1.8" << std::endl
      << " espacio para silla de ruedas : 0" << std::endl
      << " tiene caja de carga : 1 capacidad kg : 1000" << std::endl
      << " nombre : test 7" << std::endl
      << " ubicacion : Queretaro" << std::endl
      << " pasajeros : 4" << std::endl
      << " necesidad : caja 500 kilos" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 6 )" << std::endl
      << " Vehículo :  id : 6" << std::endl
      << " marca : Chrisler" << std::endl
      << " conductor : Jacopo" << std::endl
      << " tipo : especial" << std::endl
      << " ubicacion : Italia" << std::endl
      << " precio : 40.4" << std::endl
      << " asientos : 4" << std::endl
      << " modificador tarifa : 1.8" << std::endl
      << " espacio para silla de ruedas : 1" << std::endl
      << " tiene caja de carga : 0 capacidad kg : 0" << std::endl
      << " nombre : test 4" << std::endl
      << " ubicacion : Michoacan" << std::endl
      << " pasajeros : 3" << std::endl
      << " necesidad : silla de ruedas" << std::endl
      << " estatus : 1" << std::endl << std::endl
      << "-----------------------------" << std::endl;

    if (ss.str() == a.mostrarAsignaciones(flota, clientelaAsig)) {
        std::cout << "  éxito" << std::endl;
    } else {
        std::cout << "  fracaso" << std::endl;
        std::cout << a.mostrarAsignaciones(flota, clientelaAsig) << std::endl;
        std::cout << ss.str() << std::endl;
    }


    std::cout << "\nPrueba 10: integración en asignación cuando hay más"
              << " clientes que los soportados por clientela " << std::endl;

    std::cout << " Asignar "<< " Vehículo fuera del rango" << std::endl;
    if (a.asignarVehiculo(5, flota, clientelaAsig) == -1) {
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


    std::cout << "\nPrueba 11: matriz de distancia" << std::endl;

    Asignacion distAsig;
    Flota f3;

    f3.creaAuto("Mazda", "Mijares","Centro", 7.4, 4);
    f3.creaAuto("Mazda", "Juan Gabriel","La Cruz", 8.0, 4);
    f3.creaAuto("Honda", "Rigo Tobar","Calesa", 7.4, 4);
    f3.creaAuto("Honda", "Ana Gabriel","Las Campanas", 8.0, 4);

    Clientela cl3;

    cl3.creaCliente("Benjamin", "Karina", 3, "ninguna");
    cl3.creaCliente("Eduardo", "Centro", 2, "ninguna");

    distAsig.asignarVehiculo(0,f3,cl3);
    distAsig.asignarVehiculo(1,f3,cl3);

    ss.str(""); // borra el contenido del stream
    ss << "--- Asignaciones Actuales ---" << std::endl
      << " (asignacion : 0 )" << std::endl
      << " Vehículo :  id : 0" << std::endl
      << " marca : Mazda" << std::endl
      << " conductor : Mijares" << std::endl
      << " tipo : auto" << std::endl
      << " ubicacion : Centro" << std::endl
      << " precio : 7.4" << std::endl
      << " asientos : 4" << std::endl
      << " nombre : Eduardo" << std::endl
      << " ubicacion : Centro" << std::endl
      << " pasajeros : 2" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << " (asignacion : 2 )" << std::endl
      << " Vehículo :  id : 2" << std::endl
      << " marca : Honda" << std::endl
      << " conductor : Rigo Tobar" << std::endl
      << " tipo : auto" << std::endl
      << " ubicacion : Calesa" << std::endl
      << " precio : 7.4" << std::endl
      << " asientos : 4" << std::endl
      << " nombre : Benjamin" << std::endl
      << " ubicacion : Karina" << std::endl
      << " pasajeros : 3" << std::endl
      << " necesidad : ninguna" << std::endl
      << " estatus : 1" << std::endl<< std::endl
      << "-----------------------------" << std::endl;

      if (ss.str() ==  distAsig.mostrarAsignaciones(f3, cl3)) {
          std::cout << "  éxito" << std::endl;
      } else {
          std::cout << "  fracaso" << std::endl;
          std::cout << ss.str() << std::endl;
          std::cout << distAsig.mostrarAsignaciones(f3, cl3) << std::endl;
      }

}
