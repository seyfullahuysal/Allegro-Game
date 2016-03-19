#include<allegro.h>
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#include<math.h>


int tepeler[2][2];

void Baslat();
void Bitir();
int aci_belirle(int,int);
int hiz_belirle();
void bina_ciz();
void top_at();


int main() 
{

		Baslat();
			
		
	
		bina_ciz();
		
		
		Bitir();
		return 0;
}

		
	
	
END_OF_MAIN()

void Baslat() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1300, 680, 0, 0);
	if (res != 0) 
	{
	allegro_message(allegro_error);
	exit(-1);
	}
	install_timer();
	install_keyboard();
	install_mouse();
}

void Bitir() 
{

	clear_keybuf();
 
}

////////////////////////////////////////////////////////////////////////////////////
int aci_belirle(int x1,int y1)
{

	int x2=x1+45,y2=y1-45;
	int aci=45;
	int x_artis=1,y_artis=1;


	while (!key[KEY_ENTER]) 
	{
		
		aci=aci%360;

		if(key[KEY_RIGHT])
		{
			x2+=x_artis;
			y2+=y_artis;
			aci--;

		}

		if(key[KEY_LEFT])
		{
			x2-=1*x_artis;
			y2-=1*y_artis;
			aci++;
			
		}


		if(aci>0 && aci<90)
		{
			x_artis=1;
			y_artis=1;
		}

		if(aci>90 && aci<180)
		{
			x_artis=1;
			y_artis=-1;
		}

		if(aci>180 && aci<270)
		{
			x_artis=-1;
			y_artis=-1;
		}

		if(aci>270 && aci<360)
		{
			x_artis=-1;
			y_artis=1;
		}

		if(aci<0)
		{
			aci=360+aci;
		}

		line(screen,x1,y1,x2,y2,makecol(255,0,255));
		textprintf_ex(screen,font,600,60,makecol(255,255,255),-1,"Aci= %d",aci);
		rest(30);
		clear_bitmap(screen);

	}

	return aci;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int hiz_belirle()
{
	int hiz=0;


	int x1=10,y1=10,x2=1000,y2=100;

	rect(screen,x1,y1,x2,y2,makecol(10,10,255));
	x2=x1;
	while(!key[KEY_A])
	{

		if(key[KEY_RIGHT])
		{
			x2=x2+100;
			hiz+=2;
			clear(screen);
			rectfill(screen,x1,y1,x2,y2,makecol(10,255,10));
			textprintf_ex(screen,font,600,300,makecol(255,255,255),-1,"hýz= %d",hiz);
		}
	
	
		rest(40);
	

	}


	return hiz;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
	void bina_ciz()
	{


	BITMAP *binalar=create_bitmap(1300,680);
	BITMAP *tugla=load_bitmap("tugla.bmp",NULL);
	srand(time(NULL));
	int yukseklik=rand()%7+4;
	int genislik=rand()%4+3;
	int x1=0,y1=680,x,y;

	tepeler[1][1]=(genislik*20);
	tepeler[1][2]=680-(yukseklik*20)+3;

	
	clear_to_color(binalar,makecol(255,255,100));
	
	while(x1+genislik*20<1300)
	{
	x=x1;
	y=y1;
		
		
		
		for(int i=1;i<=yukseklik;i++)
		{

			x=x1;
			for(int j=1;j<=genislik;j++)
			{
			
				blit(tugla,binalar,0,0,x=x+20,y,1300,680);
			}
		
			y=y-20;

		}

		tepeler[2][1]=x1+(40);
		tepeler[2][2]=680-(yukseklik*20);

		y1=675;
		x1=x1+genislik*20+75;
		genislik=rand()%4+3;
		yukseklik=rand()%7+4;

	}
	

	blit(binalar,screen,0,0,0,0,1300,680);
	rest(-1);
	

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
	void top_at()
	{

		BITMAP *arka=create_bitmap(1300,650);
		int x=tepeler[1][1],y=tepeler[1][2];
		
		circlefill(arka,x, y, 25,makecol(255,0,0));

		int aci=aci_belirle(x,y);
		int hiz=hiz_belirle();
		int x_hiz=(int)(cos(aci*3.14/180)*hiz);
		int y_hiz=(int)(sin(aci*3.14/180)*hiz);

		int sayac1=0;

		while(y<=690)
		{
			sayac1++;
			clear_bitmap(arka);
			circlefill(arka,x, y, 25,makecol(255,0,0));

			rest(30);
			
			blit(arka,screen,0,0,00,00,1300,650);

			if(sayac1==10)
			{
				y_hiz-=3;
				sayac1=0;
			}

			x+=x_hiz;
			y-=y_hiz;	

			

		}
		textprintf_ex(screen,font,10,60,makecol(255,255,255),-1,"top durdu");
		rest(-1);

	
	}