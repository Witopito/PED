/*
 * tcalendario.cpp
 *
 *  Created on: 04/02/2015
 *      Author: hmb6
 */

#include "tcalendario.h"
#include <sstream>

TCalendario::TCalendario() {
	this->dia=1;
	this->mes=1;
	this->anyo=1900;

	this->mensaje=NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, char* mens) {
	this->dia=dia;
	this->mes=mes;
	this->anyo=anyo;
	this->mensaje=mens;

	TCalendario aux = *this;
	if(!aux.comprobarFecha())
	{
		this->dia=1;
		this->mes=1;
		this->anyo=1900;
		this->mensaje=NULL;
	}
}

//Copia
TCalendario::TCalendario(const TCalendario &a) {
	this->anyo=a.anyo;
	this->mes=a.mes;
	this->dia=a.dia;
	if(a.mensaje != NULL)
	{
		this->mensaje = new char[strlen(a.mensaje)+1];
		strcpy(mensaje,a.mensaje);
	}
	else
	{
		this->mensaje = NULL;
	}

}

TCalendario::~TCalendario() {
	this->dia=1;
	this->mes=1;
	this->anyo=1900;

	this->mensaje=NULL;
}

TCalendario &
TCalendario:: operator=(const TCalendario &a)
{
	if(this != &a)
	{
		(*this).~TCalendario();

		dia = a.dia;
		mes = a.mes;
		anyo = a.anyo;

		mensaje = a.mensaje;
	}
	return *this;
}


// Sobrecarga del operador SUMA de fecha + un número de dias;
TCalendario
TCalendario::operator+(int a)
{
	TCalendario temporal(*this);
	if(a>0)
	{
		for(int i=0;i<a;i++)
		{
			temporal++;
		}
		if(temporal.comprobarFecha())
		{
			return temporal;
		}
	}

	return *this;
}
// Sobrecarga del operador RESTA de fecha - un número de dias;
TCalendario
TCalendario::operator-(int a)
{
	TCalendario temporal(*this);

		for(int i=0;i<a;i++)
		{
			temporal--;
		}
		if(temporal.comprobarFecha())
		{
			return temporal;
		}

		temporal.dia = 1;
		temporal.mes = 1;
		temporal.anyo = 1990;
		temporal.mensaje = NULL;
		return *this;
}


