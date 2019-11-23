/*
U.N.A.M
LICENCIATURA EN INFORMATICA
ESTRUCTURA DE DATOS
CARLOS EDUARDO HOYOS ROJAS
UNIDAD 2 ACTIVIDAD 1
Desarrolla en Lenguaje C el programa de una pila utilizando un arreglo, 
recuerda incluir por lo menos las operaciones push() y pop(), así como otras 
operaciones que sean necesarias. Para esta actividad, elige 4
nombres propios de personas pues la pila los almacenará. 
El programa principal realizará las siguientes operaciones:
1. Extraer un nombre
2. Insertar 4 nombres
3. Extraer 2 nombres
4. Extraer 3 nombres

CODIGO ESCRITO EN VISUAL STUDIO CODE
COMPILADO CON GNU (GCC)
*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 25

char nombre[MAX][MAX];
int cima = -1;
char x[MAX];

int pilaVacia();
int pilaLlena();
void push();
int pop();
void verPila();
void menu();

int main(){

    menu();
    system("pause");
    return 0;
}

void menu(){
    int opc;

    do{

        printf("\n\nBienvenido al programa que agrega nombres propios a una pila.");
        printf("\n Por favor ingrese una opcion:");
        printf("\n 1. Extraer un nombre de la pila.");
        printf("\n 2. Insertar cuatro nombres.");
        printf("\n 3. Extraer 2 nombres de la pila.");
        printf("\n 4. Extraer 3 nombres de la pila.\n");
        printf("\n 5. Ver todos los elementos de la pila.");
        printf("\n 6. Salir.\n");
        scanf("%d",&opc);
        fflush(stdout);
    switch (opc) {
         fflush(stdout);
        case 1:
            pop();
             fflush(stdout);
            break;
        case 2:
            push();
            push();
            push();
            push();
             fflush(stdout);
            break;
        case 3:
            pop();
            pop();
             fflush(stdout);
            break;
        case 4:
            pop();
            pop();
            pop();
             fflush(stdout);
            break;
         case 5:
            verPila();
             fflush(stdout);
            break;
        case 6:
            
            break;
        default:
            printf("\nOpcion invalida, por favor ingrese otra opcion.\n");
            break;
        }
    }while(opc!=6);

}

int pilaLlena(){
    if((cima == MAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilaVacia()
{
    if((cima == -1))
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push()
{
    if(pilaLlena())
    {
        printf("\nNo se pueden agregar mas elementos, la pila esta llena.\n");
    }
    else{
        printf("\nIngresa un elemento para agregar a la pila: \n");
        scanf("%s", x);
         fflush(stdout);
         printf("\nSe ha ingresado a la pila el siguiente elemento: %s\n", x);
        cima++;
        strcpy(nombre[cima], x);
    }
}

int pop(){
    if(pilaVacia())
    {
        printf("\nLa pila esta vacia\n");
        
    }
    else{
        strcpy(x,nombre[cima]);
        printf("\nSe ha eliminado de la pila el siguiente elemento: %s\n", x);
        cima--;
    }
}

void verPila(){
    
        if(pilaVacia())
        {
            printf("\nNo hay elementos en la pila.\n");
        
        }
        else{
            int i;
            printf("\n\n Los elementos de la pila son los siguientes: \n");
            for(i=0;i<cima+1;i++)
            {
                printf("%s \n", nombre[i]);
            }
        }
    }
