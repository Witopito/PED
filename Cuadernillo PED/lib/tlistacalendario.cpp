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

TListaCalendario::TListaCalendario(const TListaCalendario &l)
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
	if(!l.EsVacia())
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
	return *this;
}

bool
TListaCalendario::operator==(const TListaCalendario &l)
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

//IMPLEMENTAR
TListaPos
TListaCalendario::Ultima() const
{
	TListaPos q;
	q=Primera();
	if(!EsVacia())
	{
		while(!q.EsVacia())
		{
			if(q.Siguiente().EsVacia())
				return q;
			q=q.Siguiente();
		}
	}

	return q;
}

TListaPos
TListaCalendario::Primera() const
{
	TListaPos prim;
	prim.pos=primero;
	return prim;
}

int
TListaCalendario::Longitud()
{
	int contador=0;
	TListaPos q;
	q=Primera();
	while(!q.EsVacia())
	{
		contador++;
		q=q.Siguiente();
	}
	return contador;
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


bool
TListaCalendario::Borrar(int d,int m,int a)
{
	TCalendario aux(d,m,a,NULL);
	TListaPos q;
	q=Primera();
	bool borrado=false;

	while(primero->c<aux)
	{
		TNodoCalendario *auxiliar = new TNodoCalendario();
		auxiliar=primero;
		primero=primero->siguiente;
		delete auxiliar;
		borrado=true;
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


TListaCalendario
TListaCalendario::SumarSubl(int I_L1, int F_L1,const TListaCalendario & L2, int I_L2, int F_L2)
{
	int cuentapos;
	TListaCalendario listafinal;
	TListaPos q;

	//bloque de posicionar q para L1
	if(I_L1<=F_L1)
	{
		if(I_L1<=0)		//si el inicio es menor que 1, empieza desde la primera
		{
			q=Primera();
			cuentapos=1;
		}
		else
		{
			q=Primera();
			cuentapos=1;
			while(cuentapos<I_L1 & !q.EsVacia())
			{
				q=q.Siguiente();
				cuentapos++;
			}
		}
		//bloque de añadir los de L1
		while(cuentapos<=F_L1 && !q.EsVacia())
		{
			listafinal.Insertar(q.pos->c);
			cuentapos++;
			q=q.Siguiente();
		}
	}
	//------------------------------------------

	//bloque de posicionar q para L2
	if(I_L2 <= F_L2)
	{
		if(I_L2<=0)		//si el inicio es menor que 1, empieza desde la primera
		{
			q=L2.Primera();
			cuentapos=1;
		}
		else
		{
			q=L2.Primera();
			cuentapos=1;
			while(cuentapos<I_L2 & !q.EsVacia())
			{
				q=q.Siguiente();
				cuentapos++;
			}
		}
		//bloque de añadir los de L1
		while(cuentapos<=F_L2 && !q.EsVacia())
		{
			listafinal.Insertar(q.pos->c);
			cuentapos++;
			q=q.Siguiente();
		}
	}



	//devolvemos la lista
	return listafinal;
}


TListaCalendario
TListaCalendario::operator+(const TListaCalendario &l2)
{
	TListaPos q;
	q=l2.Primera();
	TListaCalendario l1(*this);

	//insertamos los de l2 en l1
	while(!q.EsVacia())
	{
		l1.Insertar(q.pos->c);
		q=q.Siguiente();
	}

	return l1;
}

TListaCalendario
TListaCalendario::operator-(const TListaCalendario &l2)
{
	TListaPos q;
	q=l2.Primera();
	TListaCalendario l1(*this);

	//insertamos los de l2 en l1
	while(!q.EsVacia())
	{
		l1.Borrar(q.pos->c);
		q=q.Siguiente();
	}

	return l1;
}

TListaCalendario
TListaCalendario::ExtraerRango(int n1, int n2)
{
	int cuentapos;
	TListaCalendario listafinal;
	TListaPos q;

	//bloque de posicionar q para L1
	if(n1<=n2)
	{
		if(n1<=0)		//si el inicio es menor que 1, empieza desde la primera
		{
			q=Primera();
			cuentapos=1;
		}
		else
		{
			q=Primera();
			cuentapos=1;
			while(cuentapos<n1 & !q.EsVacia())
			{
				q=q.Siguiente();
				cuentapos++;
			}
		}
		//bloque de añadir los de L1
		while(cuentapos<=n2 && !q.EsVacia())
		{
			listafinal.Insertar(q.pos->c);
			cuentapos++;
			q=q.Siguiente();
		}
	}

	q=listafinal.Primera();
	while(!q.EsVacia())
	{
		Borrar(q.pos->c);
		q=q.Siguiente();
	}

	return listafinal;
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

TNodoCalendario::TNodoCalendario(const TNodoCalendario &n)
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
TNodoCalendario::operator=(const TNodoCalendario &n)
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


TListaPos::TListaPos(const TListaPos &p)
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

