class Reloj {
       private: int hh, mm;
        
        public:
                Reloj();
                Reloj(int h, int m );
                int getHora();
                int getMinu();
                void setHora(int h);
                void setMinu(int m);
                bool operator>=(Reloj r);
                bool operator<=(Reloj r);
                int operator-(Reloj r);
                
             
                void print();
};

 Reloj :: Reloj()
 { hh = 12;
 mm = 00;
 }
 Reloj :: Reloj(int h, int m)
 {hh = h;
 mm = m;
 }
 
int Reloj ::  getHora()
 {return hh;
 }
 
 int Reloj ::  getMinu()
 {return  mm;
 }
 
 void Reloj ::  setHora(int h)
 {hh = h;
 }
 
 void Reloj ::  setMinu(int m)
 {mm = m;
 }
 
bool Reloj :: operator>=(Reloj r)
{bool o;
if (hh != r.getHora())
		{	if (hh > r.getHora())
				{
					o = true;
					}
	
		
		}
else
{if (hh == r.getHora() && mm >= r.getMinu())
o = true;
else
o = false;
}
return o;
}    
 
bool Reloj :: operator<=(Reloj r)
{bool o;
if (hh != r.getHora())
{if (hh <= r.getHora())
o = 1;
else
o = 0;
}

else
{if (mm <= r.getMinu())
o = 1;
else
o = 0;
}
return o;
}  

int Reloj :: operator-(Reloj r)
    {int mn1, mn2, x;
        mn2 = (r.getHora()*60) + r.getMinu();
        mn1 = (hh*60)+mm;  
		
		x = mn1 - mn2;
		
		return x;     
        }
 

 
 void Reloj ::  print()
 {
cout<<setfill('0')<<setw(2)<<hh<<":"<<setfill('0')<<setw(2)<<mm<<endl;
 
 
 }
