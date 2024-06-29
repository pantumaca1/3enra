#include "header.h"

void init_cpu_test(){
  if(tipo_jugador == 'X'){ tipo_cpu = 'O'; }
  else{ tipo_cpu = 'X'; }
}
int main(){
  tamaño_raya = 1;
  n_filas = 2;
  n_columnas = 1;
  tipo_jugador = 'X';
  tabla_main.assign(n_filas, std::vector<char> (n_columnas, ' '));
}