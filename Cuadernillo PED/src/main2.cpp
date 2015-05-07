/*
 * main2.cpp
 *
 *  Created on: 14/04/2015
 *      Author: eps
 */
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include "tabbcalendario.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	TCalendario a(10,10,2006, (char*) "mensaje 1");
	  TCalendario b(11,10,2006, (char*) "mensaje 2");
	  TCalendario c(12,10,2006, (char*) "mensaje 3");
	  TCalendario d(14,10,2006, (char*) "mensaje 4");
	  TCalendario e(13,10,2006, (char*) "mensaje 5");
	  TCalendario f(15,10,2006, (char*) "mensaje 6");
	  TCalendario g(16,10,2006, (char*) "mensaje 7");
	  TCalendario h(17,10,2006, (char*) "mensaje 8");
	  TCalendario i(18,10,2006, (char*) "mensaje 9");
	  TCalendario j(19,10,2006, (char*) "mensaje 10");
	  TCalendario k(20,10,2006, (char*) "mensaje 11");
	  TCalendario l(21,10,2006, (char*) "mensaje 12");


	  TListaCalendario lista;
	  TListaCalendario lista2;
	  TListaCalendario lista3;
	  TListaCalendario lista4;

	  lista.Insertar(a);
	  lista.Insertar(b);
	  lista.Insertar(c);
	  lista.Insertar(d);
	  lista.Insertar(e);

	  lista2.Insertar(f);
	  lista2.Insertar(g);
	  lista2.Insertar(h);
	  lista2.Insertar(i);
	  lista2.Insertar(j);
	  //lista4=lista2;
	  //lista3=lista.SumarSubl(4,2,lista2,0,1);
	  lista2.Borrar(h);

	  TListaCalendario lista5(lista2);


	  cout<<lista<<endl;
	  cout<<lista2<<endl;
	  cout<<lista3<<endl;
	  cout<<lista4<<endl;
	  cout<<lista5<<endl;

	  if(lista2==lista4)
		  cout << "lista2 es igual a lista4" << endl;
	  else
		  cout << "lista2 NO es igual a lista4" << endl;

	  if(lista2==lista5)
	  		  cout << "lista2 es igual a lista5" << endl;
	  	  else
	  		  cout << "lista2 NO es igual a lista5" << endl;

	  if(lista3==lista4)
	  		  cout << "lista3 es igual a lista4" << endl;
	  	  else
	  		  cout << "lista3 NO es igual a lista4" << endl;

	   return 0;
}



