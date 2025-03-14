#ifndef ASIGNACION_H
#define ASIGNACION_H

#define MAXC 20  ///< Maximo numero de clientees.
#define MAXV 9   ///< Maximo numero de Vehículos.

#include "Cliente.h"
#include "Vehiculo.h"

#include <string>
#include <sstream>

class Asignacion {
private:

public:

  Asignacion();

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
                          int asignaciones[MAXV]);


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
  std::string opNecesidad(std::string opNec);

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
  bool revisaYaAsignada(int idCliente, int asignaciones[MAXV]);

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
                            int asignaciones[MAXV]);
};

#endif
