#include"iostream.h"
#include"stdlib.h"
#define MaxSize 100

typedef struct
{
	int *elem;
	int n;
	int listsize;
}Sqlist;

void Creat(Sqlist &L)
{
	int i=0;
	L.elem=(int *)malloc(MaxSize*sizeof(Sqlist));
	L.n=0;
	L.listsize=MaxSize;

	while(1)
	{
		int c = 1;
		// cout<<"请输入内容";
		// cin>>c;
		if(c==0)
		   break;
		L.elem[i++] = c;
	}

	L.n=i;
}

void Show(Sqlist L)
{
	for(int i=0;i<L.n;i++)
		cout<<L.elem[i]<<" ";
	cout<<endl<<"The length of the seqlist is:"<<L.n<<endl;
}

bool DeletMin(Sqlist &L,int &min)//P12 1题（1）
{
	int i=0,p;
	if(L.n==0) return false;
	min=L.elem[0];
	for(i=1;i<L.n;i++)
		if(L.elem[i]<min)
			min=L.elem[i];
	for(i=0;i<L.n;i++)
	{
		if(L.elem[i]==min)
			L.elem[i]=L.elem[L.n-1];
	}
	
}

bool DeletI(Sqlist &L,int i,int &value)//P12 1题（2）
{
	if(L.n==0||i<0||i>=L.n) return false;
	value=L.elem[i-1];
	for(int j=i;j<L.n;j++)
		L.elem[j-1]=L.elem[j];
	L.n--;
}

bool Insert(Sqlist &L,int i,int x)//(3)
{
	int j;

	if(L.n==0 || i<0 || i>L.n)
	{
	   return false;
	}
	   
	for(j = L.n; j >= i; j--)
	{
	   L.elem[j] = L.elem[j-1];	
	}
		
	L.elem[j]=x;
	L.n++;
}

bool DeleteX(Sqlist &L,int x)//(4)
{
	if(L.n==0)return false;
	for(int i=0;i<L.n;i++)
	{
		if(L.elem[i]==x)
		{
			for(int j=i;j<L.n-1;j++)
				L.elem[j]=L.elem[j+1];
			L.n--;
			i--;
		}
	}
}

bool DeleteST(Sqlist &L,int s,int t)//(5)
{
	if(L.n==0||s>t)return false;
	for(int i=L.n-1;i>=0;i--)
		if(L.elem[i]<t&&L.elem[i]>s)
		{
			for(int j=i;j<L.n;j++)
				L.elem[j]=L.elem[j+1];
			L.n--;
		}
		return true;
}

bool DeleteSTq(Sqlist &L,int s,int t)//(6)
{
	int i,j,k,u;
	if(L.n==0||s>t)return false;
	for(i=0;i<L.n&&L.elem[i]<=s;i++);
	if(i>=L.n)return false;
	cout<<i<<endl;
	for(j=L.n-1;j>0&&L.elem[j]>=t;j--);
	if(j<=0)return false;
	cout<<j<<endl;
	for(k=i,u=j;u<L.n;k++,u++)
		L.elem[k]=L.elem[u+1];
	L.n-=(j-i+1);
	return true;
}

bool Merge(Sqlist A,Sqlist B,Sqlist &C)
{
	int i=0,j=0,k=0;
	if((A.n+B.n)>C.listsize)return false;
	while(i<A.n&&j<B.n)
	{
		if(A.elem[i]<=B.elem[j])
			C.elem[k++]=A.elem[i++];
		else 
			C.elem[k++]=B.elem[j++];
	}
	while(i<A.n)C.elem[k++]=A.elem[i++];
	while(j<B.n)C.elem[k++]=B.elem[j++];
	C.n=k;
}

bool DeleteSame(Sqlist &L)//(8)
{
	if(L.n==0)return false;
	
	int i=0,j;
	
	while(i<L.n)
	{
		j=i+1;

		if(L.elem[i]!=L.elem[j])
		{
		   i++;
	       j++;
        }
		else 
		{
			while(L.elem[j]==L.elem[i]&&j<L.n-1)j++;
			int k=i;
			while(j<L.n) L.elem[k++]=L.elem[j++];
			L.n=k;
			i++;
		}
	}
}

int main()
{
	int min = 0;
	Sqlist L;
	Creat(L);
	cout<<"顺序表的长度";
	Show(L);
	// DeletMin(L,min);
	//Show(L);
	cout<<endl<<min<<endl;
}
