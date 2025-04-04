#ifndef ASIGNACION_H
#define ASIGNACION_H

#include "Cliente.h"
#include "Clientela.h"
#include "Vehiculo.h"
#include "Flota.h"

#include <string>
#include <sstream>

class Asignacion {
private:

  int asignaciones[MAXV]; ///< Asignaciones entre vehiculo (pos) y cliente (val)

public:

  /**
  * @brief Constructor por defecto
  */
  Asignacion();

  /**
   * @brief Devuelve un valor de distancia entre 2 ubicaciones.
   *
   * Mapea los strings v y c para mapearlos a ubicaciones en una matriz y
   * obtiene la distancia registrada en la matriz de
   *
   * @param v Ubicación del vehiculo.
   * @param c Ubicación del cliente.
   *
   * @return Entero con el valor de la distancia entre el las ubicaciones.
   */

  int calculaDistancia(std::string v, std::string c);

  /**
   * @brief Asigna los vehiculos a los viajes.
   *
   * Usando el indice de la cliente verifica que exista un vehiculo que pueda
   * atender la petición y asigna la petición al arreglo.
   *
   * @param indiceP Indice de la Petición a agergar.
   * @param vehiculos Arreglo con los vehículos.
   * @param clientes Arreglo de objetos con los clientes.
   *
   * @return -1 si no se pudo agregar la petición o la posición donde se asignó
   * la petición .
   */
  int asignarVehiculo(int indiceP, Flota& flota,
                          Clientela& clientela);


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
   *
   * @return boolean true si encuentra la petición en el arreglo sino false
   *
   */
  bool revisaYaAsignada(int idCliente);

  /**
   * @brief Muestra un reporte de las asignaciones generadas.
   *
   * recorre el arreglo de asignaciones y muestra el vehiculo y al cliente
   * correspondiente
   *
   * @param vehiculos Arreglo con los vehículos.
   * @param clientes Arreglos de cleintes.
   *
   * @return string con el reporte de las asignaciones.
   *
   */
  std::string mostrarAsignaciones(Flota& flota,
                            Clientela& clientela);
};

#endif // ASIGNACION_H
