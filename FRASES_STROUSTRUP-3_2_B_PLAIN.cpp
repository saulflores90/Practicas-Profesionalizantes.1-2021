/*
Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase
en una línea, con Interlineado.
*/
#include <iostream> // libreria de inpuy y output de pantalla
#include <fstream> // libreria de input y output file
#include <string>  // libreria de cadena de texto
using namespace std; // espacio de nombre estandar

int main() // funcion principal
{
    ifstream in;// declaramos que vamos a leer un archivo
    in.open("QuotesOfBjarne.txt");// se declara el archivo a abrir

    //if (!in) throw "Error opening file";
    if (!in)
    {
        cerr << "Error opening file" << endl; // salida de error estandar, solo para c++
        exit(EXIT_FAILURE);
    }

    while (!in.eof())// mientras no encuentre el final del archivo
    {
        string line;  // declara una linea
        getline(in, line); // carga el string
        cout << line << endl; // muestra el texto en pantalla
        cout << endl; // salto de linea
    }

    in.close();//cerramos el archivo

    return 0;// retorna 0
}
