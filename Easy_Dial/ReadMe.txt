###EasyDial - Sistema de Gestión de Llamadas Telefónicas###

##Descripción del Proyecto:
	El sistema EasyDial es un conjunto de clases diseñado para gestionar información relacionada con llamadas telefónicas. El proyecto consta de tres módulos principales:


g
##Módulo de Registro de Llamadas (call_registry):
	Almacena y gestiona información sobre números de teléfono, nombres asociados y frecuencia de llamadas a cada uno.
	Permite consultas eficientes sobre la información almacenada.

##Módulo de Interacción con el Usuario (dialog):
	Implementa una función que simula la interacción en la que se ingresa un nombre letra a letra en un teléfono móvil.
	Presenta en pantalla los nombres y el número de teléfono final en función de la entrada del usuario.
	Utiliza la clase easy_dial para recopilar información de la clase call_registry.

##Módulo Principal (driver_EasyDial):
	Contiene el programa principal que utiliza todas las clases implementadas.
	Permite invocar operaciones de cada módulo y clase.



##Diseño Modular:
	El sistema se compone de clases interconectadas: phone, call_registry, easy_dial, y dialog. El módulo driver_EasyDial utiliza todas estas clases para realizar operaciones específicas.



##Implementación:
	#phone (phone.cpp, phone.hpp, phone.rep):
		Gestiona los datos asociados a un teléfono: número, nombre y contador de llamadas.
		Se proporcionan los métodos de construcción por còpia, asignación y destrucción.
	
	#call_registry (call_registry.cpp, call_registry.hpp, call_registry.rep):
		Almacena y gestiona información detallada sobre llamadas telefónicas.
		Proporciona métodos para realizar consultas eficientes.

	#easy_dial (easy_dial.cpp, easy_dial.hpp, easy_dial.rep):
		Recopila información de la clase call_registry y la almacena de manera eficiente.
		Contribuye a la "inteligencia" del sistema EasyDial.

	#dialog (dialog.cpp, dialog.hpp):
		Simula la interacción del usuario, ingresando nombres letra a letra y presentando resultados en pantalla.
		Utiliza la clase easy_dial para acceder a la información necesaria.



##Compilación y Ejecución:
	El proyecto proporciona un archivo Makefile para facilitar la compilación. Para compilar el programa, ejecuta el siguiente comando en la terminal: make
	Esto generará un ejecutable llamado program.exe. Puedes ejecutar el programa con:./program.exe