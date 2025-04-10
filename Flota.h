#ifndef FLOTA_H
#define FLOTA_H

#define MAXV 100 // Número máximo de vehículos por tipo

#include <string>
#include "Vehiculo.h"

class Flota {
  private:
    Vehiculo **vehiculos;  ///< arreglo dinámico de vehiculos en el heap
    int capacidad;  ///< Tamaño máximo del arreglo antes de ajustarse
    int idVehiculo; ///< posisción de siguiente vehiculo a registrar en arreglo


    /**
     * @brief Duplica la capacidad del arreglo cada que vehiculos se llena
     */
    void redimensionaArreglo();

  public:

      Flota();

      /**
       * @brief Crea un objeto Auto en la flota
       *
       * @param marca Marca del vehículo
       * @param conductor Nombre del conductor
       * @param ubicacion Ubicación actual del vehículo
       * @param precio Precio específico del vehículo
       * @param asientos Número de asientos del vehículo
       */
      void creaAuto(std::string marca, std::string conductor,
          std::string ubicacion, float precio, int asientos);

      /**
       * @brief Crea un objeto Camioneta en la flota
       *
       * @param marca Marca del vehículo
       * @param conductor Nombre del conductor
       * @param ubicacion Ubicación actual del vehículo
       * @param precio Precio específico del vehículo
       * @param asientos Número de asientos del vehículo
       * @param modTarifa Modificador de la tarifa
       */
      void creaCamioneta(std::string marca, std::string conductor,
          std::string ubicacion, float precio, int asientos, float modTarifa);

      /**
       * @brief Crea un objeto Camioneta en la flota
       *
       * @param marca Marca del vehículo
       * @param conductor Nombre del conductor
       * @param ubicacion Ubicación actual del vehículo
       * @param precio Precio específico del vehículo
       * @param asientos Número de asientos del vehículo
       */
      void creaCamioneta(std::string marca, std::string conductor,
          std::string ubicacion, float precio, int asientos);

      /**
       * @brief Crea un objeto Especial en la flota
       *
       * @param marca Marca del vehículo
       * @param conductor Nombre del conductor
       * @param ubicacion Ubicación actual del vehículo
       * @param precio Precio específico del vehículo
       * @param asientos Número de asientos del vehículo
       * @param modTarifa Modificador de la tarifa
       * @param sillaRuedas Indica si el vehículo tiene espacio para
       *  silla de ruedas
       * @param cajaMaterial Indica si el vehículo tiene caja para
       *  carga de material
       * @param pesoMax Peso máximo que puede cargar el vehículo
       */
      void creaEspecial(std::string marca, std::string conductor,
         std::string ubicacion, float precio,
         int asientos, float modTarifa,  bool sillaRuedas,
         bool cajaMaterial, float pesoMax);

      /**
       * @brief Crea un objeto Especial en la flota
       *
       * @param marca Marca del vehículo
       * @param conductor Nombre del conductor
       * @param ubicacion Ubicación actual del vehículo
       * @param precio Precio específico del vehículo
       * @param asientos Número de asientos del vehículo
       * @param sillaRuedas Indica si el vehículo tiene espacio para
       *  silla de ruedas
       * @param cajaMaterial Indica si el vehículo tiene caja para
       *  carga de material
       * @param pesoMax Peso máximo que puede cargar el vehículo
       */
      void creaEspecial(std::string marca, std::string conductor,
         std::string ubicacion, float precio,
         int asientos, bool sillaRuedas,
         bool cajaMaterial, float pesoMax);

     /**
      * @brief Devuelve el numero de vehiculos registrados en el
      *  arreglo vehiculos
      *
      * @return Entenro con la variable idVehiculoo
      */
      int getIdVehiculo() const;

      /**
       * @brief Devuelve el apuntador al objeto vehículo en la posición id
       *
       * @param id Entero con el indice del objeto a obtener
       *
       * @return Apuntador a objeto Vehiculo
       */
      Vehiculo* obtenVehiculo(int id);

      /**
       * @brief Filtra vehículos por un atributo (ej. "marca" o "conductor")
       *  y un valor específico
       *
       * @param atributo Atributo por el cual se filtrará
       * @param valor Valor del atributo a buscar
       *
       * @return Cadena con los vehículos que cumplen el criterio de filtrado
       */
      std::string filtrarVehiculo(std::string atributo, std::string valor);

      /**
       * @brief Calcula el promedio de tarifas de todos los vehículos en
       *  la flota
       *
       * @return Promedio de tarifas
       */
      float promedioTarifas();
};

#endif // FLOTA_H
