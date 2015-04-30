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
	TABBCalendario a;
	  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(1, 1,2000,(char *)"fecha1"), c3(3, 3,2000,(char *)"fecha");

	  if(a.Insertar(c1))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;

	  if(a.Insertar(c2))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;

	  if(a.Insertar(c3))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl<< endl;


	  cout << "Calendario raiz: " << a.Raiz()<< endl<< endl;


	  if(a.Insertar(c2))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;


	  TABBCalendario b(a);
	  TABBCalendario c;
	  c=a;
	  TCalendario c4(27,2,1989,(char *)"holis");
	  TCalendario c5(21,5,1990,(char *)"jijiji");

	  if(b.Insertar(c4))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;
	  if(b.Insertar(c2))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;

	  if(c.Insertar(c4))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;
	  if(c.Insertar(c2))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;
	  if(c.Insertar(c5))
		  cout << "INSERTADO"<< endl;
	  else
		  cout << "NO INSERTADO"<< endl;



	   return 0;
}



