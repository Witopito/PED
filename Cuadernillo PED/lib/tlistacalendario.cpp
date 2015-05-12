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
	TListaPos q,i;
	q=l.Primera();

	TNodoCalendario *nuevo = new TNodoCalendario();   //Se crea el primer nodo, y se le asigna memoria
	nuevo->c = q.pos->c;								//Se copia el calendario del primer nodo, al nuevo primer nodo
	primero=nuevo;
	i.pos=primero;
	q=q.Siguiente();									//el iterador se incrementa

	//a partir de la segunda posicion
	while(!q.EsVacia()){
		TNodoCalendario *nuevo = new TNodoCalendario();
		nuevo->c = q.pos->c;
		i.pos->siguiente=nuevo;
		q=q.Siguiente();
		i=i.Siguiente();
	}

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
TListaCalendario::operator=(const TListaCalendario &l)
{

	if(!this->EsVacia())
	{
		this->~TListaCalendario();
	}

	TListaPos q,i;
	q=l.Primera();

	TNodoCalendario *nuevo = new TNodoCalendario();   //Se crea el primer nodo, y se le asigna memoria
	nuevo->c = q.pos->c;								//Se copia el calendario del primer nodo, al nuevo primer nodo
	primero=nuevo;
	i.pos=primero;
	q=q.Siguiente();									//el iterador se incrementa

	//a partir de la segunda posicion
	while(!q.EsVacia()){
		TNodoCalendario *nuevo = new TNodoCalendario();
		nuevo->c = q.pos->c;
		i.pos->siguiente=nuevo;
		q=q.Siguiente();
		i=i.Siguiente();
	}

	return *this;
}

bool
TListaCalendario::operator==(TListaCalendario &l)
{
 	TListaPos p,q;
 	p=l.Primera();
 	q=Primera();
 	while(!q.EsVacia()&&!p.EsVacia())
 	{
 		if(p.pos->c!=q.pos->c)
 			return false;
 		p=p.Siguiente();
 		q=q.Siguiente();
 	}
 	if(!q.EsVacia()||!p.EsVacia())
 		return false;
 	return true;
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
	prim.pos=primero;
	return prim;
}



bool
TListaCalendario::Insertar(const TCalendario &cal)
{
	TListaPos p,q;

	if(!EsVacia())
	{
		if(!Buscar(cal))
		{
			p.pos=primero;
			q=p.Siguiente();
			//primera posicion
			if(p.pos->c>cal)
			{
				TNodoCalendario *nuevo = new TNodoCalendario();
				nuevo->c=cal;
				nuevo->siguiente=p.pos;
				primero=nuevo;
				return true;
			}
			else	//a partir de la segunda
			{
				while(!q.EsVacia())
				{
					if(q.pos->c>cal)
					{
						TNodoCalendario *nuevo = new TNodoCalendario();
						nuevo->c=cal;
						p.pos->siguiente=nuevo;
						nuevo->siguiente=q.pos;
						return true;
					}
					p=q;
					q=q.Siguiente();
				}
				TNodoCalendario *nuevo = new TNodoCalendario();
				nuevo->c=cal;
				p.pos->siguiente=nuevo;
				return true;
			}
		}
	}
	else
	{
		TNodoCalendario *nuevo = new TNodoCalendario();
		nuevo->c=cal;
		primero=nuevo;
		return true;
	}

	return false;

}


bool
TListaCalendario::Borrar(const TCalendario &cal)
{
	TListaPos p,q;


	if(Buscar(cal))
	{
		if(primero->c==cal)
		{
			TNodoCalendario *aux = new TNodoCalendario();
			aux=primero;
			primero=primero->siguiente;
			delete aux;
			return true;
		}
		else
		{
			p=Primera();
			q=p.Siguiente();
			while(!q.EsVacia())
			{
				if(q.pos->c==cal)
				{
					TNodoCalendario *aux = new TNodoCalendario();
					aux=p.pos->siguiente;
					p.pos->siguiente=q.pos->siguiente;
					delete aux;
					return true;
				}
				p=q;
				q=q.Siguiente();
			}
		}
	}
	return false;
}


bool
TListaCalendario::Borrar(const TListaPos &posicion)
{
	TListaPos p,q;

	p=Primera();
	q=p.Siguiente();
	while(!q.EsVacia())
	{
		if(q==posicion)
		{
			TNodoCalendario *aux = new TNodoCalendario();
			aux=q.pos;
			p.pos->siguiente=q.pos->siguiente;
			delete aux;
			return true;
		}
		p=q;
		q=q.Siguiente();
	}

	return false;
}

//NO FUNCIONA BIEN, REHACER Y PROBAR
bool
TListaCalendario::Borrar(int d,int m,int a)
{
	TCalendario aux(d,m,a,NULL);
	TListaPos q;
	q=Primera();
	bool borrado=false;

	while(!q.EsVacia())
	{
		if(q.pos->c<aux)
		{
			Borrar(q.pos->c);
			borrado=true;
		}
		q=q.Siguiente();
	}

	return borrado;
}


bool
TListaCalendario::Buscar(const TCalendario &cal)
{
	TListaPos q;
	q.pos=primero;
	while(!q.EsVacia())
	{
		if(q.pos->c==cal)
			return true;
		q=q.Siguiente();
	}
	return false;
}

bool
TListaCalendario::EsVacia() const
{
	if(primero==NULL)
		return true;
	return false;
}

TCalendario
TListaCalendario::Obtener(const TListaPos &p) const
{
	return p.pos->c;
}


ostream& operator<<(ostream &x,const TListaCalendario &l)
{
	TListaPos q;
	x<<"<";
	if(!l.EsVacia())
	{
		q=l.Primera();
		while(!q.EsVacia())
		{
			if(!q.Siguiente().EsVacia())
				x<< l.Obtener(q) << " ";
			else
				x<<l.Obtener(q);
			q=q.Siguiente();
		}
	}
	x<<">";
	return x;

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
	pos=NULL;
}

TListaPos &
TListaPos::operator=(const TListaPos &p)
{
	pos=p.pos;
	return *this;
}

//metodos
bool
TListaPos::operator==(const TListaPos &p)
{
	if(pos==p.pos)
		return true;

	return false;
}

bool
TListaPos::operator!=(const TListaPos &p)
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

