/*
 * tlistacalendario.cpp
 *
 *  Created on: 18/04/2015
 *      Author: hector
 */

#include "tlistacalendario.h"

TListaCalendario::TListaCalendario() {
	primero=NULL;
}

TListaCalendario::TListaCalendario(TListaCalendario &l)
{
	TListaPos p,q;

	//PRIMER NODO
	primero=new TNodoCalendario(*l.primero);
	q=l.Primera();
	p=q;
	q=q.Siguiente();

	//A PARTIR DE SEGUNDO NODO
	while(!q.EsVacia())
	{
		TNodoCalendario *aux=new TNodoCalendario();
		aux=q.pos;
		p.pos->siguiente=aux;

		//actualiza p al actual, e incrementa q para el siguiente
		p=q;
		q=q.Siguiente();
	}

	//pone a null ultimo elemento de la lista
	p.pos->siguiente=NULL;
}

TListaCalendario::~TListaCalendario() {
	TListaPos p,q;

	q.pos=primero;
	while(!q.EsVacia())
	{
		p=q;
		q=q.Siguiente();
		delete p.pos;
	}
	primero=NULL;
}

TListaCalendario &
TListaCalendario::operator=(TListaCalendario &l)
{
	return *this;
}

bool
TListaCalendario::operator==(TListaCalendario &l)
{
 return false;
}


TListaPos
TListaCalendario::Ultima() const
{
	TListaPos prim;
	return prim;
}

TListaPos
TListaCalendario::Primera() const
{
	TListaPos prim;
	return prim;
}




///////////////////////////////////////TNODOCALENDARIO//////////////////////////////////////////////////////////////////////

TNodoCalendario::TNodoCalendario()
{
	this->c = TCalendario();
	this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(TNodoCalendario &n)
{
	if(siguiente!=NULL)
	{
		delete siguiente;
	}

	this->c=n.c;
	this->siguiente=n.siguiente;
}

TNodoCalendario::~TNodoCalendario()
{
	this->c=TCalendario();
	this->siguiente=NULL;
}


TNodoCalendario &
TNodoCalendario::operator=(TNodoCalendario &n)
{
		if(siguiente!=NULL)
		{
			delete siguiente;
		}

		this->c=n.c;
		this->siguiente=n.siguiente;

		return *this;
}





////////////////////////////////////////////TListaPos/////////////////////////////////////////////

//forma canonica
TListaPos::TListaPos()
{
	this->pos=new TNodoCalendario();
}


TListaPos::TListaPos(TListaPos &p)
{
	this->pos=p.pos;
}

TListaPos::~TListaPos()
{
	if(pos!=NULL)
	{
		delete pos;
	}
}

TListaPos &
TListaPos::operator=(const TListaPos &p)
{
	pos=p.pos;
	return *this;
}

//metodos
bool
TListaPos::operator==(TListaPos &p)
{
	if(pos==p.pos)
		return true;

	return false;
}

bool
TListaPos::operator!=(TListaPos &p)
{
	if(*this==p)
		return false;

	return true;
}


TListaPos
TListaPos::Siguiente()
{
	TListaPos p;
	p.pos=pos->siguiente;
	return p;
}

bool
TListaPos::EsVacia()
{
	if(pos==NULL)
		return true;
	return false;
}

