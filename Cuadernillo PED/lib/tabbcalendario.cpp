/*
 * tabbcalendario.cpp
 *
 *  Created on: 29/04/2015
 *      Author: hmb6
 */

#include "tabbcalendario.h"


/////////////////////////////////TNodoABB//////////////////////////////////////////////
TNodoABB::TNodoABB():iz(),de()
{
	item=TCalendario();
}

TNodoABB::TNodoABB(const TNodoABB &n)
{
	item=n.item;
	iz=n.iz;
	de=n.de;
}

TNodoABB::~TNodoABB()
{
	item=TCalendario();
}

TNodoABB &
TNodoABB::operator=(const TNodoABB &n)
{
	this->~TNodoABB();
	item=n.item;
	iz=n.iz;
	de=n.de;
	return *this;
}

////////////////////////////////TABBCalendario/////////////////////////////////////
TABBCalendario::TABBCalendario()
{
	raiz=NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &a)
{
	Copiar(a);
}

TABBCalendario::~TABBCalendario()
{
	if(raiz!=NULL)
		delete raiz;
	raiz=NULL;
}

TABBCalendario &
TABBCalendario::operator=(const TABBCalendario &a)
{
	this->~TABBCalendario();
	Copiar(a);
	return *this;
}

bool
TABBCalendario::Insertar(const TCalendario &c)
{
	Enraizar(raiz->iz,c,raiz->de);
}

void
TABBCalendario::Enraizar(TABBCalendario &iz, const TCalendario c, TABBCalendario &de){
	TNodoABB *aux = new TNodoABB( );
	aux->item = c;
	(aux->iz).raiz = iz.raiz;
	(aux->de).raiz = de.raiz;
	iz.raiz = de.raiz = NULL;
	this->~TABBCalendario();
	raiz=aux;
}



void
TABBCalendario::Copiar(const TABBCalendario &origen)
{
	if(origen.raiz !=NULL)
	{
		TNodoABB *aux = new TNodoABB();
		aux->item = origen.raiz->item;
		raiz = aux;
		raiz->iz.Copiar(origen.raiz->iz);
		raiz->de.Copiar(origen.raiz->de);
	}
	else
		raiz=NULL;
}
