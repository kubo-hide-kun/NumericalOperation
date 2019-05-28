#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8
void swapLow(double matrix[][N*2],int i,int n){
    int j;
    int maxPoint = i;
    double temp;

    // i番目の要素が最大の行を探索
    for(j=i+1;j<n;j++){
        if(fabs(matrix[maxPoint][i])<fabs(matrix[j][i])) maxPoint = j;
    }

    // i行目と探索の結果求めた行を入れ替える
    for(j=0;j<n*2;j++){
        temp = matrix[i][j];
        matrix[i][j] = matrix[maxPoint][j];
        matrix[maxPoint][j] = temp;
    }
}
int main(void){
    int n;
    int i,j,k;
    double matrix[N][N*2];

    // 入力部
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&matrix[i][j]);
        }
        for(j=0;j<n;j++)matrix[i][j+n] = i==j?1:0;
    }

    for(i=0;i<n;i++){
        // 対角成分が0なら強制終了
        swapLow(matrix,i,n);
        double head = matrix[i][i];
        if(fabs(head)<1e-6){
            printf("Can not calcuration\n");
            exit(-1);
        }

        // 対角成分を１にするよう処理
        for(j=i;j<n*2;j++)matrix[i][j] /= head;

        // i+1行目以下のi列目の要素を0にする。
        for(j=i+1;j<n;j++){
            double otherHead = matrix[j][i];
            for(k=i;k<n*2;k++){
                matrix[j][k] -= matrix[i][k]*otherHead;
            }
        }
        /*
        for(j=0;j<n;j++){
            for(k=0;k<n*2;k++){
                printf("%lf ",matrix[j][k]);
            }printf("\n");
        }printf("\n");
        */
    }

    // 逆進代入法
    double ans[N][N];
    for(i=n-1;i>=0;i--){
        for(j=n;j<n*2;j++){
            double sum = 0;
            for(k=i;k<n;k++){
                sum += ans[k][j-n]*matrix[i][k];
            }
            // printf("%lf\n",matrix[i][j]);
            ans[i][j-n] = matrix[i][j] - sum;
        }
    }

    //出力部
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%lf ",ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}