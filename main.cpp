/* Desarrolle un programa que permita leer el orden de una matriz y realice lo sggte"
 * 1. Crear dos matrices con valores aleatorios entre 0 1 y
 * 2. imprimir ambas matrices
 * 3. crear una tercera matriz, en donde en cada casillero figure 1 si los valores
 * correspondientes a la misma posicion en m1 y en m2 son diferentes y 0 si son iguales.
 *  00 0
 *  01 1
 *  10 1
 *  11 0
 */


#include <iostream>
#include <iomanip>
using namespace std;

unsigned int ** DimensionaMatriz(unsigned int filas, unsigned int col);
void llenaMatriz(unsigned int ** matriz,unsigned int filas,unsigned int col);
void imprimeMatriz( unsigned int ** matriz, unsigned int filas, unsigned int col);
void guerradeMatrices(unsigned int **m1,unsigned int **m2,unsigned int **mR,
                      unsigned int filas,unsigned int col);
void eliminarMatriz(unsigned int ** &matriz,unsigned int filas,unsigned int col);


int main()
{unsigned int filas, col;
 unsigned int ** m1= nullptr;
 unsigned int ** m2= nullptr;
 unsigned int ** mR= nullptr;

 srand(time(nullptr));
 cout << "Numero de filas : "; cin >> filas;
 cout << "Numero de columnas : "; cin >> col;

 m1 = DimensionaMatriz(filas,col);
 llenaMatriz(m1,filas,col);
 m2 = DimensionaMatriz(filas,col);
 llenaMatriz(m2,filas,col);
 imprimeMatriz(m1,filas,col);
 imprimeMatriz(m2,filas,col);

  mR = DimensionaMatriz(filas,col);
  guerradeMatrices(m1,m2,mR,filas,col);
  imprimeMatriz(mR,filas,col);
  eliminarMatriz(m1,filas,col);
  eliminarMatriz(m2,filas,col);
  eliminarMatriz(mR,filas,col);
  return 0;
}


unsigned int ** DimensionaMatriz(unsigned int filas, unsigned int col)
{
  unsigned int ** nuevaMatriz= nullptr;

  nuevaMatriz = new unsigned int *[filas];
  for(int f=0; f<filas; f++)
    nuevaMatriz[f] = new unsigned int[col];
  return nuevaMatriz;
}

void llenaMatriz(unsigned int ** matriz,unsigned int filas,unsigned int col)
{
  //--- se llena con datos
  for(int f =0; f<filas; f++) {
    for (int c = 0; c < col; c++)
      matriz[f][c] = rand() % 2;
  }
}

void imprimeMatriz( unsigned int ** matriz, unsigned int filas, unsigned int col)
{
  cout << "\n";
  for(int f =0; f<filas; f++)
  {
    for(int c=0; c<col; c++)
      cout << setw(6) << matriz[f][c];
    cout << "\n";
  }

}

void guerradeMatrices(unsigned int **m1,unsigned int **m2,unsigned int **mR,
                      unsigned int filas,unsigned int col)
{
  for(int f =0; f<filas; f++)
    for(int c=0; c<col; c++)
      if (m1[f][c]!=m2[f][c])
        mR[f][c] = 1;
      else
        mR[f][c] = 0;
}

void eliminarMatriz(unsigned int ** &matriz,unsigned int filas,unsigned int col)
{
  for(int f =0; f<filas; f++)
    delete []matriz[f];
  delete []matriz;
  matriz= nullptr;
}