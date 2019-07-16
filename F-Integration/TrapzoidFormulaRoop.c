#include<stdio.h>
#include<math.h>
#define FNF(x) (1.0-x)*exp(-x)
int main(void){
    double a,b;
    scanf("%lf %lf",&a,&b);
    double h = (b-a)/2;
    double s = (FNF(a)+FNF(b))*h/2.0;
    double prev=-1;
    for(int n=2;fabs(prev-s)>1e-7;n*=2){
        prev = s;
        h = (b-a)/n;
        s = (FNF(a)+FNF(b))*h/2.0;
        for(int i=1;i<n;i++){
            double x = a + h * i;
            s += FNF(x)*h;
        }
        if(prev==s)break;
    }
    printf("%.6lf\n",prev);
    return 0;
}