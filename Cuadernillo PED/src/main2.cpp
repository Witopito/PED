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
	 TVectorCalendario a(6);
	   TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
	   a[1]=ca1;
	   a[2]=ca2;
	   a[3]=ca3;
	   a[4]=ca1;
	   a[5]=ca2;
	   a[6]=ca3;
	   a.Redimensionar(0);
	   cout<<a<<endl;
	   a.Redimensionar(10);
	   cout<<a<<endl;
	   a.Redimensionar(2);
	   cout<<a<<endl;
	   return 0;
}



