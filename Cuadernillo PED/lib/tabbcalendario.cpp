/*
 * tabbcalendario.cpp
 *
 *  Created on: 29/04/2015
 *      Author: hmb6
 */

#include "tabbcalendario.h"
#include <queue>


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
TABBCalendario::Insertar(TCalendario &c)
{
	if(this->EsVacio())
	{
		if(!c.EsVacio())
		{
			TNodoABB *x=new TNodoABB();
			x->item=c;
			raiz=x;
			return true;
		}
		else
		{
			cout << cerr << " No se pueden insertar dos arboles repetidos" << endl;
			return false;
		}
	}
	else
	{
		//TABBCalendario aux(*this);
		if(!Buscar(c))
		{
			this->insertarOrdenado(c);
			return true;
		}
		else
		{
			cout << cerr << " No se pueden insertar dos arboles repetidos" << endl;
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
	if(!EsVacio())
		return raiz->item;
	else
		cout << cerr << " arbol vacio no tiene raiz" << endl;
	return TCalendario();
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
				return true;
			}
			else if(raiz->iz.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux=raiz->de.raiz;
				raiz=aux;
				return true;
			}
			else
			{

				TNodoABB *aux = new TNodoABB(raiz->iz.Max());
				TNodoABB *aux2 = new TNodoABB();
				aux2=raiz;
				TCalendario *cal = new TCalendario(raiz->iz.Max().item);

				aux->de=raiz->de;			//se cuelga la parte derecha del arbol actual, en la derecha del aux
				aux2->iz.Borrar(*cal);
				aux->iz=aux2->iz;

				raiz=aux;


				return true;
			}
		}
	}
	else
	{
		cout << cerr << " El elemento no esta en el arbol" << endl;
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


TVectorCalendario
TABBCalendario::Postorden()
{
	int posicion=1;
	TVectorCalendario v(Nodos());
	PostordenAux(v,posicion);
	return v;
}

void
TABBCalendario::PostordenAux(TVectorCalendario &v, int &a)
{
	if(!EsVacio())
	{
		raiz->iz.PostordenAux(v,a);
		raiz->de.PostordenAux(v,a);
		v[a]=raiz->item;
		a++;
	}
}

TVectorCalendario
TABBCalendario::Preorden()
{
	int posicion=1;
	TVectorCalendario v(Nodos());
	PreordenAux(v,posicion);
	return v;
}


void
TABBCalendario::PreordenAux(TVectorCalendario &v, int &a)
{
	if(!EsVacio())
	{
		v[a]=raiz->item;
		a++;
		raiz->iz.PreordenAux(v,a);
		raiz->de.PreordenAux(v,a);
	}
}





TVectorCalendario
TABBCalendario::Niveles()
{
	int contador=1;
	queue<TABBCalendario> cola;
	TVectorCalendario v(Nodos());
	TABBCalendario aux;
	aux=(*this);
	cola.push(aux);

	while(!cola.empty())
	{
		aux=(cola.front());
		v[contador]=aux.raiz->item;
		contador++;
		cola.pop();
		if(!aux.raiz->iz.EsVacio())
			cola.push(aux.raiz->iz);
		if(!aux.raiz->de.EsVacio())
			cola.push(aux.raiz->de);
	}

	return v;
}


ostream & operator<<(ostream &x, TABBCalendario &a)
{
	TVectorCalendario v;
	v=a.Niveles();
	x << v;

	return x;
}


TABBCalendario
TABBCalendario::operator+(TABBCalendario &b)
{
	TVectorCalendario v;
	v=b.Inorden();

	TABBCalendario a(*this);
	for(int i=1;i<=b.Nodos();i++)
		a.Insertar(v[i]);
	return a;
}

TABBCalendario
TABBCalendario::operator-(TABBCalendario &b)
{
	TVectorCalendario v;
	v=this->Inorden();

	TABBCalendario a;
	for(int i=1;i<=this->Nodos();i++)
	{
		if(!b.Buscar(v[i]))
			a.Insertar(v[i]);
	}
	return a;
}









