/*
Equipo #6:

Victor Matos 1093812
Vicente Vargas 1097813
Darlene Sanz 1097870

*/

#include<iostream>
using namespace std;

/* Un arbol binario tiene variable data, nodo izquierdo y derecho */
struct nodo
{
string data;
struct nodo* izquierdo;
struct nodo* derecho;
};

/* Si variable target esta presente en el arbol, entonces imprime los ancestros
y retorna true, sino retorna false. */
bool imprimirAncestros(struct nodo *raiz, string target)
{
/* casos base */
if (raiz == NULL)
    return false;

if (raiz->data == target)
    return true;

/* Si variable target esta presente en subarbol izquierdo o derecho de este nodo,
    entonces imprime este nodo */
if ( imprimirAncestros(raiz->izquierdo, target) ||
    imprimirAncestros(raiz->derecho, target) )
{
    cout << raiz->data << " ";
    return true;
}

/* Else retorne falso */
return false;
}

/* Funcion que aloca un nuevo nodo con la
 data ingresada y NULL los punteros de la izquierda y derecha */
struct nodo* nuevonodo(string data)
{
struct nodo* nodo = (struct nodo*)
                    malloc(sizeof(struct nodo));
nodo->data = data;
nodo->izquierdo = NULL;
nodo->derecho = NULL;

return(nodo);
}

int main()
{

/* Referencia de como se ve el arbol genealogico
            John
           /    \
          Bob   Erica
        /     \
    Vicente   Elena
       /
     Bort
*/
struct nodo *raiz = nuevonodo("John"); //1
raiz->izquierdo     = nuevonodo("Bob"); // 2
raiz->derecho     = nuevonodo("Erica"); // 3
raiz->izquierdo->izquierdo = nuevonodo("Vicente"); // 4
raiz->izquierdo->derecho = nuevonodo("Elena"); // 5
raiz->izquierdo->izquierdo->izquierdo = nuevonodo("Bort"); //7

imprimirAncestros(raiz, "Erica");

getchar();
return 0;
}
