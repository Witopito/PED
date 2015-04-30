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

	  a.Insertar(c1);
	  //a.Insertar(c2);
	  //a.Insertar(c3);

	   return 0;
}



