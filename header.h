#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits> // errores de cin
#include <cstdlib> //rand, srand
#include <locale> // setlocale
#include <conio.h> // getch
#include <iomanip>
using namespace std;

extern int n_filas, n_columnas, tamaño_raya;
extern string tipo_jugador;
extern string tipo_cpu;
extern string first;
extern vector <vector <char>> tabla_main;

bool condicion(string arg);
template<class T> void AskUser(string mensaje_peticion, T& cin_var, string variable, string mensaje_error);
void Imprimir();
void ColocarFicha(int f, int c, char tipo);
void ColocarCPU();
void Preguntar();
bool Comprobar();

void clear();