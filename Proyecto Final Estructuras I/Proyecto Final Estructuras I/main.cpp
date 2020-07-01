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
        nuevo-> dat = d;
        nuevo->sig = val;
        val = nuevo;
        return val;
    }
    
    Nodo* eliminar(Nodo* val, int d){
        Nodo* nuevo = new Nodo;
        nuevo = val;
        val = nuevo->sig;
        d = nuevo->dat;
        return val;
    }
    
void mostrareli(Nodo* val){     //mostrar elemento eliminado
    Nodo* aux;
    aux = val;
    cout<<aux->dat;
    aux = aux->sig;}
    
void mostrarPila(Nodo* val){        //mostrar elemento
    Nodo* aux;
    aux = val;
    while(aux!=NULL){
        cout<<aux->dat<<endl;
        aux = aux->sig;
    }
}
    
void mostrarCola(Nodo* val){
    Nodo* aux;
    aux = val;
    while (aux!=NULL) {
        cout<<aux->dat<<endl;
        aux = aux ->sig;
    }
    }
};

void operaciones_pila(){        //operaciones con las pilas
    int menu;
    int x = 0,z;
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
            d->mostrarPila(val);
            
        }
        
    }while (menu!=4);}

void operaciones_cola(){
    int input;
    Nodo* val=NULL;
    Nodo* d;
    
    cout<<"\nLa cola solo acepta 5 elementos\n";
   
    do {
        cout<<"\n\nOperaciones con Cola\n[1]Insertar en la cola\n[2]Eliminar de la cola\n[3]Mostrar la Cola (se borraran los elementos y se volverán a insertar)\n[4]Volver al Menu Principal\n";
        cin>>menu;
        
        if (menu == 1) { //encolar
            cout<<"\nIntroduzca el elemento que desea encolar: ";
            cin>>input;
            val = d -> insertar(val,input);
            cout<<"\n Encolando: "<<input<<" \n";
            
        }else{
            
            if (menu == 2) {        //desencolar
                cout<<"\nIntroduzca el elemento que desea desencolar: ";
                cin>>input;
                val = d -> eliminar(val,input);
                cout<<"\n Desencolando: "<<input<<" \n";
                
            }
            
            if (menu == 3) {    //mostrar la cola
                cout<<"\nSu cola es: ";
                d->mostrarCola(val);
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

