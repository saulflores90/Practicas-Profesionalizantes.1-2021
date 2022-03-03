/*
Para el Archivo del ejercicio (a) 
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream> //libreria  
#include <fstream> // libreria 
#include <string> // libreria 
using namespace std; // espacio de nombre 

void error(string message, string message2 = "")// se ejecuta solo si detecta error en la apertura del archivo 
{
    cerr << message << ' ' << message2 << endl;// salida estandar de error, muestra los mensajes 
    exit(EXIT_FAILURE);
}

ifstream openFile(string path)
{
    ifstream in; // declara el tipo de archivo lectura
    in.open(path);// abrir el archivo
    bool isCorruptFile = (!in.is_open() || !in.good()); // comprobamos si el archivo esta abierto y el archivo no esta corrupto
    if (isCorruptFile) error("Error opening file");// verifico si hay error, si hay llamo a la funcion void error
    return in; //retorna archivo abierto
}

void closeFile(ifstream& file)
{
    if (file.is_open()) file.close();  
}

int countWords(string sentence) // pasa la oracion sentence para examinarla y contar las palabras
{
    int i = 0; 
    int counter = 1;

    while (i < sentence.length())//cuenta las 
    {
        if (sentence[i] == ' ') // si hay un espacio vacio cuenta una palabra
        {
            counter++; // incrementa el contador
        }
        i++;
    }
    return counter; // retorna valor del contador
}

void showWordsOf(ifstream& file)// paso por referencia el lugar de memoria con el &
{
    int sentecesNumber = 0; 
    int totalWords = 0;
    
    while (!file.eof()) // mientras el archivo no termine voy contando las sentencenumber y total words
    {
        string sentence;   // oracion tipo texto
        getline(file, sentence);// leer linea de oracion
        int wordsPerSentence = countWords(sentence);// palabras por oracion las guarda en contador en formato int wordspersentence
        cout << "La frase número " << sentecesNumber + 1 << " tiene " << wordsPerSentence << " palabras" << endl;

        totalWords += wordsPerSentence; //totalWords = totalWords + wordsPerSentence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;
}

int main()
{
    /*
        IMPORTANTE PRESTAR ATENCIÓN AL PASO POR REFERENCIA
        EN LAS FUNCIONES showQuotesOf y closeFile
        NO SE PUEDE INCIALIZAR UN OBJETO ifstream CON OTRO
        Y LUEGO PASARLO POR VALOR PORQUE ifstream TIENE
        UN CONSTRUCTOR COPIA ELIMINADO, POR ESO NO SE PUEDE COPIAR
    */
    ifstream textFile = openFile("QuotesOfBjarne.txt");  // abro el archivo
    showWordsOf(textFile);// muestra palabras de archivo
    closeFile(textFile); // cerrar el archivo
    return 0;
}