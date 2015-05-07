class TarjetaProveedor : public Tarjeta{
	
	private:
		int idPro;
		string empresa;
		
	public:
		TarjetaProveedor();
		TarjetaProveedor(int idt, int idp, string e);
		int getIdProveedor();
		string getEmpresa();
		void setIdProveedor(int idp);
		void setEmpresa(string t);
		int calculaPago(Reloj r1, Reloj r2, int t);
		void muestraDatos();
};

TarjetaProveedor :: TarjetaProveedor() : Tarjeta()
{idPro = 0;
empresa="n/s";
}

TarjetaProveedor :: TarjetaProveedor(int idt, int idp, string e) : Tarjeta(idt)
{idPro = idp;
empresa = e;
}

int TarjetaProveedor :: getIdProveedor()
{return idPro;
}

string TarjetaProveedor :: getEmpresa()
{return empresa;
}

void TarjetaProveedor:: setIdProveedor(int idp)
{idPro=idp;
}

void TarjetaProveedor :: setEmpresa(string e)
{empresa = e;
}

int TarjetaProveedor :: calculaPago(Reloj r1, Reloj r2, int t)
{
	int ht, x;
	
	ht=calculaHorasCobrar(r1, r2);
	
	x=(ht-1)*t;
	
	return x;
}

void TarjetaProveedor :: muestraDatos()
{
	cout<<"PROVEEDOR"<<endl;
	cout<<"numero de proveedor: "<<idPro<<" "<<endl;
	cout<<"tarjeta: "<<idTarjeta<<" "<<endl;
	cout<<"empresa: "<<empresa<<" "<<endl;
}
