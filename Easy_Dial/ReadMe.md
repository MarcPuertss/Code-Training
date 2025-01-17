# EasyDial - Sistema de Gestión de Llamadas Telefónicas

**EasyDial** es un sistema modular diseñado para gestionar y consultar información relacionada con llamadas telefónicas. Este proyecto consta de varios módulos que interactúan entre sí para ofrecer una experiencia eficiente y funcional.

---

## Descripción del Proyecto
El sistema EasyDial está compuesto por tres módulos principales:

1. **Módulo de Registro de Llamadas (`call_registry`)**:  
   - Almacena y gestiona información sobre números de teléfono, nombres asociados y frecuencia de llamadas.  
   - Proporciona consultas eficientes sobre los datos almacenados.

2. **Módulo de Interacción con el Usuario (`dialog`)**:  
   - Simula la interacción donde el usuario introduce un nombre letra por letra en un teclado telefónico.  
   - Presenta en pantalla los nombres asociados y el número de teléfono correspondiente.  
   - Utiliza la clase `easy_dial` para recopilar información desde el módulo `call_registry`.

3. **Módulo Principal (`driver_EasyDial`)**:  
   - Implementa el programa principal que integra las operaciones de todos los módulos y clases.  
   - Permite invocar funciones específicas de cada componente.

---

## Diseño Modular
EasyDial está compuesto por cuatro clases principales:

- **`phone`**: Gestiona los datos básicos de un teléfono, como el número, el nombre asociado y un contador de llamadas.  
- **`call_registry`**: Almacena información detallada sobre las llamadas y permite realizar consultas optimizadas.  
- **`easy_dial`**: Recopila y organiza los datos de `call_registry` para ofrecer búsquedas inteligentes.  
- **`dialog`**: Simula la interacción del usuario y proporciona los resultados de manera visual.

El módulo principal (`driver_EasyDial`) utiliza estas clases para integrar todas las funcionalidades del sistema.

---

## Implementación

### Estructura del Código
- **`phone`** (`phone.cpp`, `phone.hpp`, `phone.rep`):  
  - Gestiona datos como número, nombre y contador de llamadas.  
  - Incluye métodos para construcción por copia, asignación y destrucción.  

- **`call_registry`** (`call_registry.cpp`, `call_registry.hpp`, `call_registry.rep`):  
  - Almacena y gestiona información detallada sobre las llamadas.  
  - Ofrece métodos para realizar consultas de manera eficiente.  

- **`easy_dial`** (`easy_dial.cpp`, `easy_dial.hpp`, `easy_dial.rep`):  
  - Organiza y recopila información del módulo `call_registry`.  
  - Aporta la "inteligencia" del sistema EasyDial.  

- **`dialog`** (`dialog.cpp`, `dialog.hpp`):  
  - Simula la interacción con el usuario.  
  - Permite ingresar nombres letra a letra y muestra resultados basados en los datos de `easy_dial`.  

---

## Compilación y Ejecución

### Compilación
El proyecto incluye un archivo **Makefile** para simplificar la compilación.  
Para compilar el programa, ejecuta el siguiente comando en la terminal:  
make
Esto generará un archivo ejecutable llamado program.exe.
