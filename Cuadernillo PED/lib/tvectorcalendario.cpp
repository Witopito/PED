/*
 * TVectorCalendario.cpp
 *
 *  Created on: 18/03/2015
 *      Author: hmb6
 */

#include "tvectorcalendario.h"
#include "tcalendario.h"

TVectorCalendario::TVectorCalendario() {
	this->c = NULL;
	this->tamano = 0;
	this->error = TCalendario();

}

TVectorCalendario::TVectorCalendario(int t)
{
	if(t<0)
	{
		this->c = NULL;
		this->tamano = 0;
	}
	else
	{
		this->c= new TCalendario[t];
		this->tamano=t;
	}
	this->error = TCalendario();
}

TVectorCalendario::~TVectorCalendario() {
	if(this->c!=NULL)
	{
		this->tamano=0;
		delete [] c;
		this->c = NULL;
	}
}

TVectorCalendario &
TVectorCalendario::operator=(TVectorCalendario &v)
{
	this.~TVectorCalendario();

	this->c = TCalendario[v.Tamano];
	this->tamano = v.Tamano();
	this->error = TCalendario();

	return this;
}

bool
TVectorCalendario::operator==(TVectorCalendario &v)
{
	bool igualdad = true;
	if(this->tamano==v.Tamano())
	{
		for(int i=0;i<tamano;i++)
		{
			if(this->c[i]!=v.c[i])
			{
				igualdad = false;
			}
		}
	}
	else
	{
		igualdad = false;
	}
	return igualdad;
}

bool
TVectorCalendario::operator!=(TVectorCalendario &v)
{
	if(this==v)
		return false;

	return true;
}

TCalendario &
TVectorCalendario::operator[](int pos)
{
	if(pos < 1 || pos > tamano)
	{
		return error;
	}

	return c[pos-1];
}

TCalendario
TVectorCalendario::operator[](int pos) const
{
	if(pos < 1 || pos > tamano)
	{
		return error;
	}

	return c[pos-1];
}

int
TVectorCalendario::Tamano()
{
	return this->tamano;
}

void
TVectorCalendario::MostrarMensajes(int d,int m,int a)
{
	TCalendario aux = TCalendario();
	TVectorCalendario v = (*this);
	bool primera = true;
	if(!aux.comprobarFecha(d,m,a))
	{
		cout << "[]" << endl;
	}
	else
	{
		aux = TCalendario(d,m,a,"");
		cout << "[";
		for(int i=1;i<=tamano;i++)
		{
			if(v[i].mayorFecha(aux))
			{
				if(primera == true)
				{
					primera = false;
				}
				else
				{
					cout << ", ";
				}

				cout << v[i];
			}
		}
	}
}


//actualizadooooooo
