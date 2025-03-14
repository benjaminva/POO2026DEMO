# POO2026DEMO

### Contexto 
En el año 2022, en la ciudad de Ciudad de México, una startup de servicios de transporte llamada "MoviRápido" se enfrenta a un problema en la asignación de vehículos a los clientes. La empresa ha crecido rápidamente y ha aumentado su flota de vehículos, pero ha encontrado dificultades para asignar de manera eficiente y justa los vehículos a los clientes según sus necesidades y ubicaciones. El equipo de desarrollo ha decidido implementar un sistema de asignación utilizando programación orientada a objetos para mejorar la eficiencia y satisfacción del cliente. 

El problema específico radica en la falta de un sistema automatizado que considere múltiples variables, como la ubicación del cliente, la disponibilidad del vehículo y el tiempo estimado de llegada. Las partes involucradas incluyen a los desarrolladores de software, el equipo de operaciones y los conductores. El equipo ha decidido utilizar un lenguaje de programación orientado a objetos para diseñar y desarrollar esta solución. Los desarrolladores deben modelar el sistema utilizando diagramas de clases en UML y asegurar que la solución sea adaptable a diferentes escenarios de demanda y oferta. 
 
### Usuarios
Los usuarios del programa serán los conductores y los operadores de la compañía, es decir, tengo que tener en cuenta que el programa debe de adecuarse a los dos perfiles. 

### Funcionalidad
En el programa actual se puede:

1. Agregar petición , se crea un cliente con una necesidad

2. Asignar vehículos , se asignan los vahículos registrados en el programa para atender las peticiones de los clientes

3. Mostrar asignaciones , se genera un reporte sobre las asignaciones realizadas

### Pruebas para Escenarios Diferentes 
En el archivo pruebas.cpp se pueden ver las pruebas diseñadas para 3 escenarios extremos en el contexto del programa:

 * cuando no hay clientes
 * cuendo hay clientes
 * cuando se excede el número de clientes que se pueden asignar

Cada función involucrada en el proceso se prueba de forma separada y se compara contra el comportamiento esperado en el diseño de la prueba. 
Adicionalmente se prueba el uso de las clases creadas:

 * Vehiculo
 * Asignacion

### Guía de Estilo
Para mantener buen estilo en el código me basé en los materiales del curso y en la siguiente guía de recomendaciones de estilo:  https://lefticus.gitbooks.io/cpp-best-practices/content/03-Style.html# 
