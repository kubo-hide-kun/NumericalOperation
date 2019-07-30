#include<stdio.h>
#include<math.h>
#define FNF(x) (1.0-x)*exp(-x)
int main(void){
    int n;
    scanf("%d",&n);
    double a,b;
    scanf("%lf %lf",&a ,&b);
    
    double h = (b-a)/n;
    double I = FNF(a)+FNF(b);
    printf("%lf:%lf\n",a,FNF(a));
    printf("%lf:%lf\n",b,FNF(b));

    double sum = 0;
    for(double i=1;i<n;i+=2){
        sum += FNF((a+h*i));
    }
    I += sum*4;

    sum = 0;
    for(double i=2;i<n;i+=2){
        sum += FNF((a+h*i));
    }
    I += sum*2;

    I *= h/3;
    printf("%lf\n",I);
}