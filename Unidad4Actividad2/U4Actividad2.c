/*

U.N.A.M
LICENCIATURA EN INFORMATICA
ESTRUCTURA DE DATOS
CARLOS EDUARDO HOYOS ROJAS

CODIGO ESCRITO EN VISUAL STUDIO CODE
COMPILADO CON GNU (GCC)

UNIDAD 4, ACTIVIDAD 2
Desarrolla en Lenguaje C el programa que ordene de manera 
ascendente y descendente un arreglo de cadenas, con los 
nombres de canciones que a ti te gusten (mínimo 20 canciones). 
Utiliza el algoritmo Quick Sort de manera recursiva. Entregar 
un archivo zip con el código fuente y captura pantallas de las
 ejecuciones del programa. Recuerda poner en los comentarios el 
 algoritmo utilizado.


 */
 #include <stdio.h>
 #include <string.h>



    char const *canciones[] = {
         "Hey Jude",
         "Like a Rolling Stone",
         "Yesterday",
         "Layla",
         "Persiana americana",
         "La celula que explota ",
         "Entre dos tierras",
         "Cuando pase el temblor",
         "Afuera",
         "En la ciudad de la furia ",
         "Light My Fire",
         "Flaca",
         "Let It Be",
         "Partita No.2",
         "All Along the Watchtower",
         "My Girl",
         "Dream On",
         "Strawberry Fields Forever",
        "Roxanne",
         "Imagine"
     };

 int main(){

     printf("\nBienvenido al programa que ordena una lista de 20 canciones:\n");
     printf("\nA continuacion se muestra la lista a ordenar, despues se muestra en orden ascendente y descendente respectivamente:\n\n");
    
     imprimirLista(canciones, sizeof(canciones)/sizeof(*canciones));
    
     quicksort(canciones, sizeof(canciones)/sizeof(*canciones));

     printf("\nORDEN ASCENDENTE:\n");
    imprimirLista(canciones, sizeof(canciones)/sizeof(*canciones));

     

     printf("\nORDEN DESCENDENTE:\n");
     reverseQuicksort(canciones, sizeof(canciones)/sizeof(*canciones));
    imprimirLista(canciones, sizeof(canciones)/sizeof(*canciones));
     
     return 0;
 }

 void imprimirLista(char const *canciones[], unsigned tamano)
{
    unsigned i=0;
    for (;i<tamano;++i)
        puts(canciones[i]);
}

 void cambiar(char const **cancion1, char const **cancion2){
     char temp[50];

     const char *tmp = *cancion1;
    *cancion1 = *cancion2;
    *cancion2 = tmp;
 }

//Algoritmo quick sort para ordenar el arreglo de cadena de caracteres
 void quicksort(char const *canciones[], unsigned int tamano)
{
    unsigned int i, pivote=0;

    if (tamano <= 1)
        return;

    cambiar(canciones+((unsigned int)rand() % tamano), canciones+tamano-1);

    for (i=0;i<tamano-1;++i)
    {
        if (strcmp(canciones[i], canciones[tamano-1]) < 0)
            cambiar(canciones+i, canciones+pivote++);
    }

    cambiar(canciones+pivote, canciones+tamano-1);


    quicksort(canciones, pivote++);
    quicksort(canciones+pivote, tamano - pivote);
}

void reverseQuicksort(char const *canciones[], unsigned int tamano)
{
    unsigned int i, pivote=0;

    if (tamano <= 1)
        return;

 
    cambiar(canciones+((unsigned int)rand() % tamano), canciones+tamano-1);

    
    for (i=0;i<tamano-1;++i)
    {
        if (strcmp(canciones[i], canciones[tamano-1]) > 0)
            cambiar(canciones+i, canciones+pivote++);
    }

    cambiar(canciones+pivote, canciones+tamano-1);

    reverseQuicksort(canciones, pivote++);
    reverseQuicksort(canciones+pivote, tamano - pivote);
}



