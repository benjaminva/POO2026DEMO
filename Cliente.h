#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

/**
 * @brief Clase que representa a un Cliente.
 *
 * La clase Cliente almacena información sobre un cliente, incluyendo su nombre, necesidad,
 * ubicación y estado.
 *
 * @author Benjamin Valdes Aguirre
 */
class Cliente {
private:
    std::string nombre; ///< Nombre del cliente.
    std::string ubicacion; ///< Ubicación del cliente.
    std::string necesidad; ///< Necesidad del cliente.
    int pasajeros; ///< Numero de pasajeros que el cliente ocupa en el viaje.
    bool estatus; ///< Estado del cliente (activo/inactivo).

public:
    /**
     * @brief Constructor de la clase Cliente por Defecto.
     */
    Cliente();

    /**
     * @brief Constructor de la clase Cliente.
     * @param nom Nombre del cliente.
     * @param ubi Ubicación del cliente.
     * @param pas Cantidad de pasajeros.
     * @param nec Necesidad del cliente.
     */
    Cliente(std::string nom, std::string ubi, int pas, std::string nec);

    /**
     * @brief Obtiene el nombre del cliente.
     * @return El nombre del cliente.
     */
    std::string getNombre() const;

    /**
     * @brief Obtiene la ubicación del cliente.
     * @return La ubicación del cliente.
     */
    std::string getUbicacion() const;

    /**
     * @brief Obtiene la necesidad del cliente.
     * @return La necesidad del cliente.
     */
    std::string getNecesidad() const;

    /**
     * @brief Obtiene el numero de pasajeros.
     * @return int Numero de pasejeros.
     */
    int getPasajeros() const;

    /**
     * @brief Obtiene el estado del cliente.
     * @return `true` si el cliente está activo, `false` si está inactivo.
     */
    bool getEstatus() const;

    /**
     * @brief Establece una nueva necesidad para el cliente.
     * @param nuevaNec Nueva necesidad del cliente.
     */
    void setNecesidad(std::string nuevaNec);

    /**
     * @brief Establece un nuevo nombre para el cliente.
     * @param nuevoNom Nuevo nombre del cliente.
     */
    void setNombre(std::string nuevoNom);

    /**
     * @brief Establece una nueva ubicación para el cliente.
     * @param nuevaUbi Nueva ubicación del cliente.
     */
    void setUbicacion(std::string nuevaUbi);

    /**
     * @brief Establece un nuevo estado para el cliente.
     * @param nuevoEst Nuevo estado del cliente (`true` para activo, `false` para inactivo).
     */
    void setEstatus(bool nuevoEst);

    /**
     * @brief Devuelve la información del objeto en formato string
     * @return Información del objeto en string
     */
    std::string toString();
};

#endif // CLIENTE_H
