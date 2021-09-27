//Estructura de datos del TDA lista dinÃ¡mica
struct nodo {
    int info;
    struct nodo *sig;
};
typedef struct nodo Nodo;

struct lista {
    Nodo *head;
    int n; //tamaÃ±o de la lista (cantidad de elementos)
};

typedef struct lista Lista;

//PROTOTIPOS o ENCABEZADOS DE LAS FUNCIONES
Lista *crearLista();
void insertarNodoIni(Lista *L, int val);
void insertarNodoFin(Lista *L, int val);
void insertarNodo(Lista *L, int valLis, int valNuevo);
void recorrerLista(Lista *L);
int eliminarNodoIni(Lista *L);
int eliminarNodoFin(Lista *L);
int eliminarNodo(Lista *L, int val);
Nodo *buscarNodo(Lista *L, int val);
Nodo *primero(Lista *L);
Nodo *ultimo(Lista *L);
void destruirLista(Lista *L);