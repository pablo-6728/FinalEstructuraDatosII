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
    
    cout<<"Insertando "<< item <<"\n";
    
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
    std::cout<< "\n\nUniversidad Tecnologica de Panama\nCurso:Estructura de Datos I\nAlumnos: Pablo Paladino, Michael ";
}

void operaciones_cola(){
    int menu;
    int input;
    cola q(5);
    
    cout<<"\nLa cola solo acepta 5 elementos\n";
   
    do {
        cout<<"\n\nOperaciones con Cola\n[1]Insertar en la cola\n[2]Eliminar de la cola\n[3]Mostrar la Pila\n[4]Volver al Menu Principal\n";
        cin>>menu;
        
        if (menu == 1) {        //encolar
            cout<< "\nIntoduzca el elemento que desea encolar\n";
            cin>>input;
            q.enqueue(input);
            
        }else{
            
            if (menu == 2) {        //desencolar
                cout<< "\nDesencolando...\n";
                q.dequeue();
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
            
            if (menu == 3) {
                operaciones_cola();
            }
        }
        
    }while (menu!=4);
        
    
}

