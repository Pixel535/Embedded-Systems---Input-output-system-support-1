#include <REGX52.H>

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
   for(x=0;x<200;x++)
      {
         for(y=0;y<200;y++) {;}
      }
}

void main(void)
{
   unsigned char data index = 0;
	 unsigned char data index2 = 0;
   bit Zezwalaj = 1;
   unsigned char i = 0;
	 
   while(1)
   {
				P2 = Tab[index];
				Key = P2;
				if (Warunek)
				{ 
					if (Zezwalaj == 1)
					{
						if(Key_1 == 0) index2 = 3;
						else if(Key_2 == 0) index2 = 2;
						else if(Key_3 == 0) index2 = 1;
						for(i = 4; i > index; i--)
						{
							Dioda = Zapal; Delay(); Dioda = Zgas; Delay();
						}
						Delay(); Delay();
						for(i = 0; i < index2; i++)
						{
							Dioda = Zapal; Delay(); Dioda = Zgas; Delay();
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
