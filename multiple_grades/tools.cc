// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero 
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo tools.h: contiene las definiciones de las clases declaradas en tools.h

#include <iostream>

#include "tools.h"

/**
 * @brief Funcion que asegura el correcto uso de la linea de ejecucion
 * @param argc Entero que contiene el numero de argumentos pasados por linea de ejecucion
 * @param argv Array que contiene los argumentos pasados por linea de ejecucion
*/
void Usage(int argc, char *argv[]) {
  switch (argc) {
    case 2: {
      std::string parametro = argv[1];
      if (parametro == "--help") {
        std::cout << "El programa se encarga de gestionar las calificaciones obtenidas por diferentes alumnos\
                      para poder ejeceutarlo es necesario un fichero .txt que contenga los datos de la siguiente manera:" << std::endl;
        std::cout << "aluXXXXXXXXXX nota" << std::endl;
        exit(EXIT_SUCCESS);
      } else {
        break;
      }
      break;
    }
    default: {
        std::cerr << argv[0] << ": Modo de empleo: ./p01_single_grades grades.txt" << std::endl;
		    std::cout << "Pruebe " << argv[0] << " --help para obtener mas informacion" << std::endl;
		    exit(EXIT_SUCCESS);
      break;
    }
  }
}