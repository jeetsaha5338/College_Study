#include<stdio.h>
int xor(int m,int n)
{
   if(m==n)
   {
      return 0;
   }
   return 1;
}
int main()
{
   int dn,pn,ndn,k,l;
   int a[10],a1[10];
   int b[10];
   int c[10],d[10],i,j;
   printf("Enter For data size & poly size\n");
   scanf("%d%d",&dn,&pn);
   printf("Enter poly:\n");
   for(i=0;i<pn;i++)
   {
      scanf("%d",&b[i]);
   }
   printf("Enter data:\n");
   ndn=dn+pn-1;
   //printf("%d\n",ndn);
   for(i=0;i<ndn;i++)
   {
      if(i<dn)
      {
         scanf("%d",&a[i]);
      }
      else
      {
         a[i]=0;
      }
   }
   printf("\nModified Array:\n");
   for(i=0;i<ndn;i++)
   {
      a1[i]=a[i];
      printf("%d",a[i]);
   }
   printf("\n");

   for(i=0;i<ndn-pn+1;i++)
   {
      if(a[i]==0)
      {
         c[i]=0;
         for(k=0;k<=pn;k++)
         {
            d[k]=c[i]*b[k];
         }

        /* d[1]=c[i]*b[1];
         d[2]=c[i]*b[2];
         d[3]=c[i]*b[3];*/
      }
      else
      {
         c[i]=1;
         for(k=0;k<=pn;k++)
         {
            d[k]=c[i]*b[k];
         }
         /*d[0]=c[i]*b[0];
         d[1]=c[i]*b[1];
         d[2]=c[i]*b[2];
         d[3]=c[i]*b[3];*/
      }
      for(j=0;j<pn;j++)
      {
         a[i+j]=xor(a[i+j],d[j]);
      }
   }
   printf("\nRemainder Array:\n");
   for(i=0;i<ndn;i++)
   {
      printf("%d",a[i]);
   }
   printf("\n\nQuoitent Array:\n");
   for(i=0;i<pn;i++)
   {
      printf("%d",c[i]);
   }

   for(i=0;i<pn;i++)
   {
       a[i]=a1[i];
   }
   printf("\n\nSending Array:\n");
   for(i=0;i<ndn;i++)
   {
      printf("%d",a[i]);
   }
   printf("\n");
   return 0;
}

