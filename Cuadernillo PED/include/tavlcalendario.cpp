/*
 * tavlcalendario.cpp
 *
 *  Created on: 13/05/2015
 *      Author: hmb6
 */

#include "tavlcalendario.h"
#include <queue>

/////////////////////////////////TNodoAVL//////////////////////////////////////////////
TNodoAVL::TNodoAVL():iz(),de()
{
	item=TCalendario();
	fe=0;
}

TNodoAVL::TNodoAVL(TNodoAVL &n)
{
	item=n.item;
	iz=n.iz;
	de=n.de;
	fe=n.fe;
}

TNodoAVL::~TNodoAVL()
{

}

TNodoAVL &
TNodoAVL::operator=(TNodoAVL &)
{

}


