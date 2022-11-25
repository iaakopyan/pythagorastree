#include<graphics.h>
#define pi 3.1415926536
#include<ctime>
void myline(int x1, int y1, int x2, int y2, int co){
	int N = abs(x2 - x1);
    int M = abs(y2 - y1);
    int x = x1 < x2 ? 1 : -1;
    int y = y1 < y2 ? 1 : -1;
    int e = N - M;
    putpixel(x2, y2, co);
    while(x1 != x2 || y1 != y2) 
   {
        putpixel(x1, y1, co);
        int e2 = e * 2;
        if(e2 > -M) 
        {
            e -= M;
            x1 += x;
        }
        if(e2 < N) 
        {
            e += N;
            y1 += y;
        }
    }
}

void mycirc(int x, int y, int r){
	int maxcol=16;
	int c;
	c=rand() % maxcol;
	int i=0;
	int e;
	int j=r;
	e=3-2*r;
	do{
		putpixel(x+i,y+j,c);
		putpixel(x+j,y+i,c);
 		putpixel(x+j,y-i,c);
 		putpixel(x+i,y-j,c);
 		putpixel(x-i,y-j,c);
 		putpixel(x-j,y-i,c);
 		putpixel(x-j,y+i,c);
 		putpixel(x-i,y+j,c);
		if(e<=0){
			e=e + 4*i +6;
		}
		else{
			e=e+4*(i-j)+10;
			j=j-1;
			
		}
		i=i+1;
	}
	while(i<=j);

}
void pifagor(int n, int x0, int y0, int a, double fi, double alpha){
	int co=6;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	double b,c;
	if(n==0) {
		return;
	}
	else{
		n--;
		b=a*cos(alpha);
		c=a*sin(alpha);
	 	if (n<10){
			co=2;
		}	
	
		x1 = (int)(x0+a*cos(fi)), y1 = (int)(y0-a*sin(fi));
		x2 = (int)(x1-a*sin(fi)), y2 = (int)(y1-a*cos(fi));
		x3 = (int)(x0-a*sin(fi)), y3 = (int)(y0-a*cos(fi));
		x4 = (int)(x3+b*cos(alpha+fi)), y4 = (int)(y3-b*sin(alpha+fi));
	
		mycirc(x2,y4, c/2);
		setcolor(co);
		myline (x0,y0,x1,y1, co);
		myline (x1,y1,x2,y2, co);
		myline (x2,y2,x3,y3, co);
		myline (x0,y0,x3,y3, co);
		myline (x3,y3,x4,y4, co);
		myline (x2,y2,x4,y4, co);
	
		if (co==0){
			co++;
		}
		pifagor(n, x3, y3, (int)b, alpha+fi, alpha);
		pifagor(n, x4, y4, (int)c, -pi/2+alpha+fi, alpha);
	}
	return;
}
 int main(){
 	srand(time(NULL));
    int gddriver = DETECT, gmode;
    initgraph(&gddriver, &gmode, "");
    pifagor(21, getmaxx()-800, getmaxy()-100, 120, 0, pi/6.0);
    getch();
    closegraph();
    return 0;
}
