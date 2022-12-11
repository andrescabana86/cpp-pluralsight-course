#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int filas = 20, columnas = 6;
void menu();
void imprimirInscriptos();
void imprimirPuntaje(string tabla[filas][columnas]);
void umbralPuntaje(string tabla[filas][columnas]);
void resultadosTxt(string tabla[filas][columnas]);
void matrizCompetidores(string tabla[filas][columnas]);

int main ()
{
    string tabla[filas][columnas]; // creamos la tabla de dos dimensiones
    ifstream myfile ("inscriptos.txt"); // leemos el archivo
    if (myfile.is_open()) // el archivo se leyo correctamente
    {
        int i = 0; // contador de lineas
        string line;
        while (!myfile.eof()) // mientras NO => no sea el final del archivo
        {
            getline(myfile,line); // leemos la linea
            istringstream strLine(line); // linea por palabra
            string palabra;
            int j = 0; // contador de palabras
            while(getline(strLine, palabra, ' ')) // mientras exista una palabra despues de un espacio
            {
                tabla[i][j] = palabra; // guardar palbra
                j++;
            }
            i++;
        }
        myfile.close(); // cerramos el archivo
    }

    int respuesta;
    do
    {
        menu();

        cout << endl;
        cout << "Opcion: ", cin >> respuesta;
        cout << endl;

        switch (respuesta)
        {
            case 1: cout<<"listado de competidores:"<<endl;
                imprimirInscriptos(); // mostrar listado de competidores
                break;
            case 2: cout<<"total de puntos de los competidores:"<<endl;
                imprimirPuntaje(tabla); // mostrar puntajes
                break;
            case 3: cout<<"resultados finales de los competidores:"<<endl;
                resultadosTxt(tabla);
                break;
            case 4: cout<<"competidores que superan el tope de puntos estipulados:"<<endl;
                umbralPuntaje(tabla);
                break;
            case 5: cout<<"cantidad de competidores por categoria y subcategoria:"<<endl;
                matrizCompetidores(tabla);
                break;
            case 6: break;
        }
    }while (respuesta != 6);

    return 0;
}

void menu()
{
    cout<<endl;
    cout<<endl;
    cout<<"================================================================"<<endl;
    cout<<"OPCIONES DEL PROGRAMA"<<endl;
    cout<<"1-Listado de competidores:"<<endl;
    cout<<"2-Total de puntos de los competidores:"<<endl;
    cout<<"3-Resultados finales de los competidores:"<<endl;
    cout<<"4-Competidores que superan el tope de puntos estipulados:"<<endl;
    cout<<"5-Cantidad de competidores por categoria y subcategoria:"<<endl;
    cout<<"6-Salir del sistema."<<endl;
}

void imprimirInscriptos()
{
    string array[21];
    short loop=0;
    string line;
    ifstream myfile ("inscriptos.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            array[loop] = line;
            cout << array[loop] << endl;
            loop++;
        }
        myfile.close();
    }
    else cout << "can't open the file";
}

void imprimirPuntaje(string tabla[filas][columnas])
{
    for (int i=0; i<filas; i++)
    {
        string nombre = tabla[i][1];
        int puntaje = (stoi(tabla[i][4]) * 10) + (stoi(tabla[i][5]) * 5); // string => int, "2" se convierte en 2
        cout << "Jugador: " << nombre << ", total: " << puntaje << endl;
    }
}
void umbralPuntaje(string tabla[filas][columnas])
{
    int umbral;
    do
    {
        cout << endl;
        cout << "Ingrese un numbero mayor a cero (0): ", cin >> umbral;
        cout << endl;
    } while (umbral<= 0);

    int contador = 0;
    for (int i=0; i<filas; i++)
    {
        int puntaje = (stoi(tabla[i][4]) * 10) + (stoi(tabla[i][5]) * 5); // string => int, "2" se convierte en 2
        if (puntaje>umbral)
        {
            contador++;
        }
    }
    cout << "Cantidad de competidores que superan el umbral: "  << contador  << endl;
}

void resultadosTxt(string tabla[filas][columnas])
{
    string tablaTemp[filas][columnas];
    for (int i=0; i<filas; i++)
    {
        for (int j=0; j < columnas; j++)
        {
            tablaTemp[i][j] = tabla[i][j];
        }
    }

    for (int i = 0; i < filas; i++) {
        int bandera = false;
        for (int j = 0; j < (filas - i - 1); j++) {
            string nombre = tablaTemp[j][1];
            int puntaje = (stoi(tablaTemp[j][4]) * 10) + (stoi(tablaTemp[j][5]) * 5);
            int puntajeSiguiente = (stoi(tablaTemp[j+1][4]) * 10) + (stoi(tablaTemp[j+1][5]) * 5);
            if (puntaje > puntajeSiguiente) {
                bandera = true;
                for (int k = 0; k < columnas; k++)
                {
                    string temp = tablaTemp[j][k];
                    tablaTemp[j][k] = tablaTemp[j + 1][k];
                    tablaTemp[j + 1][k] = temp;
                }

            }
        }
        if (bandera == false) {
            break;
        }
    }

    ofstream archivo("resultados.txt");
    for (int i=0; i<filas; i++)
    {
        for (int j=0; j < columnas; j++)
        {
            archivo << tablaTemp[i][j] << " ";
        }
        archivo << endl;
    }
    archivo.close();

    cout<<"================================================================"<<endl;
    cout << "Archivo resultados.txt creado!" << endl;
    cout<<"================================================================"<<endl;
}

void matrizCompetidores(string tabla[filas][columnas])
{
    int categorias[3][3]{0};
    for (int i=0; i<filas; i++)
    {
        int categ = stoi(tabla[i][2]);
        int subcateg = stoi(tabla[i][3]);
        categorias[categ][subcateg] += 1;
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j < 3; j++)
        {
            cout << "Para la categoria " << i << " subcategoria " << j << " el valor es: " << categorias[i][j] << endl;
        }
    }
}
