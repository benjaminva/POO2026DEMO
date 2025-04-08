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
  protected:
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
    virtual float calculaTarifa() = 0;

    /**
     * @brief Devuelve la información del objeto en formato string
     * @return Información del obejto en string
     */
    virtual std::string toString();

};

/**
  * @brief Clase que representa un auto derivado de un Vehiculo
  *
  * Contiene la información auto.
  *
  * @author Benjamín Valdés Aguirre
  */
class Auto : public Vehiculo{
  public:

    /**
     * @brief Constructor por defetco
     */
    Auto();

    /**
     * @brief Constructor con parámetros
     * @param id Identificador único del vehículo
     * @param marca Marca del vehículo
     * @param conductor Nombre del conductor
     * @param tipo Tipo de vehículo
     */
    Auto(int id, std::string marca, std::string conductor,
        std::string ubicacion, float precio, int asientos);

    /**
     * @brief Devuelve la información del objeto en formato string
     * @return Información del obejto en string
     */
    std::string toString();


    /**
     * @brief Calclula el costo del tipo de auto
     * @return Costo de la tarifa
     */
    float calculaTarifa();


};

/**
  * @brief Clase que representa un auto derivado de un Vehiculo
  *
  * Contiene la información auto.
  *
  * @author Benjamín Valdés Aguirre
  */
class Camioneta : public Vehiculo{
  private:
    float modTarifa;

  public:

    /**
     * @brief Constructor por defetco
     */
    Camioneta();

    /**
     * @brief Constructor con parámetros
     * @param id Identificador único del vehículo
     * @param marca Marca del vehículo
     * @param conductor Nombre del conductor
     * @param tipo Tipo de vehículo
     * @param tarifa El monto modifacadore de tarifas 1.5 1.8
     */
    Camioneta(int id, std::string marca, std::string conductor,
        std::string ubicacion, float precio, int asientos, float modTarifa);

    /**
     * @brief Constructor con parámetros
     * @param id Identificador único del vehículo
     * @param marca Marca del vehículo
     * @param conductor Nombre del conductor
     * @param tipo Tipo de vehículo
     * @param tarifa El monto modifacadore de tarifas 1.5 1.8
     */
    Camioneta(int id, std::string marca, std::string conductor,
        std::string ubicacion, float precio, int asientos);

    /**
     * @brief Actualiza el valor del modificador de la tarifa
     * @param tar Valor del nuevo modifcador de la tarifa
     */
    void setModTarifa( float tar);

    /**
     * @brief Devuelve la información del objeto en formato string
     * @return Información del obejto en string
     */
    std::string toString();


    /**
      * @brief Calclula el costo del tipo de auto
      * @return Costo de la tarifa
      */
    float calculaTarifa();


};

/**
  * @brief Clase que representa un auto derivado de un Vehiculo
  *
  * Contiene la información auto.
  *
  * @author Benjamín Valdés Aguirre
  */
class Especial : public Vehiculo{
  private:
    float modTarifa;
    bool sillaRuedas;
    bool cajaMaterial;
    float pesoMax;


  public:

    /**
     * @brief Constructor por defetco
     */
    Especial();

    /**
     * @brief Constructor con parámetros
     * @param id Identificador único del vehículo
     * @param marca Marca del vehículo
     * @param conductor Nombre del conductor
     * @param tipo Tipo de vehículo
     * @param tarifa El monto modifacadore de tarifas 1.5 1.8
     * @param sillaRuedas Si el vehiculo cuenta con silla de ruedas
     * @param cajaMateial Si el vehículo cuenta con caja para material
     * @param pesoMax Valor máximo de peso que soporta la caja de carga
     */
    Especial(int id, std::string marca, std::string conductor,
       std::string ubicacion, float precio,
       int asientos, float modTarifa,  bool sillaRuedas,
       bool cajaMaterial, float pesoMax);

    /**
     * @brief Constructor con parámetros donde la tarifa se infiere a partir del
     *        tipo de necesidad : silla de ruedas  ->   2.0
     *                            cajaMaterial 500 ->   1.8
     *                            cajaMaterial 1000 ->  2.1
     * @param id Identificador único del vehículo
     * @param marca Marca del vehículo
     * @param conductor Nombre del conductor
     * @param tipo Tipo de vehículo
     * @param sillaRuedas Si el vehiculo cuenta con silla de ruedas
     * @param cajaMateial Si el vehículo cuenta con caja para material
     * @param pesoMax Valor máximo de peso que soporta la caja de carga
     */
    Especial(int id, std::string marca, std::string conductor,
       std::string ubicacion, float precio, int asientos, bool sillaRuedas,
       bool cajaMaterial, float pesoMax);


    /**
     * @brief Si el vehiculo tiene espacio para silla de ruedas o no
     * @return Verdadero si tiene espacio para silla de ruedas
     */
    bool getSillaRuedas() const;

    /**
     * @brief Si el vehiculo tiene caja trasera para carga de material
     * @return Verdadero si tiene caja
     */
    bool getCajaMaterial() const;

    /**
     * @brief Obtiene el peso maximo que puede cargar el vehículo
     * @return Peso Máximo
     */
    float getPesoMax() const;

    /**
     * @brief Actualiza el valor del modificador de la tarifa
     * @param tar Valor del nuevo modifcador de la tarifa
     */
    void setModTarifa( float tar ) ;

    /**
     * @brief Devuelve la información del objeto en formato string
     * @return Información del obejto en string
     */
    std::string toString();

    /**
      * @brief Calclula el costo del tipo de auto
      * @return Costo de la tarifa
      */
    float calculaTarifa();



};

#endif // VEHICULO_H
