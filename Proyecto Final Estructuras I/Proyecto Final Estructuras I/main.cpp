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

int menu;

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
        }
        
    }while (menu!=4);
        
    
}

