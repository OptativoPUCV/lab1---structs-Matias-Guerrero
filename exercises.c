#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

//ejercicios de punteros y arreglos

/*
Ejercicio 1.
Programe la función void swap(int *a, int *b), la cual
intercambia los valores de las variables apuntadas por a y b.
*/
void swap(int *a, int *b) {
   int temporal = *a;

   *a = *b;
   *b = temporal;
}

/*
Ejercicio 2.
Programe la función void arrayMaxMin(int *a, int n, int *max, int *min),
la cual encuentra el máximo y el mínimo valor del arreglo a y los
almacena en las variables apuntadas por max y min.
*/
void arrayMaxMin(int *a, int n, int *max, int *min) {
   // Inicializamos el max y el min con el primer valor del arreglo.
   *max = a[0];
   *min = a[0];

   // Iteramos el arreglo y comprobamos los numeros.
   for(int i = 1; i < n; i++)
   {
      if(a[i] < *min)
      {
         *min = a[i];
      }

      if(a[i] > *max)
      {
         *max = a[i];
      }
   }
}


/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos ingresados como parámetros y retorna un puntero 
al dato recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona* p = (Persona *) malloc(sizeof(Persona));
   
   //asignar valores de entrada a los campos de p
   strcpy(p->nombre, nombre);
   strcpy(p->rut, rut);
   p->edad = edad;

   return p;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int *datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector* crearVector(int n)
{
   Vector* vector = (Vector *) malloc(sizeof(Vector));

   vector->datos = (int *) calloc(n, sizeof(int));
   vector->capacidad = n;

   return vector;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
   // Se debe verificar que el indice esta dentro del tamaño del vector
   if(i < 0 || i >= v->capacidad)
   {
      printf("Posicion fuera del rango del vector.");
      return;
   }

   // Se asigna el valor a la posicion i del vector
   v->datos[i] = valor;
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i)
{
   // Se debe verificar que el indice esta dentro del tamaño del vector
   if(i < 0 || i >= v->capacidad)
   {
      printf("Posicion fuera del rango del vector.");
      return 0;
   }

   // Retornamos el valor en la posicion i del vector
   return v->datos[i];
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c)
{
   // Se verifica si los vectores tienen el mismo tamaño
   if(a->capacidad != b->capacidad || b->capacidad != c->capacidad)
   {
      printf("Los Vectores no tienen el mismo tamaño, por lo que no se pueden sumar entre ellos.");
      return;
   }

   // Se suman los vectores 'a' y 'b' y se guardan en 'c', con un for que recorre todas las posiciones
   for(int i = 0; i < a->capacidad; i++)
   {
      c->datos[i] = a->datos[i] + b->datos[i];
   }
}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1,b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c)
{
   // Creamos 2 vectores (a y b) con talla 2 con el uso de crearVector()
   Vector* a = crearVector(2);
   Vector* b = crearVector(2);

   // Asignamos los valores correspondientes a los vectores creados con el uso de asignarValor()
   asignarValor(a, 0, a1);
   asignarValor(a, 1, a2);
   asignarValor(b, 0, b1);
   asignarValor(b, 1, b2);

   // Sumamos los vectores "a" y "b" con la funcion sumaV() y la guardamos en el vector "c"
   sumaV(a, b, c);

   // Liberamos la memoria de cada vector que no se utilizara mas
   free(a->datos);
   free(a);
   free(b->datos);
   free(b);
}