/*
Equipo #6:

Victor Matos 1093812
Vicente Vargas 1097813
Darlene Sanz 1097870

*/

#include<iostream>
using namespace std;

/* Un arbol binario tiene variable data, nodo izquierdo y derecho */
struct node
{
string data;
struct node* left;
struct node* right;
};

/* Si variable target esta presente en el arbol, entonces imprime los ancestros
y retorna true, sino retorna false. */
bool printAncestors(struct node *root, string target)
{
/* casos base */
if (root == NULL)
    return false;

if (root->data == target)
    return true;

/* Si variable target esta presente en subarbol izquierdo o derecho de este nodo,
    entonces imprime este nodo */
if ( printAncestors(root->left, target) ||
    printAncestors(root->right, target) )
{
    cout << root->data << " ";
    return true;
}

/* Else retorne falso */
return false;
}

/* Funcion que aloca un nuevo nodo con la
 data ingresada y NULL los punteros de la izquierda y derecha */
struct node* newnode(string data)
{
struct node* node = (struct node*)
                    malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
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
struct node *root = newnode("John"); //1
root->left     = newnode("Bob"); // 2
root->right     = newnode("Erica"); // 3
root->left->left = newnode("Vicente"); // 4
root->left->right = newnode("Elena"); // 5
root->left->left->left = newnode("Bort"); //7

printAncestors(root, "Bort");

getchar();
return 0;
}
