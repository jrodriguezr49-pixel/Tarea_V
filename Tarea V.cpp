#include <iostream>
using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};


void insertarInicio (Nodo*& tope)
{
    Nodo* Nuevo = new Nodo();

    cout << "Ingrese carne: ";
    cin >> Nuevo->carne;
    cin.ignore();

    cout << "Ingrese nombre: ";
    getline(cin, Nuevo->nombre);

    cout << "Ingrese apellido: ";
    getline(cin, Nuevo->apellido);

    cout << "Ingrese carrera: ";
    getline(cin, Nuevo->carrera);

    Nuevo->siguiente = tope;
    tope = Nuevo;

    cout << "Estudiante agregado al inicio\n";
}


void insertarFinal(Nodo*& tope)
{
    Nodo* Nuevo = new Nodo();

    cout << "Ingrese carne: ";
    cin >> Nuevo->carne;
    cin.ignore();

    cout << "Ingrese nombre: ";
    getline(cin, Nuevo->nombre);

    cout << "Ingrese apellido: ";
    getline(cin, Nuevo->apellido);

    cout << "Ingrese carrera: ";
    getline(cin, Nuevo->carrera);

    Nuevo->siguiente = NULL;

    if (tope == NULL)
    {
        tope = Nuevo;
    }
    else
    {
        Nodo* actual = tope;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = Nuevo;
    }

    cout << "Estudiante agregado al final\n";
}


void mostrar (Nodo* tope)
{
    if (tope == NULL){
        cout << "No hay estudiantes\n";
        return;
    }

    Nodo* actual = tope;

    while (actual != NULL)
    {
        cout << "\nCarne: " << actual->carne << endl;
        cout << "Nombre: " << actual->nombre << endl;
        cout << "Apellido: " << actual->apellido << endl;
        cout << "Carrera: " << actual->carrera << endl;
        cout << "-----------------------------\n";

        actual = actual->siguiente;
    }
}


void buscarElemento (Nodo* tope, int carne)
{
    if (tope == NULL){
        cout << "No hay estudiantes\n";
        return;
    }

    Nodo* actual = tope;
    bool encontrado = false;

    while (actual != NULL)
    {
        if (actual->carne == carne)
        {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << actual->nombre << endl;
            cout << "Apellido: " << actual->apellido << endl;
            cout << "Carrera: " << actual->carrera << endl;

            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
    {
        cout << "Estudiante no encontrado\n";
    }
}

void eliminar(Nodo*& tope, int carne)
{
    if (tope == NULL)
    {
        cout << "No hay estudiantes\n";
        return;
    }

    Nodo* actual = tope;
    Nodo* anterior = NULL;


    if (actual->carne == carne)
    {
        tope = actual->siguiente;
        delete actual;
        cout << "Estudiante eliminado\n";
        return;
    }

    while (actual != NULL && actual->carne != carne)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        cout << "Estudiante no encontrado\n";
        return;
    }

    anterior->siguiente = actual->siguiente;
    delete actual;

    cout << "Estudiante eliminado\n";
}

void vaciarPila(Nodo*& tope)
{
    while (tope != NULL)
    {
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
    cout << "Lista vaciada\n";
}

int main() {

    Nodo* tope = NULL;
    int opcion, valor;

    do {
    	cout << "\nJavier David Rodriguez Rosales/9941-24-71";
    	cout << "\nEste programa fue creado utilizando como base el codigo de la tarea 4 reutilizando partes del codigo";
        cout << "\n1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Vaciar lista\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarInicio(tope);
                break;
            case 2:
                insertarFinal(tope);
                break;
            case 3:
                mostrar(tope);
                break;
            case 4:
                cout << "Carne a buscar: ";
                cin >> valor;
                buscarElemento(tope, valor);
                break;
            case 5:
                cout << "Carne a eliminar: ";
                cin >> valor;
                eliminar(tope, valor);
                break;
            case 6:
                vaciarPila(tope);
                break;
            case 7:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 7);

    return 0;
}