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
		//TABBCalendario aux(*this);
		if(!Buscar(c))
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
TABBCalendario::Buscar(const TCalendario &c)
{
	bool auxiz,auxde;

	if(!EsVacio() &&raiz->item == c)
		return true;
	else if(EsVacio())
		return false;
	else if(raiz->de.EsVacio() && raiz->iz.EsVacio())
		return false;
	else if(!raiz->iz.EsVacio() && raiz->de.EsVacio())
		return raiz->iz.Buscar(c);
	else if(!raiz->iz.EsVacio() && raiz->de.EsVacio())
		return raiz->de.Buscar(c);
	else
		auxiz=raiz->iz.Buscar(c);
		auxde=raiz->de.Buscar(c);
		if(auxiz==true || auxde== true)
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
	if(!Buscar(a.raiz->item))
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

int
TABBCalendario::Nodos()
{
	if(raiz==NULL)
		return 0;
	else
		if(raiz->iz.EsVacio()&&raiz->de.EsVacio())
			return 1;
		else if(!raiz->iz.EsVacio()&&!raiz->de.EsVacio())
			return 1+(raiz->iz.Nodos())+(raiz->de.Nodos());
		else if(!raiz->iz.EsVacio())
			return 1+(raiz->iz.Nodos());
		else
			return 1+(raiz->de.Nodos());

	return 0;
}

int
TABBCalendario::NodosHoja()
{
	if(raiz==NULL)
		return 0;
	else
		if(raiz->iz.EsVacio()&&raiz->de.EsVacio())
			return 1;
		else if(!raiz->iz.EsVacio()&&!raiz->de.EsVacio())
			return ((raiz->iz.NodosHoja())+(raiz->de.NodosHoja()));
		else if(!raiz->iz.EsVacio())
			return ((raiz->iz.NodosHoja()));
		else
			return ((raiz->de.NodosHoja()));

	return 0;
}

bool
TABBCalendario::operator==(TABBCalendario &a)
{
	bool auxiz=true,auxde=true;
	//TABBCalendario aux(*this);


	if(Nodos()!=a.Nodos())
		return false;
	if(!Buscar(a.raiz->item))
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


int
TABBCalendario::Altura()
{
	int a1,a2;

	if(raiz!=NULL)
	{
		a1=raiz->iz.Altura();
		a2=raiz->de.Altura();
		return (1+(a1<a2 ? a2 : a1));
	}
}



bool
TABBCalendario::Borrar(TCalendario &c)
{
	if(Buscar(c))
	{
		if(c < raiz->item)
			raiz->iz.Borrar(c);
		else if(c > raiz->item)
			raiz->de.Borrar(c);
		else
		{
			if(raiz->de.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux=raiz->iz.raiz;
				raiz=aux;
			}
			else if(raiz->iz.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux=raiz->de.raiz;
				raiz=aux;
			}
			else
			{
				TNodoABB *aux = new TNodoABB(Max());
				//aux=Max();				//se crea el nodo auxiliar con el del maximo de la izquierda
				aux->de=raiz->de;		//se cuelga la parte derecha del arbol actual, en la derecha del aux
				Borrar(aux->item);		//se borra el nodo hoja maximo de la derecha
				raiz=aux;				//se sustituye el actual por el aux
			}
		}
	}
	return false;
}

TNodoABB
TABBCalendario::Max()
{
	TNodoABB *aux = new TNodoABB();
	if(EsVacio())
	{
		return *aux;
	}
	if(raiz->de.EsVacio())
	{
		aux=raiz;
		return *aux;
	}
	else
	{

		aux=new TNodoABB(raiz->de.Max());
		return *aux;
	}

	return *aux;
}


TVectorCalendario
TABBCalendario::Inorden()
{
	int posicion=1;
	TVectorCalendario v(Nodos());
	InordenAux(v,posicion);
	return v;
}

void
TABBCalendario::InordenAux(TVectorCalendario &v, int &a)
{
	if(!EsVacio())
	{
		raiz->iz.InordenAux(v,a);
		v[a]=raiz->item;
		a++;
		raiz->de.InordenAux(v,a);
	}
}








//void PreordenAux(TVectorCalendario &, int &);
//void PostordenAux(TVectorCalendario &, int &);


//TVectorCalendario Preorden();
//TVectorCalendario Postorden();
//TVectorCalendario Niveles();
//friend ostream & operator<<(ostream &, TABBCalendario &);
//TABBCalendario operator+( TABBCalendario &);
//TABBCalendario operator-( TABBCalendario &);



