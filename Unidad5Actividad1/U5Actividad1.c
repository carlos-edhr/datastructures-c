/*

U.N.A.M
LICENCIATURA EN INFORMATICA
ESTRUCTURA DE DATOS
CARLOS EDUARDO HOYOS ROJAS

CODIGO ESCRITO EN VISUAL STUDIO CODE
COMPILADO CON GNU (GCC)

UNIDAD 5, ACTIVIDAD 1
Realiza el programa completo para la búsqueda de un elemento,
con el método de búsqueda lineal, en donde
declares un menú para que el usuario inserte elementos y después 
haga una búsqueda.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void agregar();
void buscar();
void imprimirArreglo(int arr[], int tamano);
void quicksort(int numeros[], int menor, int mayor);
void cambiar(int* a, int* b);
int particion(int numeros[], int menor, int mayor);
void agregar();
int busquedaLineal(int arrayNumeros[], int elementos, int numero);

int  arrayNumeros[MAX];
int elementos, numero;



int main(){
    int opc;
    
    printf("\n\tBienvenido al programa que almacena un elemento y realiza una busqueda con el metodo lineal. \n");

    do{
        printf("\nIngrese una de las siguientes opciones: ");
		printf("\n1. Ingresar elementos: ");
		printf("\n2. Buscar un elemento:");
		printf("\n3. Imprimir todo el arreglo en orden ascendente:");
		printf("\n4. Salir");
		printf("\nOpcion: ");
		scanf("%d",&opc);
        fflush(stdin);
		
		switch(opc){
			case 1: agregar();break;
			case 2: buscar();break;
			case 3: 
					if(elementos > 0){
						printf("\n\n");
					quicksort(arrayNumeros, 0,  elementos - 1);
						printf("\n\nElementos del arreglo:\n");
					imprimirArreglo(arrayNumeros, elementos);
					printf("\n\n");
					}else{
						printf("\nFavor de ingresar los elementos del arreglo\n\n");
					}
			
			break;
			case 4: exit(0);break;
            default:
            printf("\nOpcion invalida, por favor ingrese otra opcion.\n");
            break;
		}
	
	}while(opc != 4);
  
   
    return 0;

}

void buscar(){
	
	printf("\n Ingrese el numero que desea buscar: \n");
	scanf("%i", &numero);

	int resultado = busquedaLineal(arrayNumeros, elementos, numero);

	if(resultado < 0){
		printf("\nEl numero no se encuentra en el arreglo. \n");
	}if(resultado >= 0){
		printf("\nEl numero existe en el arreglo, ubicado en la posicion: [%d]\n", resultado);
	}

}

int busquedaLineal(int arrayNumeros[], int elementos, int numero){
	int i;
	for(i = 0; i < elementos; i++)
		if(arrayNumeros[i] == numero)
			return i;
	return -1;
}


void imprimirArreglo(int arr[], int tamano){
	int i;
	for(i=0; i < tamano; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void quicksort(int numeros[], int menor, int mayor){
	if(menor < mayor)
	{
		int pivote = particion(numeros, menor, mayor);

		quicksort(numeros, menor, pivote - 1);
		quicksort(numeros, pivote + 1, mayor);

	}
}

void cambiar(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int particion(int numeros[], int menor, int mayor){
	int pivote = numeros[mayor];
	int i = (menor - 1);

	for(int j = menor; j <= mayor - 1; j++)
	{
		if(numeros[j] < pivote)
		{
			i++;
			cambiar(&numeros[i], &numeros[j]);
		}
	}
	cambiar(&numeros[i + 1], &numeros[mayor]);
			return (i + 1);
}


void agregar(){
    int x;
    printf("\n Por favor indique el total de elementos a ingresar(0-100): ");
	scanf("%i",&elementos);
	printf("\n\n");
	for(int i=0; i < elementos; i++){
		printf("[%i].- Ingrese un numero:", i);
		scanf("%i", &arrayNumeros[i]);
		  fflush(stdin);
	}
}

