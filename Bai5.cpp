#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#define MAX 100
#define inputfile "M:/bai5.txt"

typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DOTHI;
int DocMaTranKe(char TenFile[100], DOTHI &g)
{
	FILE*f;
	f=fopen("bai5.txt","rt");
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

int luuVet[MAX];
int chuaXet[MAX];
struct QUEUE
{
	int size,a[MAX];
};
void khoiTaoQueue(QUEUE &Q)
{
	Q.size=0;
}
int dayGiaTriVaoQueue(QUEUE &Q,int value)
{
	if(Q.size+1>=100)
		return 0;
	Q.a[Q.size]=value;
	Q.size++;
	return 1;
}
int layGiaTriRaKhoiQueue(QUEUE &Q,int &value)
{
	if(Q.size<=0)
		return 0;
	value=Q.a[0];
	for(int i=0;i<Q.size-1;i++)
		Q.a[i]=Q.a[i+1];
	Q.size--;
	return 1;
}
int kiemTraQueueRong(QUEUE Q)
{
	if(Q.size<=0)
		return 1;
	return 0;
}
void BFS(int v,DOTHI g)
{
	QUEUE Q;
	khoiTaoQueue(Q);
	dayGiaTriVaoQueue(Q,v);
	while(!kiemTraQueueRong(Q))
	{
		layGiaTriRaKhoiQueue(Q,v);
		chuaXet[v]=1;
		for(int u=0;u<g.n;u++)
			if(g.a[v][u]!=0&&chuaXet[u]==0)
			{
				dayGiaTriVaoQueue(Q,u);
				if(luuVet[u]==-1)
					luuVet[u]=v;
			}
	}
}
void duyetTheoBFS(int S,int F,DOTHI g)
{
	int i;
	for(i=0;i<g.n;i++)
	{
		luuVet[i]=-1;
		chuaXet[i]=0;
	}
	BFS(S,g);
	if(chuaXet[F]==1)
	{
		printf("Duong di tu dinh %d den dinh %d theo BFS la: \n\t",S,F);
		i=F;
		printf("%d",F);
		while(i!=S)
		{
			printf(" <--- %d",luuVet[i]);
			i=luuVet[i];
		}
	}
	else
		printf("\nKhong co duong di tu dinh %d den dinh %d theo BFS\n",S,F);
}
int main()
{
	DOTHI g;
	int S,F;
	if(DocMaTranKe(inputfile, g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n");
		XuatMaTranKe(g);
		printf("Nhap diem bat dau: ");
		scanf("%d",&S);
		printf("Nhap diem ket thuc: ");
		scanf("%d",&F);
		duyetTheoBFS(S,F,g);
	}
}
