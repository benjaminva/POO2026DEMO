#ifndef CLIENTELA_H
#define CLIENTELA_H


#define MAXC 100  ///< Maximo numero de clientes.

#include "Cliente.h"
#include <string>

/**
 * @brief Clase que representa a un grupo de Clientes.
 *
 * La clase Clientela almacena información sobre los clientes existentes y,
 * tiene una serie de métodos para filtrarlos y organizarlos.
 *
 * @author Benjamin Valdes Aguirre
 */
class Clientela {
private:
  Cliente clientes[MAXC]; ///< clientes
  int indCliente; ///< número actual de clientes.

public:

  /**
   * @brief Constructor por defecto de la clase Clientela.
   */
  Clientela();

  /**
   * @brief Devuelve el cliente.
   */
  int getIndCliente();

  /**
   * @brief Crea un objeto cliente y lo agrega al arreglo clientes.
   *
   * @param nom Nombre del cliente.
   * @param ubi Ubicación del cliente.
   * @param pas Cantidad de pasajeros.
   * @param nec Necesidad del cliente.
   */
  void creaCliente(std::string nom, std::string ubi, int pas, std::string nec);

  /**
   * @brief Crea un objeto cliente y lo agrega al arreglo clientes.
   *
   * @param nom Nombre del cliente.
   * @param ubi Ubicación del cliente.
   * @param pas Cantidad de pasajeros.
   */
  void creaCliente(std::string nom, std::string ubi, int pas);

  /**
   * @brief elimina el objeto cliente y recorre los demás.
   *
   * @param indice Posicion del objeto a a borrar del arreglo de clientes.
   */
  void eliminaCliente(int indice);


  /**
   * @brief Muestra los clientes con necesidades específicas.
   *
   * @param necesidad La necesidad usada para filtrar a los clientes.
   */
  std::string filtraNecesidad(std::string necesidad);

  /**
   * @brief Devuelve el objeto en esa posición del arreglo.
   *
   * @param indice La posición del objeto que será devuelto.
   *
   * @return objeto tipo Cliente
   */
  Cliente consultaCliente(int indice);

  /**
   * @brief modifica el objeto en esa posición del arreglo.
   *
   * @param indice La posición del objeto que será devuelto.
   * @param at Atributo a modificar.
   * @param val Valor a asignar.
   *
   * @return objeto tipo Cliente
   */
  void modificaCliente(int indice, std::string at, std::string val);

  /**
   * @brief Devuelve la información de los clientes en formato string
   *
   * @return Información del objeto en string
   */
  std::string toString();

};

#endif // CLIENTELA_H
