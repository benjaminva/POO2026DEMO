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
    Vehiculo(int id, std::string marca,
              std::string conductor, std::string tipo);

    /**
     * @brief Obtiene el ID del vehículo
     * @return ID del vehículo
     */
    int getId();

    /**
     * @brief Obtiene la marca del vehículo
     * @return Marca del vehículo
     */
    std::string getMarca();

    /**
     * @brief Obtiene el nombre del conductor
     * @return Nombre del conductor
     */
    std::string getConductor();

    /**
     * @brief Obtiene el tipo de vehículo
     * @return Tipo de vehículo
     */
    std::string getTipo();

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
};

#endif
