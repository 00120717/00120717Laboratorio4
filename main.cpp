/*
Se trabajo en el Codigo base realizado por el grupo de instructores de la materia 
de Tecnicas de Simulacion por computadoras.
Derechos a los respectivos creadores del codigo
 */


#include <iostream>
#include "math_tools.h"
#include "classes.h"
#include "display_tools.h"
#include "tools.h"
#include "sel.h"


int main()
{
    vector<Matrix> localKs;
    vector<Vector> localbs;
    Matrix K;
    Vector b;
    Vector T;

    
    cout<< "TAREA LABO 4: Encontrar los valores para Y(x) y W(x) de las ecuaciones dadas\n";

    mesh m;
    leerMallayCondiciones(m);

    crearSistemasLocales(m,localKs,localbs);
    
    zeroes(K,m.getSize(NODES)*2);
    zeroes(b,m.getSize(NODES)*2);
    ensamblaje(m,localKs,localbs,K,b);
    

    //Solo se aplica Dirichlet, no habra condiciones de Neumann
    applyDirichlet(m,K,b);
    
    showMatrix(K);

    zeroes(T,b.size());

    calculate(K,b,T);

    cout << "La respuesta es: " << endl;
    
    showVector(T);

    return 0;
}