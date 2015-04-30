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
	//item=TCalendario();
}

TNodoABB &
TNodoABB::operator=(const TNodoABB &n)
{
	this->~TNodoABB();
		item=n.item;

		if(n.iz.raiz!=NULL)
			iz=n.iz;
		else
			iz=TABBCalendario();


		if(n.de.raiz!=NULL)
			de=n.de;
		else
			de=TABBCalendario();

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
	if(this->EsVacio())
	{
		TNodoABB *x=new TNodoABB();
		x->item=c;
		raiz=x;
		return true;
	}
	else
	{
		TABBCalendario aux(*this);
		if(!buscaCalendario(c,aux))
		{
			this->insertarOrdenado(c);
			return true;
		}
	}
	return false;
}

void
TABBCalendario::insertarOrdenado(TCalendario c)
{
	if(c<raiz->item)
	{
		if(raiz->iz.EsVacio())
		{
			TNodoABB *x=new TNodoABB();
			x->item=c;
			raiz->iz.raiz=x;
		}
		else
			raiz->iz.insertarOrdenado(c);
	}
	else
	{
		if(raiz->de.EsVacio())
		{
			TNodoABB *x=new TNodoABB();
			x->item=c;
			raiz->de.raiz=x;
		}
		else
			raiz->de.insertarOrdenado(c);
	}

}


TCalendario
TABBCalendario::Raiz()
{
	return raiz->item;
}

bool
TABBCalendario::EsVacio()
{
	if(raiz == NULL)
		return true;
	return false;
}


bool
TABBCalendario::buscaCalendario(const TCalendario &c,TABBCalendario sub)
{
	bool auxiz,auxde;

	if(!sub.EsVacio() && sub.raiz->item == c)
		return true;
	else if(sub.EsVacio())
		return false;
	else if(sub.raiz->de.EsVacio() && sub.raiz->iz.EsVacio())
		return false;
	else if(!sub.raiz->iz.EsVacio() && sub.raiz->de.EsVacio())
		return buscaCalendario(c,sub.raiz->iz);
	else if(!sub.raiz->iz.EsVacio() && sub.raiz->de.EsVacio())
		return buscaCalendario(c,sub.raiz->de);
	else
		auxiz=buscaCalendario(c,sub.raiz->iz);
		auxde=buscaCalendario(c,sub.raiz->de);
		if(auxiz==true || auxde== true)
			return true;

	return false;
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

bool
TABBCalendario::auxBuscar(TABBCalendario a)
{
	bool auxiz=true,auxde=true;
	TABBCalendario aux(*this);
	if(!buscaCalendario(a.raiz->item,aux))
		return false;
	else
	{
		if(!a.raiz->iz.EsVacio())
			auxiz=this->auxBuscar(a.raiz->iz);
		if(!a.raiz->de.EsVacio())
			auxde=this->auxBuscar(a.raiz->de);
		if(!auxiz || !auxde)
			return false;
	}

	return true;
}

bool
TABBCalendario::operator==(TABBCalendario &a)
{
	bool auxiz=true,auxde=true;
	TABBCalendario aux(*this);
	if(!buscaCalendario(a.raiz->item,aux))
		return false;
	else
	{
		if(!a.raiz->iz.EsVacio())
			auxiz=this->auxBuscar(a.raiz->iz);
		if(!a.raiz->de.EsVacio())
			auxde=this->auxBuscar(a.raiz->de);
		if(!auxiz || !auxde)
			return false;
	}

	return true;
}












