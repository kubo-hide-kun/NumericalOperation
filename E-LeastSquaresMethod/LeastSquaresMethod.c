#include<stdio.h>
#include<math.h>
int main(void){

    //入力部
    int n;
    scanf("%d",&n);
    double x[10],y[10];
    for(int i=0;i<n;i++)scanf("%lf %lf",&x[i],&y[i]);
    

    double Ab[10][3];//[[a,b,y]...]
    double tA[2][10];

    //tAと[A b]を生成
    for(int i=0;i<n;i++){
        //まずは両辺の対数をとった値を[A b]に格納
        Ab[i][0]=1;
        Ab[i][1]=x[i];
        Ab[i][2]=log(y[i]);
        //Aの転置行列であるtAを生成
        tA[0][i]=Ab[i][0];
        tA[1][i]=Ab[i][1];
    }

    double matrix[2][3];
    //tAと[A b]の積を計算
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            matrix[i][j]=0;
            for(int k=0;k<n;k++)matrix[i][j]+=tA[i][k]*Ab[k][j];
        }
    }

    //連立方程式を解く(行列が小さいのでループは使わず実装)
    double head = matrix[0][0];
    for(int i=0;i<3;i++)matrix[0][i] /= head;
    head = matrix[1][0];
    for(int i=0;i<3;i++)matrix[1][i] -= matrix[0][i]*head;

    //係数a,bの算出
    double b = matrix[1][2]/matrix[1][1];
    double a = exp(matrix[0][2] - matrix[0][1]*b);

    //出力部
    printf("y = %lf*e^(%lfx)",a,b);
    return 0;
}