/*
U.N.A.M
LICENCIATURA EN INFORMATICA
ESTRUCTURA DE DATOS
CARLOS EDUARDO HOYOS ROJAS

CODIGO ESCRITO EN VISUAL STUDIO CODE
COMPILADO CON GNU (GCC)

UNIDAD 3, ACTIVIDAD 2
Desarrolla en lenguaje C el programa de un grafo que almacene los estados de la República
Mexicana y sus estados vecinos; es decir, el programa debe imprimir el nombre de todos los
estados y una lista de los estados vecinos para cada estado en particular. El grafo puede
representarse a través de una matriz o una lista ligada. Recuerda utilizar por lo menos las
operaciones de Init(), addNodo(), addEdge().
Ejemplo:
• Ciudad de México
- Estado de México
- Morelos
• Morelos
- Ciudad de México
- Estado de México
- Guerrero
- Puebla
Entregar un archivo zip con el código fuente y la captura de pantallas de la ejecución del
programa.
 */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define MAX 50

struct AdjListNode 
{ 
    int dest; 
    char estado[MAX];
    struct AdjListNode* next;
     
}; 
  

struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  

struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  

struct AdjListNode* newAdjListNode(int dest, char estado[MAX]) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest;
    strcpy(newNode->estado, estado );
    newNode->next = NULL; 
    return newNode; 
} 
  
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 

    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  

void addEdge(struct Graph* graph, int src, int dest,char estadoOriginario[], char estadoVecino[]) 
{ 

    struct AdjListNode* newNode = newAdjListNode(dest, estadoVecino); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  

    newNode = newAdjListNode(src, estadoOriginario); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
  

void printGraph(struct Graph* graph) 
{ 
    int v;

   
  
    
   
    for (v = 0; v < graph->V; ++v) 
    { 

         
        struct AdjListNode* pCrawl = graph->array[v].head; 

         printf("%d", v);
   
       
        while (pCrawl) 
        { 
             printf("\t\t\t\t -> %s\n", pCrawl->estado );
            pCrawl = pCrawl->next; 
        } 
        printf("\n\n"); 
    } 

} 

int main() 
{ 

    int V = 32; 
    struct Graph* graph = createGraph(V); 


    

    addEdge(graph, 0, 2,  "Baja California", "Sonora"); 
 
    addEdge(graph, 2, 1,  "Sonora", "Sinaloa");
    addEdge(graph, 2, 3,  "Sonora", "Chihuahua");

  

    addEdge(graph, 3, 4,  "Chihuahua", "Coahuila");
    addEdge(graph, 3, 5,  "Chihuahua", "Durango)");
    addEdge(graph, 3, 1,  "Chihuahua", "Sinaloa)");

    addEdge(graph, 4, 6,  "Coahuila", "Nuevo Leon");
    addEdge(graph, 4, 7,  "Coahuila", "Zacatecas");

    addEdge(graph, 5, 7,  "Durango", "Zacatecas");
    addEdge(graph, 5, 9,  "Durango", "Nayarit");
    addEdge(graph, 5, 11,  "Durango", "Jalisco");
    addEdge(graph, 5, 1,  "Durango", "Sinaloa");
    
    addEdge(graph, 6, 8,  "Nuevo Leon", "Tamaulipas");
    addEdge(graph, 6, 10,  "Nuevo Leon", "San Luis Potosi");


    addEdge(graph, 7, 10,  "Zacatecas", "San Luis Potosi");
    addEdge(graph, 7, 12,  "Zacatecas", "Aguascalientes");

    addEdge(graph, 8, 10,  "Tamaulipas", "San Luis Potosi");
    addEdge(graph, 8, 16,  "Tamaulipas", "Veracruz");

    addEdge(graph, 9, 1,  "Nayarit", "Sinaloa");
    addEdge(graph, 9, 11,  "Nayarit", "Jalisco");

    addEdge(graph, 10, 4,  "San Luis Potosi", "Coahuila");
    addEdge(graph, 10, 13,  "San Luis Potosi", "Guanajuato");
    addEdge(graph, 10, 14,  "San Luis Potosi", "Queretaro");
    addEdge(graph, 10, 16,  "San Luis Potosi", "Veracruz");

        addEdge(graph, 11, 18,  "Jalisco", "Colima");
    addEdge(graph, 11, 17,  "Jalisco", "Michoacan");
    addEdge(graph, 11, 13,  "Jalisco", "Guanajuato");

    addEdge(graph, 12, 13,  "Aguascalientes", "Guanajuato");
 
    addEdge(graph, 13, 17,  "Guanajuato", "Michoacan");
    addEdge(graph, 13, 14,  "Guanajuato", "Queretaro");

    addEdge(graph, 14, 15,  "Queretaro", "Hidalgo");
    addEdge(graph, 14, 17,  "Queretaro", "Michoacan");

    addEdge(graph, 15, 16,  "Hidalgo", "Veracruz");
    addEdge(graph, 15, 16,  "Hidalgo", "Puebla");
    

    addEdge(graph, 16, 22,  "Veracruz", "Puebla");
    addEdge(graph, 16, 22,  "Veracruz", "Oaxaca");
    addEdge(graph, 16, 25,  "Veracruz", "Tabasco");
    addEdge(graph, 16, 27,  "Veracruz", "Chiapas");

        addEdge(graph, 17, 23,  "Michoacan", "Guerrero");
    addEdge(graph, 17, 19,  "Michoacan", "Edo. de Mexico");
     addEdge(graph, 15, 18,  "Michoacan", "Colima");

    addEdge(graph, 19, 24,  "Edo. de Mexico", "Morelos");
    addEdge(graph, 19, 20,  "Edo. de Mexico", "CDMX");
    addEdge(graph, 19, 20,  "Edo. de Mexico", "Puebla");

    addEdge(graph, 20, 24,  "CDMX", "Morelos");
  

    addEdge(graph, 21, 22,  "Tlaxcala", "Puebla");
       addEdge(graph, 21, 16,  "Tlaxcala", "Hidalgo");


    addEdge(graph, 22, 25,  "Puebla", "Oaxaca");
    addEdge(graph, 22, 23,  "Puebla", "Guerrero");

        addEdge(graph, 23, 25,  "Guerrero", "Oaxaca");
  

    addEdge(graph, 24, 25,  "Morelos", "Oaxaca");
    addEdge(graph, 24, 22,  "Morelos", "Puebla");

    addEdge(graph, 25, 27,  "Oaxaca", "Chiapas");
 

    addEdge(graph, 26, 28,  "Tabasco", "Campeche");
    addEdge(graph, 26, 27,  "Tabasco", "Chiapas");

 

    addEdge(graph, 28, 30,  "Campeche", "Yucatan");
    addEdge(graph, 28, 29,  "Campeche", "Qintana Roo");

     addEdge(graph, 29, 30,  "Quintana Roo", "Yucatan");


       addEdge(graph, 31, 0,  "Baja California Sur", "Baja California");
 

    printGraph(graph); 
  
    return 0; 
} 
