#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>


/**
  * @brief Clase que representa un Vehiculo
  *
  * Contiene la información del tipo de vehículo y sus datos particulares.
  *
  * @author Benjamín Valdés Aguirre
  */
class Vehiculo {
  private:
    int id; ///< Identificador único del vehículo
    std::string marca; ///< Marca del vehículo
    std::string conductor; ///< Nombre del conductor del vehículo
    std::string tipo; ///< Tipo de vehículo (ej. coche, moto, camión)
    std::string ubicacion; ///< Ubicación actual del vehículo
    float precio; ///< Precio específico de este vehículo
    int asientos; ///< Número de asientos ocupables que trae el vehículo

  public:
    /**
     * @brief Constructor por defecto
     */
    Vehiculo();

    /**
     * @brief Constructor con parámetros
     * @param id Identificador único del vehículo
     * @param marca Marca del vehículo
     * @param conductor Nombre del conductor
     * @param tipo Tipo de vehículo
     */
    Vehiculo(int id, std::string marca, std::string conductor,
                std::string tipo, std::string ubicacion, float precio, int asientos);

    /**
     * @brief Obtiene el ID del vehículo
     * @return ID del vehículo
     */
    int getId() const;

    /**
     * @brief Obtiene la marca del vehículo
     * @return Marca del vehículo
     */
    std::string getMarca() const;

    /**
     * @brief Obtiene el nombre del conductor
     * @return Nombre del conductor
     */
    std::string getConductor() const;

    /**
     * @brief Obtiene el tipo de vehículo
     * @return Tipo de vehículo
     */
    std::string getTipo() const;

    /**
     * @brief Obtiene la ubiacaión del vehículo
     * @return Ubicacion de vehículo
     */
    std::string getUbicacion() const;

    /**
     * @brief Obtiene el número de asientos del vehículo
     * @return Numero de asientos
     */
    int getAsientos() const;

    /**
     * @brief Establece la marca del vehículo
     * @param ma Nueva marca del vehículo
     */
    void setMarca(std::string ma);

    /**
     * @brief Establece el nombre del conductor
     * @param cu Nuevo nombre del conductor
     */
    void setConductor(std::string cu);

    /**
     * @brief Establece la Ubicacion del vehículo
     * @param ubi Nuevo ubicación
     */
    void setUbicacion(std::string ubi);

    /**
     * @brief Establece el nuevo precio del vehículo
     * @param pre Nuevo precio
     */
    void setPrecio(float pre);

    /**
     * @brief Establece el número de asientos del vehículo
     * @param asi Nuevo número de asientos
     */
    void setAsientos(int asi);

    /**
     * @brief Calclula el costo del tipo de auto
     * @return Costo de la tarifa
     */
    float calculaTarifa();

    /**
     * @brief Devuelve la información del objeto en formato string
     * @return Información del obejto en string
     */
    std::string toString();

};

#endif
