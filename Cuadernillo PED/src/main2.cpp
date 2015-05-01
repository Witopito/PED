/*
 * main2.cpp
 *
 *  Created on: 14/04/2015
 *      Author: eps
 */
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tabbcalendario.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	TABBCalendario a,b,c,d,e;
	  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(20, 2,2000,(char *)"fecha1"), c3(30, 3,2000,(char *)"fecha");
	  TCalendario c4(27,2,1989,(char *)"Holi"), c5(15, 2, 2000,(char *)"fecha");
	  a.Insertar(c2);
	  a.Insertar(c1);
	  a.Insertar(c3);

	  b.Insertar(c2);
	  b.Insertar(c1);
	  b.Insertar(c3);
	  b.Insertar(c4);

	  c.Insertar(c1);
	  c.Insertar(c2);
	  c.Insertar(c3);

	  d.Insertar(c2);
	  d.Insertar(c1);
	  d.Insertar(c3);
	  d.Insertar(c4);
	  d.Insertar(c5);


/*
	  cout << "Nodos de a: " << a.Nodos() << endl;
	  cout << "Nodos de b: " << b.Nodos() << endl;
	  cout << "Nodos de c: " << c.Nodos() << endl;
	  cout << "Nodos de d: " << d.Nodos() << endl;
	  cout << "Nodos de e: " << e.Nodos() << endl;


	  cout << "Nodoshoja de a: " << a.NodosHoja() << endl;
	  cout << "Nodoshoja de b: " << b.NodosHoja() << endl;
	  cout << "Nodoshoja de c: " << c.NodosHoja() << endl;
	  cout << "Nodoshoja de d: " << d.NodosHoja() << endl;
	  cout << "Nodoshoja de e: " << e.NodosHoja() << endl;

*/
	  /*
	  cout << "Altura de a: " << a.Altura() << endl;
	  cout << "Altura de b: " << b.Altura() << endl;
	  cout << "Altura de c: " << c.Altura() << endl;
	  cout << "Altura de d: " << d.Altura() << endl;
	  cout << "Altura de e: " << e.Altura() << endl;
*/
	  /*
	  cout << "Nodos de c: " << c.Nodos() << endl;
	  cout << "Nodoshoja de c: " << c.NodosHoja() << endl;
	 c.Borrar(c2);
	  cout << "Nodos de c: " << c.Nodos() << endl;
	  cout << "Nodoshoja de c: " << c.NodosHoja() << endl;

*/

	  cout << d.Inorden() << endl;





	   return 0;
}



