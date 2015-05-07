#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#include "Reloj.h"
#include "Registro.h"
#include "Tarjeta.h"
#include "TarjetaCliente.h"
#include "TarjetaEmpleado.h"
#include "TarjetaProveedor.h"

int main()
{
	Registro registro[20];
	Tarjeta* tarj[40];
	char t, d='x';
	int idt; int ids;
	string sec;
	int idtA, idsA;
	int cr=0;									//contador de registros
	int hora, minutos;
	ifstream archEntrada;
	int contador=0;								// contador de tarjetas
	int ix;
	int hCobradas, pago;
	Reloj rEntrada, rSalida;
	
	
	
	archEntrada.open("tarjetas.txt");
	
	while (!archEntrada.eof())                           //carga datos de tarjetas.txt
	{
	
			archEntrada>>t;
			
			
			if (t=='C')
			{
				archEntrada>>idt>>ids;
				tarj[contador]= new TarjetaCliente(idt, ids);
			
				
				
				}
				
			if (t=='E')
			{
				archEntrada>>idt>>ids;
				getline(archEntrada, sec);
		
				tarj[contador]= new TarjetaEmpleado(idt, ids, sec);
				
				}
				
			if (t=='P')
			{
				archEntrada>>idt>>ids;
				getline(archEntrada, sec);
				tarj[contador]= new TarjetaProveedor(idt, ids, sec);
				
				}
		
		contador++;
		
			
		
	}

	archEntrada.close();
	
	
	
	do									// Menu de opciones
	{	
		cout<<"Introduzca la letra que corresponda a la opcion que desee:"<<endl;
		cout<<"a. Entrada al estacionamiento"<<endl;
		cout<<"b. Salida del estacionamiento"<<endl;
		cout<<"c. Consulta del estacionamiento"<<endl;
		cout<<"d. Consulta de tarjetas"<<endl;
		cout<<"e. Salir"<<endl;
		
		cin>>d;
		
		
			
		if (d == 'a')									//Entrada al estacionamiento
		{	
		
			cout<<"introduzca el id de su tarjeta: ";
			cin>>idtA;
			
			for (int k=0; k<contador; k++)
			{
				if ( idtA == tarj[k]->getIdTarjeta() )
				{
					
				cout<<"introduzca la hora de llegada(hh:mm): ";
				cin>>hora;
				cin>>minutos;
				
					if( 0 <= hora < 24 && 0 <= minutos <60 )
					{	
					registro[cr].setIdTarj(idtA);					
					registro[cr].setHrEntrada(hora, minutos);
					cr++;
					
					
					
					
									
					}
					
				
				
				
				}
			
			
			
			}
		}	
		
		else if (d=='b')								//Salida del estacionamiento
		{	
			cout<<"introduzca el id de su tarjeta: ";
			cin>>idtA;
			
			for (int k2=0; k2<cr; k2++)
			{
				if ( idtA == registro[k2].getIdTarj() )
				
				{
					
				cout<<"introduzca la hora de salida(hh:mm): ";
				cin>>hora;
				cin>>minutos;
				
				 rSalida.setHora(hora);
				 rSalida.setMinu(minutos);
				 rEntrada = registro[k2].getHrEntrada();
				
					if (0 <= hora < 24 && 0 <= minutos <60 &&  rSalida >= rEntrada )
					{		
					
					for (int k1=0; k1<contador; k1++)
						{
						 
							if(idtA == tarj[k1]->getIdTarjeta()  )
							{
							hCobradas = tarj[k1]->calculaHorasCobrar(rEntrada, rSalida);
							pago = tarj[k1]->calculaPago(rEntrada, rSalida, 50);
							
							cout<<endl;
							cout<<"Hora de Entrada: ";
							rEntrada.print();
							cout<<endl;
							cout<<"Hora de Salida: ";
							rSalida.print();
							cout<<endl;
							cout<<"minutos totales"<<rSalida-rEntrada<<endl;
							cout<<endl;
							cout<<"Horas a cobrar: "<<hCobradas<<endl;
							cout<<endl;
							cout<<"Total a pagar: "<<pago<<endl;
							
							cr--;
							
							
							}
						}	
									
					}
					
					
				
				
				}
			
				
		}
	}		
		
		else if (d=='c')
		{
			
			
			
			
			cout<<"La informacion de las tarjetas dentro del estacionamiento es la siguiente: "<<endl;
			for (int kdd=0; kdd<cr; kdd++)
			{
				
			 	for(int kd=0; kd<contador; kd++)
					{
					
						
						if ( registro[kdd].getIdTarj() == tarj[kd]->getIdTarjeta() )
						{	tarj[kd]->muestraDatos();	
							cout<<endl;
							cout<<endl; }
						}
				}
			
			
			
		}
			
		else if (d=='d')
		{
			
			cout<<"Los datos de todas las tarjetas dadas de alta son: "<<endl;
			cout<<endl;
			cout<<endl;
			for (int kc=0; kc<contador-1; kc++)
			{
				tarj[kc]->muestraDatos();
				cout<<endl;
				
				}
			
		}
			
		
	else
	cout<<endl;	
			
			
			
		

		}
	while (d!= 'e');
	return 0;

}


