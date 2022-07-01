#include <REGX52.H>

#define Dwa 0xEB
#define Szesc 0xDD
#define Siedem 0xB7
#define Osiem 0xBB
#define Hash 0x7D
#define Gwiazdka 0x77

#define Dioda P0_0
#define Zapal 0
#define Zgas 1

#define Warunek (Key_3&Key_2&Key_1)==0

unsigned char code Tab[] = {0x7F,0xBF,0xDF,0xEF};
unsigned char bdata Key;
sbit Key_3 = Key^3;
sbit Key_2 = Key^2;
sbit Key_1 = Key^1;

void Delay(void)
{
   unsigned char data x,y;
   for(x=0;x<150;x++)
      {
         for(y=0;y<150;y++) {;}
      }
}

void Delay2(void)
{
   unsigned char data x,y;
   for(x=0;x<200;x++)
      {
         for(y=0;y<200;y++) {;}
      }
}

void main(void)
{
	unsigned char data index = 0;
	unsigned char poprawnosc = 0;
	unsigned char i = 0;
  bit Zezwalaj = 1;
	while(1)
	{
		P2 = Tab[index];
		Key = P2;
		if (Warunek)
		{ 
			if (Zezwalaj == 1)
			{
				if(Key == Szesc && poprawnosc == 0)
				{
					poprawnosc = 1;
				}
				else if(Key == Siedem && poprawnosc == 1)
				{
					poprawnosc = 2;
				}
				else if(Key == Osiem && poprawnosc == 2)
				{
					poprawnosc = 3;
				}
				else if(Key == Dwa && poprawnosc == 3)
				{
					poprawnosc = 4;
				}
				else if(Key == Hash && poprawnosc == 4)
				{
					Dioda = Zapal; Delay(); Dioda = Zgas; Delay();
					Dioda = Zapal; Delay(); Dioda = Zgas; Delay();
					poprawnosc = 0;
				}
				else if(Key == Gwiazdka && poprawnosc == 4)
				{
					for(i = 0; i <= 1; i++)
					{
						Dioda = Zapal; Delay(); Dioda = Zgas; Delay();
						Dioda = Zapal; Delay(); Dioda = Zgas; Delay();
						Dioda = Zapal; Delay(); Dioda = Zgas; Delay2();
					}
					poprawnosc = 0;
				}
				else
				{
					poprawnosc = 0;
				}
				Zezwalaj = 0;
			}
		}
		else
		{
			if (index<3) {index++;}
			else {index = 0;}
			Zezwalaj = 1;
		}
	}
}