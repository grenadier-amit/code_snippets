#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define per1(i,a,b) for(int i=a;i>b;i--)

#define sci1(x) scanf("%d",&x);
#define sci2(x,y) scanf("%d %d",&x,&y);
#define sci3(x,y,z) scanf("%d %d %d",&x,&Y,&z);

#define scl1(x) scanf("%lld",&x);
#define scl2(x,y) scanf("%lld %lld",&x,&y);
#define scl3(x,y,z) scanf("%lld %lld %lld",&x,&Y,&z);

#define mp make_pair
#define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vii;

/*#################### AMIT KUMAR YADAV ## MNNIT ALLAHABAD ####################*/

struct Point
{
	double x,y;
};

Point result1,result2;
double bestDistance;

double euclideanDistance(Point a,Point b)
{
	double X=a.x-b.x;
	double Y=a.y-b.y;
	return sqrt(X*X+Y*Y);
}

bool less2(Point a,Point b)
{
	if(a.y<b.y)
		return true;
	if(a.y>b.y)
		return false;
	return a.x<b.x;
}

void merge(Point *a,Point *aux,int lo,int mid,int hi)
{
	int i,j,k;
	rep(k,lo,hi)
		aux[k]=a[k];
	i=lo;j=mid+1;k=lo;
	while(i<=mid&&j<=hi)
		a[k++] = less2(aux[i], aux[j]) ? aux[i++] : aux[j++];
	while(i<=mid)
		a[k++]=aux[i++];
}

double closestPair(Point *pointsByX, Point *pointsByY,Point *aux,int lo,int hi)
{
	if(hi<=lo)
		return numeric_limits<double>::infinity();

	int mid=lo+(hi-lo)/2;
	double delta=closestPair(pointsByX,pointsByY,aux,lo,mid);
	double dist=closestPair(pointsByX,pointsByY,aux,mid+1,hi);
	if(dist<delta)
		delta=dist;

	merge(pointsByY,aux,lo,mid,hi);

	int M=0,i,j;
	rep(i,lo,hi)
	{
		if(abs(pointsByY[i].x - pointsByX[mid].x)<delta)
			aux[M++]=pointsByY[i];
	}

	double distance, t;
	rep1(i,0,M)
	{
		for(j=i+1;j<M && (aux[j].y - aux[i].y < delta);j++)
		{
			distance=euclideanDistance(aux[i],aux[j]);
			if(distance < delta)
			{
				delta=distance;
				if(delta < bestDistance)
				{
					bestDistance=delta;
					result1=aux[i];
					result2=aux[j];
				}
			}
		}
	}
	return delta;
}

bool X_ORDER(Point a,Point b)
{
	return a.x<b.x;
}

int main()
{
	int N;
	Point *points,*pointsByY,*aux;

	sci1(N);
	points=new Point[N];
	rep1(i,0,N)
	{
		scanf("%lf %lf",&points[i].x,&points[i].y);
	}
	if(N<=1)
		return 0;

	sort(points,points+N,X_ORDER);
	pointsByY=new Point[N];
	rep1(i,0,N)
	{
		pointsByY[i]=points[i];
	}
	aux=new Point[N];

	bestDistance=numeric_limits<double>::infinity();
	closestPair(points,pointsByY,aux,0,N-1);

	printf("%lf %lf\n",result1.x,result1.y);
	printf("%lf %lf\n",result2.x,result2.y);
	printf("%lf\n",bestDistance);

	return 0;
}
