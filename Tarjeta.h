class Tarjeta{
	protected: 
		int idTarjeta;
	
	public:
		 Tarjeta();
		Tarjeta(int i);
		virtual int calculaPago(Reloj r1, Reloj r2, int t)=0;
		int calculaHorasCobrar(Reloj r1, Reloj r2);
		virtual void muestraDatos()=0;
		int getIdTarjeta();
		void setIdTarjeta(int i);
		
		
};

Tarjeta :: Tarjeta()
{idTarjeta=0;
}

Tarjeta :: Tarjeta(int idt)
{idTarjeta=idt;
}

int Tarjeta :: calculaHorasCobrar(Reloj r1, Reloj r2)
{
	int h = 0, mt;
	mt = r2 - r1;
	
	while(mt>0)
	{mt -= 15;
	
		if(mt>0)
		{h++;
		mt -= 60;
			}
		}
		
	
	
	return h;
	
	
}

int Tarjeta :: getIdTarjeta()
{return idTarjeta;
}

void Tarjeta :: setIdTarjeta(int i)
{idTarjeta = i;
}
