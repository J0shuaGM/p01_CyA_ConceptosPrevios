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

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <set>

#include "tools.h"

/**
 * @brief Funcion que asegura el correcto uso de la linea de ejecucion
 * @param argc Entero que contiene el numero de argumentos pasados por linea de ejecucion
 * @param argv Array que contiene los argumentos pasados por linea de ejecucion
*/
void Usage(int argc, char* argv[]) {
  switch (argc) {
    case 2: {
      std::string parametro = argv[1];
      if (parametro == "--help") {
        std::cout << "El programa se encarga de gestionar las calificaciones obtenidas por diferentes alumnos. "
                  << "Para poder ejecutarlo, es necesario un fichero .txt que contenga los datos de la siguiente manera:"
                  << std::endl;
        std::cout << "aluXXXXXXXXXX nota" << std::endl;
        std::exit(EXIT_SUCCESS);
      }
      break;
    }
    default: {
      std::cerr << argv[0] << ": Modo de empleo: ./p01_single_grades grades.txt" << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para obtener mas informacion" << std::endl;
      std::exit(EXIT_SUCCESS);
    }
  }
}

std::map<std::string, std::set<double>> MultipleGrades(const std::string& nombre) {
  std::ifstream fichero_entrada(nombre);
  if (!fichero_entrada.is_open()) {
    std::cerr << "El fichero de entrada no se ha podido abrir" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::string alu;
  double nota;
  std::map<std::string, std::set<double>> listado;

  while (fichero_entrada >> alu >> nota) {
    if (ComprobarDatos(alu, nota)) {
      listado[alu].insert(nota);
    }
  }
  return listado;
}

void Insert(std::map<std::string, std::set<double>>& listado, const std::string& alu, const double nota) {
  if (ComprobarDatos(alu, nota)) {
    listado[alu].insert(nota);
  }
}

bool ComprobarDatos(const std::string& alu, const double nota) {
  if (alu.size() != 13 || alu.substr(0, 3) != "alu") {
    std::cerr << "El alu introducido no es correcto" << std::endl;
    return false;
  }
  for (int i = 3; i < alu.size(); i++) {
    if (!std::isdigit(static_cast<unsigned char>(alu[i]))) {
      std::cerr << "El alu introducido no es correcto" << std::endl;
      return false;
    }
  }
  if (nota < 0 || nota > 10) {
    std::cerr << "La nota introducida es menor a 0 o mayor a 10" << std::endl;
    return false;
  }

  return true;
}

void PrintMap(const std::map<std::string, std::set<double>>& listado) {
  for (const auto& [alumno, notas] : listado) {
    std::cout << alumno << " ";
    for(auto nota : notas) {
      std::cout << nota << " ";
    }
    std::cout << std::endl;
  }
}