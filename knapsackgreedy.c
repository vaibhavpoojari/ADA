#include<stdio.h>
#define max_items 100
double computemaxvalue(double w,double weight[],double value[],double ratio[],int nitems);
int getnextitem(double weight[],double value[], double ratio[],int nitems);
int main()
{
int nitems;
double w,weight[max_items],value[max_items],ratio[max_items];
printf("enter the number of items:");
scanf("%d",&nitems);
printf("enter wights of the items:\n");
int i;
for(i=0;i<nitems;i++)
{
scanf("%lf",&weight[i]);
}
printf("enter value of the items:\n");
for(i=0;i<nitems;i++)
{
scanf("%lf",&value[i]);
}
for(i=0;i<nitems;i++)
{
ratio[i]=value[i]/weight[i];
}
printf("enter capacity of kanpsack:");
scanf("%lf",&w);
printf("\nmaximum value in knapsack of capacity %0.2f is : %0.2f\n",w,computemaxvalue(w,weight,value,ratio,nitems));
return 0;
}
double computemaxvalue(double w,double weight[],double value[],double ratio[],int nitems)
{
double cw=0;
double cv=0;
printf("\nitems considered are:");
while(cw<w)
{
int item=getnextitem(weight,value,ratio,nitems);
if(item==-1)
{
break;
}
printf("%d",item+1);
if(cw+weight[item]<=w)
{
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}
else
{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int getnextitem(double weight[],double value[],double ratio[],int nitems)
{
double highest=0;
int index=-1;
int i;
for(i=0;i<nitems;i++)
{
if(ratio[i]>highest)
{
highest=ratio[i];
index=i;
}
}return index;
}






























 
