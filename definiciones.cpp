#include "header.h"
using namespace std;

vector <vector <char>> tabla_main;
string tipo_jugador;
string tipo_cpu;
string first;
int n_filas, n_columnas, tamaño_raya;
int fila_pos, columna_pos;

bool condicion(string arg){
  if(arg == "tamaño_raya"){
    return (tamaño_raya < 1);
  }
  else if(arg == "n_filas"){
    return (n_filas < 1);
  }
  else if(arg == "n_columnas"){
    return ((n_filas * n_columnas) < (tamaño_raya * 2) - 1);
  }
  else if(arg == "tipo_jugador"){
    return (!(tipo_jugador == "x" || tipo_jugador == "X" || tipo_jugador == "o" || tipo_jugador == "O"));
  }
  else if(arg == "first"){
    return (!(first == "y" || first == "n"));
  }
  else if(arg == "fila_pos"){
    return (!(fila_pos <= tabla_main.size() && fila_pos > 0));
  }
  else if(arg == "columna_pos"){
    return (!(columna_pos <= tabla_main[0].size() && columna_pos > 0));
  }
  else{
    return false;
  }
}

template<class T> void AskUser(string mensaje_peticion, T& cin_var, string variable, string mensaje_error){
  cout << mensaje_peticion;
  cin >> cin_var;
  while(condicion(variable)){
    while(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "entrada no válida\n" << mensaje_peticion;
      cin >> cin_var;
    }
    if(condicion(variable)){
      cout << mensaje_error << "\n" << mensaje_peticion;
      cin >> cin_var;
    }
  }
}

void Imprimir(){
  bool ultimafila{false};
  for(int i = 0; i < tabla_main.size(); i++){
    cout << " " << tabla_main[i][0];
    for(int j = 1; j < tabla_main[0].size(); j++){
      cout << " | " << tabla_main[i][j];
    }
    if(i == tabla_main.size() - 1){
      ultimafila = true;
    }
    if(!ultimafila){
      cout << endl;
      for(int c = 0; c < tabla_main[0].size() - 1; c++){
        cout << "----";
      }
      cout << "---" << endl;
    }
  }
  cout << endl << endl << endl;
}

void ColocarFicha(int f, int c, char tipo){
  tabla_main[f][c] = tipo;
}

void Preguntar(){
  bool primera_iteracion{true};
  do{
    if(!primera_iteracion){ cout << "casilla ya cogida \n"; }
    primera_iteracion = false;
    AskUser<int>("fila: ", fila_pos, "fila_pos", "fila fuera de rango");
    if(tabla_main[0].size() == 1 && (tabla_main[fila_pos - 1][0] == 'X' || tabla_main[fila_pos - 1][0] == 'O')){
      primera_iteracion = true;
      cout << "fila ya cogida \n";
      continue;
    }
    AskUser<int>("columna: ", columna_pos, "columna_pos", "columna fuera de rango");
  }
  while(tabla_main[fila_pos - 1][columna_pos - 1] == 'X' || tabla_main[fila_pos - 1][columna_pos - 1] == 'O');
  ColocarFicha(fila_pos - 1, columna_pos - 1, tipo_jugador[0]);
}

void ColocarCPU(){
  srand(time(NULL));
  int fila_cpu = rand() % (tabla_main.size());
  int columna_cpu = rand() % (tabla_main[0].size());
  while(tabla_main[fila_cpu][columna_cpu] != ' '){
    fila_cpu = rand() % (tabla_main.size());
    columna_cpu = rand() % (tabla_main[0].size());
  }
  ColocarFicha(fila_cpu, columna_cpu, tipo_cpu[0]);
}

bool Comprobar(){
  bool resultado;
  bool tabla_llena{true};
  for(int i = 0; i < tabla_main.size(); i++){
    for(int j = 0; j < tabla_main[0].size(); j++){
      if(tabla_main[i][j] == ' '){
        tabla_llena = false;
        continue;
      }
      if(i + 1 <= static_cast<int>(tabla_main.size() - (tamaño_raya - 1))){
        for(int suma = 1; suma < tamaño_raya; suma++){
          if((tabla_main[i][j] == tabla_main[i + suma][j])) resultado = true;
          else{
            resultado = false;
            break;
          }
        }
        if(resultado) return resultado;
      }

      if(j + 1 <= static_cast<int>(tabla_main[0].size() - (tamaño_raya - 1))){
        for(int suma = 1; suma <= (tamaño_raya - 1); suma++){
          if((tabla_main[i][j] == tabla_main[i][j + suma])) resultado = true;
          else{
            resultado = false;
            break;
          }
        }
        if(resultado) return resultado;
      }

      if(i + 1 <= static_cast<int>(tabla_main.size() - (tamaño_raya - 1)) 
         && j + 1 <= static_cast<int>(tabla_main[0].size() - (tamaño_raya - 1))){
        for(int suma = 1; suma <= (tamaño_raya - 1); suma++){
          if((tabla_main[i][j] == tabla_main[i + suma][j + suma])) resultado = true;
          else{
            resultado = false;
            break;
          }
        }
        if(resultado) return resultado;
      }

      if(i + 1 <= static_cast<int>(tabla_main.size() - (tamaño_raya - 1))
         && j + 1 >= tamaño_raya){
        for(int suma = 1; suma < tamaño_raya; suma++){
          if((tabla_main[i][j] == tabla_main[i + suma][j - suma])) resultado = true;
          else{
            resultado = false;
            break;
          }
        }
        if(resultado) return resultado;
      }
    }
  }
  if(tabla_llena) return true;
  return false;
}

void clear(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

template void AskUser<int>(string mensaje_peticion, int& cin_var, string variable, string mensaje_error);
template void AskUser<string>(string mensaje_peticion, string& cin_var, string variable, string mensaje_error);