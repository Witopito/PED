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
TNodoAVL::operator=(TNodoAVL &n)
{
	this->~TNodoAVL();
	item=n.item;

	if(n.iz.raiz!=NULL)
		iz=n.iz;
	else
		iz=TAVLCalendario();


	if(n.de.raiz!=NULL)
		de=n.de;
	else
		de=TAVLCalendario();

	fe=n.fe;
	return *this;
}



////////////////////////////////TAVLCalendario/////////////////////////////////////

TAVLCalendario::TAVLCalendario()
{
	raiz=NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &a)
{
	Copiar(a);
}


TAVLCalendario::~TAVLCalendario ()
{
	if(raiz!=NULL)
		delete raiz;
	raiz=NULL;
}

TAVLCalendario &
TAVLCalendario::operator=(const TAVLCalendario &a)
{
	this->~TAVLCalendario();
	Copiar(a);
	return *this;
}


void
TAVLCalendario::Copiar(const TAVLCalendario &origen)
{
	if(origen.raiz !=NULL)
	{
		TNodoAVL *aux = new TNodoAVL();
		aux->item = origen.raiz->item;
		raiz = aux;
		raiz->iz.Copiar(origen.raiz->iz);
		raiz->de.Copiar(origen.raiz->de);
	}
	else
		raiz=NULL;
}


bool
TAVLCalendario::Insertar(const TCalendario &c)
{
	if(this->EsVacio())
	{
		if(!c.EsVacio())
		{
			TNodoAVL *x=new TNodoAVL();
			x->item=c;
			x->fe=0;
			raiz=x;
			return true;
		}
		else
		{
			//cout << cerr << " No se pueden insertar dos arboles repetidos" << endl;
			return false;
		}
	}
	else
	{
		//TAVLCalendario aux(*this);
		if(!Buscar(c))
		{
			this->insertarOrdenado(c);

			return true;
		}
		else
		{
			//cout << cerr << " No se pueden insertar dos arboles repetidos" << endl;
		}
	}
	return false;
}




void
TAVLCalendario::insertarOrdenado(TCalendario c)
{
	if(c<raiz->item)
	{
		if(raiz->iz.EsVacio())
		{
			TNodoAVL *x=new TNodoAVL();
			x->item=c;
			x->fe=0;
			raiz->iz.raiz=x;
		}
		else
			raiz->iz.insertarOrdenado(c);
	}
	else
	{
		if(raiz->de.EsVacio())
		{
			TNodoAVL *x=new TNodoAVL();
			x->item=c;
			x->fe=0;
			raiz->de.raiz=x;
		}
		else
			raiz->de.insertarOrdenado(c);
	}
	equilibrado();
}

bool
TAVLCalendario::Buscar(const TCalendario &c)
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
TAVLCalendario::EsVacio() const
{
	if(raiz == NULL)
		return true;
	return false;
}


void
TAVLCalendario::equilibrado()
{


	//se actualiza el factor de equilibrio
	raiz->fe=raiz->de.Altura()-raiz->iz.Altura();

	if(raiz->fe>1)
	{
		if(raiz->de.raiz->fe >= 0)
			rotacionDD();
		else
			rotacionDI();
		//equilibrio=true;
		raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
		if (raiz->iz.raiz != NULL)
			raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
		if (raiz->de.raiz != NULL)
			raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
	}
	else if(raiz->fe<-1)
	{
		if(raiz->iz.raiz->fe <= 0)
			rotacionII();
		else
			rotacionID();
		//equilibrio=true;
		raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
		raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
		raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
		equilibrado();
	}
	else{}

}

TCalendario TAVLCalendario::Raiz() {
	if (!EsVacio())
		return raiz->item;
	else
		cout << cerr << " arbol vacio no tiene raiz" << endl;
	return TCalendario();
}

void
TAVLCalendario::rotacionDD()
{
	TNodoAVL *aux;
	aux=raiz->de.raiz;
	raiz->de.raiz= raiz->de.raiz->iz.raiz;
	aux->iz.raiz = raiz;
	raiz=aux;
}

void
TAVLCalendario::rotacionDI()
{
	TNodoAVL *aux;
	aux = raiz->de.raiz;
	raiz->de.raiz = aux->iz.raiz->iz.raiz;
	aux->iz.raiz->iz.raiz = raiz;
	raiz = aux->iz.raiz;
	aux->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = aux;

}

void
TAVLCalendario::rotacionID()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = aux->de.raiz->de.raiz;
	aux->de.raiz->de.raiz = raiz;
	raiz = aux->de.raiz;
	aux->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = aux;
}

void
TAVLCalendario::rotacionII()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = raiz->iz.raiz->de.raiz;
	aux->de.raiz = raiz;
	raiz = aux;

}


int
TAVLCalendario::Altura()
{
	int a1,a2;

	if(raiz!=NULL)
	{
		a1=raiz->iz.Altura();
		a2=raiz->de.Altura();
		return (1+(a1<a2 ? a2 : a1));
	}

	return 0;
}

int
TAVLCalendario::Nodos() const
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
TAVLCalendario::NodosHoja()
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



TVectorCalendario
TAVLCalendario::Inorden()
{
	int posicion=1;
	TVectorCalendario v(Nodos());
	InordenAux(v,posicion);
	return v;
}

void
TAVLCalendario::InordenAux(TVectorCalendario &v, int &a)
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
TAVLCalendario::Postorden()
{
	int posicion=1;
	TVectorCalendario v(Nodos());
	PostordenAux(v,posicion);
	return v;
}

void
TAVLCalendario::PostordenAux(TVectorCalendario &v, int &a)
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
TAVLCalendario::Preorden()
{
	int posicion=1;
	TVectorCalendario v(Nodos());
	PreordenAux(v,posicion);
	return v;
}


void
TAVLCalendario::PreordenAux(TVectorCalendario &v, int &a)
{
	if(!EsVacio())
	{
		v[a]=raiz->item;
		a++;
		raiz->iz.PreordenAux(v,a);
		raiz->de.PreordenAux(v,a);
	}
}

/*
TVectorCalendario
TAVLCalendario::Niveles()
{
	int contador=1;
	queue<TAVLCalendario> cola;
	TVectorCalendario v(Nodos());
	TAVLCalendario aux;
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
*/

bool
TAVLCalendario::operator==(const TAVLCalendario &a)
{
	bool auxiz=true,auxde=true;
	//TABBCalendario aux(*this);

	if(raiz==NULL && a.raiz==NULL)
		return true;
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

bool
TAVLCalendario::operator!=(const TAVLCalendario &a)
{
	TAVLCalendario aux = (*this);
	if(aux==a)
		return false;

	return true;
}

bool
TAVLCalendario::auxBuscar(TAVLCalendario a)
{
	bool auxiz=true,auxde=true;
	TAVLCalendario aux(*this);
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


ostream & operator<<(ostream &x, TAVLCalendario &a)
{
	TVectorCalendario v;
	v=a.Inorden();
	x << v;

	return x;
}


















