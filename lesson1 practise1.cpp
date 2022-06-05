#include<bits/stdc++.h>
using namespace std;
const int N=1000;

struct node
{
    int q,w,r;
}e[N];

int n,maxn;
int cmp(node x,node y)
{
    return x.q<y.q||x.q==y.q&&x.w>y.w;
}

int f[N],num[N];
void update(int x,int a)
{
      for(int i=x;i<N;i+=i&-i)
      {
          f[i]+=a;
      }
}

int Getsum(int x)
{
    int result=0;
    for(int i=x;i>=1;i-=i&-i)
    {
       result+=f[i];
    }
    return result;
}

int main()
{
     while(scanf("%d",&n),n)
     {
          for(int i=1;i<=n;i++)
          {
              scanf("%d%d",&e[i].q,&e[i].w);
              e[i].r=i;
          }
          sort(e+1,e+n+1,cmp);
          memset(f,0,sizeof(f));
          num[e[1].r]=0;
          update(e[1].w,1);
          maxn=e[1].w;
          for(int i=2;i<=n;i++)
          {
              if(e[i].q==e[i-1].q&&e[i].w==e[i-1].w)
              num[i]=num[i-1];
              num[e[i].r]=Getsum(maxn)-Getsum(e[i].w-1);
              update(e[i].w,1);
              maxn=max(maxn,e[i].w);
          }
          for(int i=1;i<=n;i++)
          {
              if(i!=1)printf(" ");
              printf("%d",num[i]);
          }
          printf("\n");
     }
}
