// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero 
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo cliente.cc: contiene la funcion main del programa

#include <iostream>
#include <fstream>
#include <string>

#include "tools.h"



int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string nombre_fichero = argv[1];
  std::map<std::string, std::vector<double>> listado = MultipleGrades(nombre_fichero);
  PrintMap(listado);
  int opcion; 
  std::cout << "¿Desea introducir mas alumnos? 1 = SI/2 = NO: " << std::endl;
  std::cin >> opcion; 
  if(opcion == 1) {
    std::string alu; 
    double nota;
    std::cout << "Introduzca 'fin' para finalizar" << std::endl;
    while (true) {
      std::cout << "Introduzca alu y nota: ";
      std::cin >> alu;
      if (alu == "fin" || alu == "FIN") {
        break;
      }
      std::cin >> nota;
      std::cout << std::endl;
      Insert(listado, alu, nota);
      PrintMap(listado);
      std::cout << std::endl;
    }
  } else if(opcion == 2) {
    return 0; 
  } else {
    std::cerr << "Opcion incorrecta" << std::endl;
    return 1;
  }
  return 0;
}