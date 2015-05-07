class Registro{
	private:
		int idTarj;
		Reloj hrEntrada;
	
	public:
		Registro();
		Registro(int i, int h, int m);
		void setIdTarj(int i);
		void setHrEntrada(int h, int m);
		int getIdTarj();
		Reloj getHrEntrada();
		
};

Registro :: Registro()
{
	idTarj = 0;
	
}

Registro :: Registro(int i, int h, int m)
{
	idTarj = i;
	hrEntrada.setHora(h);
	hrEntrada.setMinu(m);
}

void Registro :: setIdTarj(int i)
{idTarj = i;
}

void Registro :: setHrEntrada(int h, int m)
{	hrEntrada.setHora(h);
	hrEntrada.setMinu(m);
}

int Registro :: getIdTarj()
{return idTarj;
}

Reloj Registro :: getHrEntrada()
{return hrEntrada;
}