// Modifica la fecha incrementandola en un dia (con preincremento);
TCalendario
TCalendario:: operator++(int a)
{
	TCalendario temporal(*this);

		if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10)
				{
					if(dia==31)
					{
						dia=1;
						mes++;
					}
					else
					{
						dia++;
					}
				}
				else if(mes==12)
				{
					if(dia==31)
					{
						dia=1;
						mes=1;
						anyo++;
					}
					else
					{
						dia++;
					}
				}
				else if(mes==4||mes==6||mes==9||mes==11)
				{
					if(dia==30)
					{
						dia=1;
						mes++;
					}
					else
					{
						dia++;
					}
				}
				else
				{
					if(dia==28)
					{
						if(anyo%4==0 && (anyo%100!=0 || anyo%400==0))
						{
							dia++;
						}
						else
						{
							dia=1;
							mes++;
						}
					}
					else
					{
						dia++;
					}
				}

		if(!temporal.comprobarFecha())
			temporal--;

		return temporal;

}
// Modifica la fecha incrementandola en un dia (con postincremento);
TCalendario&
TCalendario:: operator++()
{
	if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10)
					{
						if(dia==31)
						{
							dia=1;
							mes++;
						}
						else
						{
							dia++;
						}
					}
					else if(mes==12)
					{
						if(dia==31)
						{
							dia=1;
							mes=1;
							anyo++;
						}
						else
						{
							dia++;
						}
					}
					else if(mes==4||mes==6||mes==9||mes==11)
					{
						if(dia==30)
						{
							dia=1;
							mes++;
						}
						else
						{
							dia++;
						}
					}
					else
					{
						if(dia==28)
						{
							if(anyo%4==0 && (anyo%100!=0 || anyo%400==0))
							{
								dia++;
							}
							else
							{
								dia=1;
								mes++;
							}
						}
						else
						{
							dia++;
						}
					}
	TCalendario aux = *this;
	if(!aux.comprobarFecha())
	{
		aux--;
		dia = aux.Dia();
		mes = aux.Mes();
		anyo = aux.Anyo();
	}

	return *this;
}
// Modifica la fecha decrementándola en un dia (con postdecremento);
TCalendario
TCalendario:: operator--(int a)
{
	TCalendario temporal(*this);
			if(mes==1)
			{
				if(dia==1)
				{
					dia=31;
					mes=12;
					anyo--;
				}
				else
				{
					dia--;
				}
			}
			else if(mes==3)
			{
				if(dia==1)
				{
					if(anyo%4==0 && (anyo%100!=0 || anyo%400==0))
					{
						dia=29;
						mes--;
					}
					else
					{
						dia=28;
						mes--;
					}
				}
				else
				{
					dia--;
				}
			}
			else if(mes==5||mes==7||mes==10||mes==12)
			{
				if(dia==1)
				{
					dia=30;
					mes--;
				}
				else
				{
					dia--;
				}
			}
			else
			{
				if(dia==1)
				{
					dia=31;
					mes--;
				}
				else
				{
					dia--;
				}
			}

			TCalendario aux(*this);
			if(!aux.comprobarFecha())
			{
				dia = 1;
				mes = 1;
				anyo = 1900;
				mensaje = NULL;
			}
			return temporal;
}
// Modifica la fecha decrementándola en un día (con predecremento);
TCalendario &
TCalendario::operator--()
{
				if(mes==1)
				{
					if(dia==1)
					{
						dia=31;
						mes=12;
						anyo--;
					}
					else
					{
						dia--;
					}
				}
				else if(mes==3)
				{
					if(dia==1)
					{
						if(anyo%4==0 && (anyo%100!=0 || anyo%400==0))
						{
							dia=29;
							mes--;
						}
						else
						{
							dia=28;
							mes--;
						}
					}
					else
					{
						dia--;
					}
				}
				else if(mes==5||mes==7||mes==10||mes==12)
				{
					if(dia==1)
					{
						dia=30;
						mes--;
					}
					else
					{
						dia--;
					}
				}
				else
				{
					if(dia==1)
					{
						dia=31;
						mes--;
					}
					else
					{
						dia--;
					}
				}

				TCalendario aux(*this);
				if(!aux.comprobarFecha())
				{
					dia = 1;
					mes = 1;
					anyo = 1900;
					mensaje = NULL;
				}

				return *this;

}



// Modifica la fecha
bool
TCalendario::ModFecha (int x, int y, int z)
{
	if(comprobarFecha(x,y,z))
	{
		this->dia=x;
		this->mes=y;
		this->anyo=z;

		return true;
	}

	return false;
}

// Modifica el mensaje
bool TCalendario::ModMensaje(char *a){
	if(a != NULL)
	{
		this->mensaje = new char[strlen(a+1)];
		strcpy(mensaje,a);
		return true;
	}
	else
	{
		this->mensaje = NULL;
		return true;
	}

	return false;
}


