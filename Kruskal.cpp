#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#define MAX 100
#define inputfile "M:/Bai7.txt"



typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DOTHI;

typedef struct EDGE
{
int u;
int v;
int value;
}CANH;

int DocMaTranKe(const char TenFile[100], DOTHI &g)
{
	FILE*f;
	f=fopen("Bai7.txt","rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
void XuatMaTranKe(DOTHI g)
{
	printf("So dinh cua do thi la %d\n",g.n);
	printf("Ma tran ke cua do thi la\n");
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
			printf("%d\t",g.a[i][j]);
		printf("\n");
	}
}

void SapXepTang(CANH E[100],int tongsocanh)
{
CANH canhtam;
for(int i = 0 ; i < tongsocanh - 1 ; i++)
{
for(int j = i + 1 ; j < tongsocanh ; j++)
if(E[i].value > E[j].value)
{
canhtam = E[i];
E[i] = E[j];
E[j] = canhtam;
}
}
}

int KiemTraMaTranKeHopLe(DOTHI g)
{
	int i;
	for (i=0; i<g.n; i++)
	{
		if (g.a[i][i] != 0)
		return 0;
	}
		return 1;
}


int Timbaccuadinh(DOTHI g)
{
	int Bac,i,j;
   	for(i = 0; i<g.n; i++) 
	{
      printf("bac cua dinh %d la:",i);
	  Bac = 0;
      for (j = 0; j<g.n; j++)
      if(g.a[i][j]>0)        
         Bac++;
    printf("%d",Bac);
	}
}

void Kruskal (DOTHI g)
{
  CANH listEdge[MAX];
  int tongsocanh = 0; 
  int i,j;
  for(i = 0 ; i < g.n ; i++) 
	{
  for( j = i+1 ; j< g.n ; j++)
  if(g.a[i][j] > 0)
  {
	listEdge[tongsocanh].u = i;
	listEdge[tongsocanh].v = j;
	listEdge[tongsocanh].value = g.a[i][j];
	tongsocanh++;
  }
	}
	SapXepTang(listEdge, tongsocanh);
	int nT = 0; 
		CANH T[MAX]; 
	int nhan[MAX]; 
		for (i = 0; i < g.n ; i++)
	nhan[i] = i;
	int canhdangxet = 0; 
	while(nT < g.n && canhdangxet < tongsocanh)
{	
if (nhan[listEdge[canhdangxet].u] != nhan[listEdge[canhdangxet].v])
{
T[nT] = listEdge[canhdangxet];
nT++;
int giatri = nhan[listEdge[canhdangxet].v];
for (j = 0; j < g.n; j++)
if (nhan[j] == giatri)
nhan[j] = nhan[listEdge[canhdangxet].u];
}
canhdangxet++; 
}
if(nT != g.n -1) 
printf("\nDo thi khong lien thong \n\n");
else 
{
int TongTrongSoCuaCayKhung = 0;
printf("\nDo thi lien thong \n\n");
printf ("Cay khung nho nhat cua do thi la \n");
for (i = 0; i < nT; i++)
{
printf ("(%d,%d), ", T[i].u, T[i].v);
TongTrongSoCuaCayKhung += T[i].value;
}
printf ("\nTong gia tri cua cay khung la %d\n",TongTrongSoCuaCayKhung);
}
}

int main()
{
	DOTHI g;
	int n;
	int dinh;
	if (DocMaTranKe(inputfile, g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("Bam 1 phim bat ki de bat dau xet tinh lien thong cua do thi ...\n\n");
		getch();
		if (KiemTraMaTranKeHopLe(g) == 1)
		printf ("Do thi hop le.\n\n");
		else
		printf ("Do thi khong hop le.\n\n");
		Kruskal(g);
	}
	getch();
}
