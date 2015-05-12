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


TVectorCalendario::TVectorCalendario(const TVectorCalendario &v)
{
	if(this->c!=NULL)
		{
			this->tamano=0;
			delete [] c;
			this->c = NULL;
		}


		this->c = new TCalendario[v.tamano];
		this->tamano = v.tamano;
		this->error = TCalendario();

		for(int i=0;i<tamano;i++)
			c[i]=v.c[i];
}

TVectorCalendario &
TVectorCalendario::operator=(const TVectorCalendario &v)
{
	if(this->c!=NULL)
	{
		this->tamano=0;
		delete [] c;
		this->c = NULL;
	}


	this->c = new TCalendario[v.tamano];
	this->tamano = v.tamano;
	this->error = TCalendario();

	for(int i=0;i<tamano;i++)
		c[i]=v.c[i];

	return *this;
}

bool
TVectorCalendario::operator==(const TVectorCalendario &v)
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
TVectorCalendario::operator!=(const TVectorCalendario &v)
{
	if(*this==v)
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
TVectorCalendario::Tamano() const
{
	return this->tamano;
}

void
TVectorCalendario::MostrarMensajes(int d,int m,int a)
{
	TCalendario aux = TCalendario();
	//TVectorCalendario v(*this);
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
			if((*this)[i].mayorFecha(aux))
			{
				if(primera == true)
				{
					primera = false;
				}
				else
				{
					cout << ", ";
				}

				cout << (*this)[i];
			}
		}
		cout << "]" << endl;
	}
}

int
TVectorCalendario::Ocupadas()
{
	int contador=0;
	TVectorCalendario aux = (*this);

	for(int i=1;i<=aux.Tamano();i++)
	{
		if(!aux[i].EsVacio())
			contador++;
	}

	return contador;
}

bool
TVectorCalendario::Redimensionar(int a)
{

	TVectorCalendario temp(a);
	if(a<=0 || a==tamano)
	{
		return false;
	}
	else if(a>tamano)
	{
		//TVectorCalendario temp(a);
		temp.tamano=a;
		//temp.c=new TCalendario[a];
		for(int i=0;i<tamano;i++)
			temp[i+1]=c[i];
		for(int i=tamano+1;i<=temp.tamano;i++)
			temp[i]=TCalendario();
	}
	else
	{
		//TVectorCalendario temp(a);
		temp.tamano=a;
		//temp.c=new TCalendario[a];
		for(int i=1;i<=a;i++)
			temp[i]=c[i-1];
	}
	*this=temp;
	return true;

}


ostream& operator<<(ostream &x, const TVectorCalendario &vec)
	{
		bool primera = true;
		x << "[";
		if(vec.tamano>0)
		{
			for(int i=1;i<=vec.tamano;i++)
			{
				if(primera == true)
				{
					primera = false;
				}
				else
				{
					x << ", ";
				}

				x << "(" << i << ") " << vec[i];
			}
			x << "]";
		}
		else
		{
			x << "]";
		}
		return x;
	}


bool
TVectorCalendario::ExisteCal(const TCalendario &c)
{
	for(int i=1;i<=tamano;i++)
	{
		if((*this)[i]==c)
			return true;
	}
	return false;
}












