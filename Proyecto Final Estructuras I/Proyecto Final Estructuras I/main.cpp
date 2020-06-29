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



void hoja_presentacion(){
    std::cout<< "\n\nUniversidad Tecnologica de Panama\nCurso:Estructura de Datos I\nAlumnos: Pablo Paladino, Michael ";
}

void operaciones_cola(){
    
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

