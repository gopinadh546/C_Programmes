#include<stdio.h>
int main(){
int t;
scanf("%d",&t);
int a[t];
for(int i=0;i<t;i++){
    int d,c,v;
    scanf("%d %d",&d,&c);
    while(c!=0){
        if(c>0 && d>0){
            d=d-c;
            if(d<=0){
                v=1;
                break;
            }
            c=c/2;
            if(c<=0){
                v=0;
                break;
            }
        }
    }
a[i]=v;

}
for(int i=0;i<t;i++)
    printf("%d\n",a[i]);
}            