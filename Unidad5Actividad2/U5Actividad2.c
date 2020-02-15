/*
U.N.A.M
LICENCIATURA EN INFORMATICA
ESTRUCTURA DE DATOS
CARLOS EDUARDO HOYOS ROJAS

CODIGO ESCRITO EN VISUAL STUDIO CODE
COMPILADO CON GNU (GCC)

UNIDAD 5, ACTIVIDAD 2
Realiza el programa completo para la búsqueda de un elemento,
 con el método de búsqueda en árboles binarios, en donde declares
  un menú para que el usuario inserte elementos y después haga una búsqueda. 
  Recuerda las reglas para insertar elementos mayores o menores al nodo padre.
*/

#include<stdlib.h>
#include<stdio.h>

//estructura para almacenar arbol binario
struct arbolBinario {
int dato;
struct arbolBinario * izq, * der;
};

//estructura para representar un nodo del arbol binario
typedef struct arbolBinario nodo;

//funcion para agregar nodo
void agregar(nodo ** arbol, int val)
{
    nodo *temp = NULL;
    if(!(*arbol))
    {
        temp = (nodo *)malloc(sizeof(nodo));
        temp->izq = temp->der = NULL;
        temp->dato = val;
        *arbol = temp;
        return;
    }

    if(val < (*arbol)->dato)
    {
        agregar(&(*arbol)->izq, val);
    }
    else if(val > (*arbol)->dato)
    {
        agregar(&(*arbol)->der, val);
    }

}

//funcion para imprimir el arbol binario
void imprimir(nodo * arbol)
{
    if (arbol)
    {
        imprimir(arbol->izq);
        printf("%d\n",arbol->dato);
        imprimir(arbol->der);
    }
}

//funcion para encontrar un nodo en el arbol binario
nodo* buscar(nodo ** arbol, int val)
{
    if(!(*arbol))
    {
        return NULL;
    }

    if(val < (*arbol)->dato)
    {
        buscar(&((*arbol)->izq), val);
    }
    else if(val > (*arbol)->dato)
    {
        buscar(&((*arbol)->der), val);
    }
    else if(val == (*arbol)->dato)
    {
        return *arbol;
    }
}

int main()
{
	int opc, elemento;
    nodo *root;
    nodo *tmp;

    root = NULL;

	printf("\n\tBienvenido al programa que almacena un elemento a un arbol binario y realiza una busqueda. \n");

    do{
        //menu
        printf("\nIngrese una de las siguientes opciones: ");
		printf("\n1. Ingresar numero al arbol binario: ");
		printf("\n2. Buscar un elemento:");
		printf("\n3. Imprimir el arbol binario: \n");
		printf("\n4. Salir");
		printf("\nOpcion: ");
		scanf("%d",&opc);
        fflush(stdin);
		
		switch(opc){
			case 1: 
			printf("\n Ingrese el elemento que desea agresar al arbol binario: ");
			scanf("%i", &elemento);
					agregar(&root, elemento);
					    fflush(stdin);
					printf("\nSe ha agregado a el arbol binario el elemento: %d", elemento);
			break;
			case 2:
			printf("\n Ingrese el numero que desea buscar en el arbol binario: ");
			scanf("%i", &elemento);
			    fflush(stdin);
				 tmp = buscar(&root, elemento);
    if (tmp)
    {
        printf("\nEl nodo=%d existe en el arbol binario.\n", tmp->dato);
    }
    else
    {
        printf("\nNo se encontro el elemento en el arbol binario.\n");
    }
			
			break;
			case 3: 
						printf("\n\nElementos del arbol binario:\n");
						printf("\n");
						imprimir(root);
			break;
			case 4: exit(0);break;
            default:
            printf("\nOpcion invalida, por favor ingrese otra opcion.\n");
            break;
		}
	
	}while(opc != 4);
  
    return 0;
}