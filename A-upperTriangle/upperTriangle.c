#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8

int main(void){
    int n;
    int i,j;
    double matrix[N][N+1];

    // 入力部
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=i;j<n+1;j++){
            scanf("%lf",&matrix[i][j]);
        }
    }

    // 対角成分を１にするように
    for(i=0;i<n;i++){
        double head = matrix[i][i];
        if(fabs(head)<1e-6){
            printf("Can not calcuration\n");
            exit(-1);
        }
        for(j=i;j<n+1;j++)matrix[i][j] /= head;
    }

    // 逆進代入法
    double ans[N];
    for(i=n-1;i>=0;i--){
        double sum = 0;
        for(j=i;j<n-1;j++){
            sum += ans[j]*matrix[i][j];
        }
        ans[i] = matrix[i][n] - sum;
    }

    for(i=0;i<n;i++){
        printf("%lf ",ans[i]);
    }
    printf("\n");
    
    return 0;
}