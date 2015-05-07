class TarjetaCliente : public Tarjeta{
	
	private:
		int idCli;
		
		
	public:
		TarjetaCliente();
		TarjetaCliente(int idt, int idc);
		int getIdCliente();
		void setIdCliente(int idc);
		int calculaPago(Reloj r1, Reloj r2, int t);
		void muestraDatos();
};

TarjetaCliente :: TarjetaCliente() : Tarjeta()
{idCli = 0;
}

TarjetaCliente :: TarjetaCliente(int idt, int idc) : Tarjeta(idt)
{idCli = idc;
}

int TarjetaCliente :: getIdCliente()
{return idCli;
}

void TarjetaCliente :: setIdCliente(int idc)
{idCli=idc;
}

int TarjetaCliente :: calculaPago(Reloj r1, Reloj r2, int t)
{
	int ht, x;
	
	ht=calculaHorasCobrar(r1, r2);
	
	x=ht*t;
	
	return x;
}

void TarjetaCliente :: muestraDatos()
{
	cout<<"CLIENTE"<<endl;
	cout<<"numero de cliente: "<<idCli<<" "<<endl;
	cout<<"tarjeta: "<<idTarjeta<<" "<<endl;
}
