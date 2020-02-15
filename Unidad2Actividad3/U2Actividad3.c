/*
U.N.A.M
LICENCIATURA EN INFORMATICA
ESTRUCTURA DE DATOS
CARLOS EDUARDO HOYOS ROJAS
UNIDAD 2, ACTIVIDAD 3
Desarrolla un programa en Lenguaje C en donde se pueda escoger entre utilizar 
una pila o una cola para almacenar y extraer nombres y que exista una opción 
que permita cambiar el tipo de dato al otro que no haya seleccionado el usuario. 
El menú sería algo como lo siguiente:
1. Inicializar estructura (pila o cola)
2. Insertar dato
3. Extraer dato
4. Cambiar la estructura de datos (de pila a cola o de cola a pila).
5. Imprimir lista

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

int primero = 0;
int ultimo = 0;

int opc;
int eOpc = -1;

int listaVacia();
int pilaLlena();
void push();
int pop();
void verPila();
void menu();

void colaOPila();

int main(){

    menu();
    system("pause");
    return 0;
}

void menu(){


    do{

        printf("\n\nBienvenido al programa que almacena nombres en una pila o una cola.");
        printf("\n Por favor seleccione una opcion:");
        printf("\n 1. Inicializar estructura (Pila o Cola).");
        printf("\n 2. Ingresar nombre.");
        printf("\n 3. Extraer nombre.");
        printf("\n 4. Cambiar la estructura de datos(de pila a cola o de cola a pila).");
        printf("\n 5. Ver todos los elementos de la lista.");
        printf("\n 6. Salir.\n");
        scanf("%d",&opc);
        fflush(stdout);
    switch (opc) {
         fflush(stdout);
        case 1:
            colaOPila();
             fflush(stdout);
            break;
        case 2:
            if(eOpc == 0){
                pushPila();
            }
            if(eOpc == 1){
                pushCola();
            }
            if(eOpc != 0 && eOpc != 1){
            printf("La estructura de datos no ha sido inicializada.");
            }   
             fflush(stdout);
            break;
        case 3:
        if(eOpc == 0){
                popPila();
            }
        if(eOpc == 1){
                popCola();
            }
        if(eOpc != 0 && eOpc != 1){
            printf("La estructura de datos no ha sido inicializada.");
        }    
        
             fflush(stdout);
            break;
        case 4:
            if(eOpc == 0){
                colaOPila();
            }
            if(eOpc == 1){
                colaOPila();
            }
            if(eOpc != 0 && eOpc != 1){
            printf("La estructura de datos no ha sido inicializada.");
            } 
            

             fflush(stdout);
            break;
         case 5:

            if(eOpc == 0){
                verPila();
            }
            if(eOpc == 1){
                verCola();
            }
            if(eOpc != 0 && eOpc != 1){
            printf("La estructura de datos no ha sido inicializada.");
            }   
             fflush(stdout);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nOpcion invalida, por favor ingrese otra opcion.\n");
            break;
        }
    }while(opc!=6);

}

void colaOPila(){
    printf("\nIngrese el numero 0 para inicializar una pila o el numero 1 para inicialzar cola.\n");
    scanf("%d", &eOpc);
     fflush(stdout);
    if(eOpc == 0 ){
        printf("Estructura de datos Pila inicializada.");
    }if(eOpc == 1){
        printf("Estructura de datos Cola inicializada.");
    }
    if(eOpc != 0 && eOpc != 1){
          printf("\n Opcion invalida.\n");
    }
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



int listaVacia()
{
    if((cima == -1))
    {
        return 1;
    }
    else{
        return 0;
    }
}

void pushCola(){
     
        printf("\nIngresa un elemento para agregar a la cola: \n");
        scanf("%s", x);
        fflush(stdout);

        cima++;
        strcpy(nombre[cima], x);

        printf("\nSe ha ingresado a la pila el siguiente elemento: %s\n", x);
       
      
    }

void pushPila()
{
   
        printf("\nIngresa un elemento para agregar a la pila: \n");
        scanf("%s", x);
         fflush(stdout);
        
        cima++;
        strcpy(nombre[cima], x);

        printf("\nSe ha ingresado a la pila el siguiente elemento: %s\n", x);
}

int popCola(){
    if(listaVacia())
    {
        printf("\nLa pila esta vacia\n");
        
    }
    else{
        
        strcpy(x,  nombre[primero]);
        primero++;
        printf("\nSe ha eliminado de la pila el siguiente elemento: %s\n", x);
    }
}

int popPila(){
    if(listaVacia())
    {
        printf("\nLa pila esta vacia\n");
        
    }
    else{
        strcpy(x, nombre[cima]);
        printf("\nSe ha eliminado de la pila el siguiente elemento: %s\n", x);
        cima--;
    }
}

void verPila(){
    
        if(listaVacia())
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

    void verCola(){
    
        if(listaVacia())
        {
            printf("\nNo hay elementos en la pila.\n");
        
        }
        else{
            int i;
            printf("\n\n Los elementos de la cola son los siguientes: \n");
            for(i=cima; i >= 0 ; i--)
            {
                printf("%s \n", nombre[i]);
            }
        }
    }
