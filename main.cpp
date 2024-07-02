/*ERRORES:
  -al terminar poner si has ganau perdiu o empatau
  -hacer funcionar la funcion condicion con direcciones y no strings
  -Crear tests a saco

  -Implementar el minimax
*/

#include "header.h"
using namespace std;

int main(){
  clear();
  setlocale(LC_ALL, "es_ES");
  AskUser<int>("tamaño de la raya: ", tamaño_raya, "tamaño_raya", "mínimo raya de 2");
  AskUser<int>("número de filas: ", n_filas, "n_filas", "fuera de rango");
  AskUser<int>("número de columnas: ", n_columnas, "n_columnas", "fuera de rango");
  AskUser<string>("juegas con X o O?: ", tipo_jugador, "tipo_jugador", "tipo no válido");

  if(tipo_jugador == "x"){ tipo_jugador = "X"; }
  if(tipo_jugador == "o"){ tipo_jugador = "O"; }

  if(tipo_jugador == "X"){ tipo_cpu = "O"; }
  else{ tipo_cpu = "X"; }

  tabla_main.assign(n_filas, vector<char> (n_columnas, ' '));
  AskUser<string>("juegas el primer turno?(y/n)", first, "first", "entrada no válida");
  if(first == "n"){
    ColocarCPU();
    Imprimir();
  }

  while(!(Comprobar())){
    Preguntar();
    clear();
    Imprimir();
    if(!(Comprobar())){
      ColocarCPU();
      Imprimir();
    }
    else{
      break;
    }
  }
  cout << "Fin del juego" << endl;
  getch();
}