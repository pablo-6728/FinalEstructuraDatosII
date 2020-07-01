//
//  main.cpp
//  Proyecto Final Estructuras I
//
//  Created by iMac on 6/29/20.
//  Copyright © 2020 iMac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <queue>

using namespace std;

#define SIZE 6

int menu;

//clase para la cola
class cola{
    int *arr; //arreglo para almacenar la informacion
    int capacidad; //capacidad de la cola
    int frente;
    int rear;
    int count; //tamano actual de la cola
    
public:
    cola(int size = SIZE); //constructor
    ~cola(); //deconstructor
    
    void dequeue();
    void enqueue(int x);
    void mostrar();
    int peek();
    int size();
    bool vacia();
    bool llena();
    
};

cola :: cola(int size){  //constructor que inicializa la cola
    arr = new int[SIZE];
    capacidad = size;
    frente = 0;
    rear = -1;
    count = 0;
    
}

cola :: ~cola(){  //deconstructor que libera la memoria
    delete arr;
}

//funcion para quitar un elemetno de la cola
void cola::dequeue(){
    
    //revisar para subdesbordamiento
    if (vacia()) {
        cout<<"\nSubdesbordamiento\nCierre del Programa\n";
        exit(EXIT_FAILURE);
    }
    
    cout<<"\nQuitando "<< arr[frente]<<"\n";
    frente = (frente + 1)%capacidad;
    count--;

}

//funcion para agregar un elemento en la cola
void cola::enqueue(int item){
    
    //verificar desbordamiento
    if (llena()) {
        cout<<"Desbordamiento\nCierre del Programa\n";
        exit(EXIT_FAILURE);
    }
    
    cout<<"\nInsertando "<< item <<"\n";
    
    rear = (rear + 1)%capacidad;
    arr[rear] = item;
    count++;
    
}


//funcion que muestra el ultimo elemento de la cola
int cola::peek(){
    
    if (vacia()){
            cout << "\nSobredesbordamiento\nCierre del Programa\n";
            exit(EXIT_FAILURE);
        }
        return arr[frente];
}

//funcion que regresa el tamano de la cola
int cola::size(){
    return count;
}

//funcion que revisa si la cola esta vacia
bool cola::vacia(){
    return (size()==0);
}

bool cola::llena(){
    return (size()== capacidad);
}


void hoja_presentacion(){
    std::cout<< "\n\nUniversidad Tecnologica de Panama\nCurso:Estructura de Datos I\nAlumnos: Pablo Paladino, Michael Xia\n";
}

//clase para crear nodos
class Nodo{
    public:
    int dat, aux;
    Nodo* sig;
    
    Nodo* insertar (Nodo* val, int d){
        Nodo* nuevo = new Nodo;
        nuevo-> dat=d;
        nuevo->sig=val;
        val=nuevo;
        return val;
    }
    
    Nodo* eliminar(Nodo* val, int d){
        Nodo* nuevo = new Nodo;
        nuevo=val;
        val=nuevo->sig;
        d=nuevo->dat;
        return val;
    }
    
void mostrareli(Nodo* val){     //mostrar elemento de la pila
    Nodo* aux;
    aux=val;
    cout<<aux->dat;
    aux=aux->sig;}
    
void mostrar(Nodo* val){
    Nodo* aux;
    aux=val;
    while(aux!=NULL){
        cout<<aux->dat<<endl;
        aux=aux->sig;
    }
}
};

void operaciones_pila(){
    int menu;
    int x=0,z;
    int pila;
Nodo* val=NULL;
 Nodo* d;
   
    do {
        cout<<"\n\nOperaciones con Pila\n[1]Insertar en la pila\n[2]Eliminar de la pila\n[3]Mostrar la Pila\n[4]Volver al Menu Principal\n";
        cin>>menu;
        
        if (menu == 1) {
            cout<< "\nIntoduzca el elemento que desea en pila\n";
            cin>>pila;
        val=d->insertar(val,pila);
            
        }else if (menu == 2) {
                if (val==NULL) {
        cout<<"\nLa Pila esta vacia\nCierre del Programa\n";
        exit(EXIT_FAILURE);
    }
    else{
   
   cout<<"\nSe quito ";
   d->mostrareli(val);
   val=d->eliminar(val,pila);
   
    }
               
            }
      else if(menu == 3){
 cout<<"\n Los numeros en su pila son: \n";
   d->mostrar(val);
            
        } }while (menu!=4);}

void operaciones_cola(){
    int menu;
    int input;
    int i = 0;
    int j = 0;
    int arreglo[5]; //arreglo en el que se va guardar la cola
    cola q(5);
    
    cout<<"\nLa cola solo acepta 5 elementos\n";
   
    do {
        cout<<"\n\nOperaciones con Cola\n[1]Insertar en la cola\n[2]Eliminar de la cola\n[3]Mostrar la Cola (se borraran los elementos y se volverán a insertar)\n[4]Volver al Menu Principal\n";
        cin>>menu;
        
        if (menu == 1) {        //encolar
            cout<< "\nIntoduzca el elemento que desea encolar\n";
            cin>>input;
            
            cout<<"\nPuedes encolar "<<4-i<< " veces mas\n";
            
            arreglo[i] = input; //se coloca el input en el arreglo
            q.enqueue(input);   //se coloca el input en la cola
            i++;
            
        }else{
            
            if (menu == 2) {        //desencolar
                cout<< "\nDesencolando...\n";
                
                arreglo[j] = 0;
                q.dequeue();
                j++;
            }
            
            if (menu == 3) {
                
                cout<<"\nLa Cola es: \n";
                
                for (j = 0; j<i; j++) { //mostrar cola
                    q.dequeue();
                }
                
                for (j = 0; j<i; j++) {
                    
                    q.enqueue(arreglo[j]);  //encolar todo de una sola vez
                }
                
                
            }
            
        }
            
    } while (menu!=4);
    
}


int main()
{
    do{
        std::cout<< "Operaciones con Estructuras de datos lineales\n\n[1] Hoja de Presentacion\n[2]Operaciones con Pila\n[3]Operaciones con Cola\n[4]Salir\n";
        
        std::cin >> menu;
        
        if (menu == 1) {
            hoja_presentacion();
        }else{
            
            if (menu == 2) {
                operaciones_pila();
            }
            
            if (menu == 3) {
                operaciones_cola();
            }
        }
        
    }while (menu!=4);
        
}