bool
TCalendario::comprobarFecha()
{
	if(anyo >= 1900)
	{
		if(mes >= 1 && mes <= 12)
		{
			if(mes == 1 || mes == 3 || mes== 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
			{
				if(dia >= 1 && dia <= 31)
				{
					return true;
				}
			}
			else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
			{
				if(dia >= 1 && dia <= 30)
				{
					return true;
				}
			}
			else
			{
				if(anyo%4==0 && (anyo%100!=0 || anyo%400==0))
				{
					if(dia >= 1 && dia <= 29)
					{
						return true;
					}
				}
				else
				{
					if(dia >= 1 && dia <= 28)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool
TCalendario::comprobarFecha(int d,int m, int a)
{
	if(a >= 1900)
	{
		if(m >= 1 && m <= 12)
		{
			if(m == 1 || m == 3 || m== 5 || m == 7 || m == 8 || m == 10 || m == 12)
			{
				if(d >= 1 && d <= 31)
				{
					return true;
				}
			}
			else if(m == 4 || m == 6 || m == 9 || m == 11)
			{
				if(d >= 1 && d <= 30)
				{
					return true;
				}
			}
			else
			{
				if(a%4==0 && (a%100!=0 || a%400==0))
				{
					if(d >= 1 && d <= 29)
					{
						return true;
					}
				}
				else
				{
					if(d >= 1 && d <= 28)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}



// Sobrecarga del operador igualdad;
bool TCalendario::operator==(const TCalendario &cal)
{

	//comparacion de campos fecha
	if(dia!=cal.dia || mes!=cal.mes || anyo!=cal.anyo )
	{
		return false;
	}

	if((mensaje!=NULL && cal.mensaje!=NULL))
	{
		if((strcmp(mensaje, cal.mensaje)) < 0  || (strcmp(mensaje, cal.mensaje)) > 0)
		{
			return false;
		}
	}
	else if(((mensaje==NULL && cal.mensaje!=NULL)) || (mensaje!=NULL && cal.mensaje==NULL))
	{
		return false;
	}

	return true;
}



// Sobrecarga del operador desigualdad;
bool TCalendario::operator!=(const  TCalendario &cal)
{
	if(*this==cal)
	{
		return false;
	}

	return true;
}


// Sobrecarga del operador >; (ver ACLARACIÓN sobre ORDENACIÓN)
bool TCalendario::operator>(const  TCalendario &cal)
{
	if(mayorFecha(cal))
	{
		return true;
	}
	else
	{
		if(!menorFecha(cal))
		{
			if(mayorMensaje(cal))
			{
				return true;
			}
		}
	}

	return false;
}

bool TCalendario::mayorMensaje(const TCalendario &cal)
{
	if(mensaje!=NULL && cal.mensaje==NULL)
	{
		return true;
	}
	if(mensaje!=NULL && cal.mensaje!=NULL)
	{
		if(strcmp(mensaje,cal.mensaje) > 0 )
		{
			return true;
		}
	}

	return false;
}


bool TCalendario::mayorFecha(const TCalendario &cal)
{
	if(anyo > cal.anyo)
	{
		return true;
	}
	else if(anyo == cal.anyo && mes > cal.mes)
	{
		return true;
	}
	else if(anyo == cal.anyo && mes == cal.mes && dia > cal.dia)
	{
		return true;
	}

	return false;
}

bool TCalendario::menorFecha(const TCalendario &cal)
{
	if(anyo < cal.anyo)
	{
		return true;
	}
	else if(anyo == cal.anyo && mes < cal.mes)
	{
		return true;
	}
	else if(anyo == cal.anyo && mes == cal.mes && dia < cal.dia)
	{
		return true;
	}

	return false;
}

// Sobrecarga del operador <; (ver ACLARACIÓN sobre ORDENACIÓN)
bool TCalendario::operator<(const TCalendario &cal)
{
	if(*this==cal || *this>cal)
	{
		return false;
	}
	return true;
}




//TCalendario vacío
	bool
	TCalendario::EsVacio()
	{
		if(dia==1 && mes==1 && anyo==1900 && mensaje==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	// Devuelve el día del calendario;
	int
	TCalendario::Dia()
	{
		return dia;
	}
	// Devuelve el mes del calendario;
	int
	TCalendario::Mes()
	{
		return mes;
	}
	// Devuelve el año del calendario;
	int
	TCalendario::Anyo()
	{
		return anyo;
	}
	// Devuelve el mensaje del calendario;
	char*
	TCalendario::Mensaje()
	{
		return mensaje;
	}


	ostream& operator<<(ostream &x, const TCalendario &c)
	{
		int day=c.dia;
		int month=c.mes;
		int year=c.anyo;
		string mens;
		if(c.mensaje!=NULL)
		{
			string aux(c.mensaje);
			mens = aux;
		}
		else
		{
			mens = "";
		}

		if(day<10)
		{
			if(month<10)
			{
				x << "0" << day << "/0" << month << "/" << year ;
			}
			else
			{
				x << "0" << day << "/" << month << "/" << year;
			}
		}
		else
		{
			if(month<10)
			{
				x << day << "/0" << month << "/" << year;
			}
			else
			{
				x << day << "/" << month << "/" << year;
			}
		}

		x << " \"" << mens << "\"";

		return x;
	}

