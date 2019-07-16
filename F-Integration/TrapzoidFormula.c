#include<stdio.h>
#include<math.h>
#define FNF(x) (1.0-x)*exp(-x)
int main(void){
    int n;
    double a,b;
    scanf("%lf %lf %d",&a,&b,&n);
    double h = (b-a)/n;
    double s = (FNF(a)+FNF(b))*h/2.0;
    for(int i=1;i<n;i++){
        double x = a + h * i;
        s += FNF(x)*h;
    }
    printf("%.6lf\n",s);
    return 0;
}