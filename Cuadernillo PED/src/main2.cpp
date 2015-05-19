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
#include "tavlcalendario.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	TAVLCalendario a;
	  TCalendario *vectorc;

	  vectorc=new TCalendario[2000];
	  for (int i=0; i<2000; i++)
	  {
	     vectorc[i].ModFecha(1,1,2000+i);
	     a.Insertar(vectorc[i]);
	  }

	  cout<<"Inorden="<<a.Inorden()<<endl;
	  return 0;
}



