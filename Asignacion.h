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

  // distancias y listas de colonias obtenidas con chatgpt
  std::string ubicaciones[20] = {
    "Centro", "Vicente Guerrero", "Rincón de San Andrés", "Rinconada Morelos",
    "Mariano Escobedo", "Las Campanas", "La Cruz", "San Javier", "Pathé",
    "El Cortijo", "Diligencias",  "Calesa",
    "Calesa 2a Sección", "Villa Los Arcos", "Karina", "El Oasis",
    "Del Río", "El Cortijo II", "La Peñita" };

  float distancias[19][19] = {
            {0, 2.5, 3, 2, 1.5, 4, 5, 6, 7, 8, 3.5, 4, 4.5, 5, 6, 7, 8, 8.5, 9},
            {2.5, 0, 1.5, 1, 2, 3.5, 4.5, 5, 6, 7, 2, 3, 3.5, 4, 5, 6, 7, 7.5, 8},
            {3, 1.5, 0, 1.5, 2.5, 4, 5, 6, 7, 8, 3, 4, 4.5, 5, 6, 7, 8, 8.5, 9},
            {2, 1, 1.5, 0, 1, 3, 4, 5, 6, 7, 2, 3, 3.5, 4, 5, 6, 7, 7.5, 8},
            {1.5, 2, 2.5, 1, 0, 2.5, 3.5, 4, 5, 6, 1.5, 2, 2.5, 3, 4, 5, 6, 6.5, 7},
            {4, 3.5, 4, 3, 2.5, 0, 1, 2, 3, 4, 3, 3.5, 4, 4.5, 5, 6, 7, 7.5, 8},
            {5, 4.5, 5, 4, 3.5, 1, 0, 1, 2, 3, 4, 4.5, 5, 5.5, 6, 7, 8, 8.5, 9},
            {6, 5, 6, 5, 4, 2, 1, 0, 1, 2, 5, 5.5, 6, 6.5, 7, 8, 9, 9.5, 10},
            {7, 6, 7, 6, 5, 3, 2, 1, 0, 1, 6, 6.5, 7, 7.5, 8, 9, 10, 10.5, 11},
            {8, 7, 8, 7, 6, 4, 3, 2, 1, 0, 7, 7.5, 8, 8.5, 9, 10, 11, 11.5, 12},
            {3.5, 2, 3, 2, 1.5, 3, 4, 5, 6, 7, 0, 1, 1.5, 2, 3, 4, 5, 5.5, 6},
            {4, 3, 4, 3, 2, 3.5, 4.5, 5, 6, 7, 1, 0, 0.5, 1, 2, 3, 4, 4.5, 5},
            {4.5, 3.5, 4.5, 3.5, 2.5, 4, 5, 6, 7, 8, 1.5, 0.5, 0, 0.5, 1, 2, 3, 3.5, 4},
            {5, 4, 5, 4, 3, 4.5, 5.5, 6, 7, 8, 2, 1, 0.5, 0, 1, 2, 3, 3.5, 4},
            {6, 5, 6, 5, 4, 5, 6, 7, 8, 9, 3, 2, 1, 1, 0, 1, 2, 2.5, 3},
            {7, 6, 7, 6, 5, 6, 7, 8, 9, 10, 4, 3, 2, 2, 1, 0, 1, 1.5, 2},
            {8, 7, 8, 7, 6, 7, 8, 9, 10, 11, 5, 4, 3, 3, 2, 1, 0, 0.5, 1},
            {8.5, 7.5, 8.5, 7.5, 6.5, 7.5, 8.5, 9, 10, 11, 5.5, 4.5, 3.5, 3.5, 2.5, 1.5, 0.5, 0, 0.5},
            {9, 8, 9, 8, 7, 8, 9, 10, 11, 12, 6, 5, 4, 4, 3, 2, 1, 0.5, 0}
  };

  int convUbicacionNum(std::string ubicacion);

public:

  /**
  * @brief Constructor por defecto
  */
  Asignacion();


  std::string muestraUbicaciones();

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
