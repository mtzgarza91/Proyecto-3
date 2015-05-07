class TarjetaEmpleado : public Tarjeta{
	
	private:
		int idEmp;
		string tienda;
		
	public:
		TarjetaEmpleado();
		TarjetaEmpleado(int idt, int ide, string t);
		int getIdEmpleado();
		string getTienda();
		void setIdEmpleado(int ide);
		void setTienda(string t);
		int calculaPago(Reloj r1, Reloj r2, int t);
		void muestraDatos();
};

TarjetaEmpleado :: TarjetaEmpleado() : Tarjeta()
{idEmp = 0;
tienda="n/s";
}

TarjetaEmpleado :: TarjetaEmpleado(int idt, int ide, string t) : Tarjeta(idt)
{idEmp = ide;
tienda=t;
}

int TarjetaEmpleado :: getIdEmpleado()
{return idEmp;
}

string TarjetaEmpleado :: getTienda()
{return tienda;
}

void TarjetaEmpleado:: setIdEmpleado(int ide)
{idEmp=ide;
}

void TarjetaEmpleado :: setTienda(string t)
{tienda = t;
}

int TarjetaEmpleado :: calculaPago(Reloj r1, Reloj r2, int t)
{
	int ht, x;
	
	t=0;
	ht=calculaHorasCobrar(r1, r2);
	
	x=ht*t;
	
	return x;
}

void TarjetaEmpleado :: muestraDatos()
{
	cout<<"EMPLEADO"<<endl;
	cout<<"numero de empleado: "<<idEmp<<" "<<endl;
	cout<<"tarjeta: "<<idTarjeta<<" "<<endl;
	cout<<"trabajador en: "<<tienda<<" "<<endl;
}
