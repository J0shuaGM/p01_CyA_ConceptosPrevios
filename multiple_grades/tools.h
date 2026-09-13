// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero 
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo tools.h: contiene la diferentes declaraciones de las funciones a usar por el programa


#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>

void Usage(int argc, char *argv[]);
std::map<std::string, std::set<double>> MultipleGrades(const std::string& nombre);
void Insert(std::map<std::string, std::set<double>>& listado, const std::string& alu, const double nota);
bool ComprobarDatos(const std::string& alu, const double nota);
void PrintMap(const std::map<std::string, std::set<double>>& listado);

#endif