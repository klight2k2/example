#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool visited[6];
int n,
matrix[6][6],
x[5],
cmin=3,
op,
minf= 1000,
g;
void Try (int k){
    for (int v = 2; v<=n;v++){
        if (visited[v] == false){
            x[k]= v; visited[v] = true; 
            int t=x[k-1];
            op=op+matrix[t][x[k]];
        if (k == n) //Cập nhật kỉ lục:
        {  
            if (op + matrix[x[k]][1] < minf) minf = op + matrix[x[k]][1]; 
        }else {g = op + (n-k + 1)*cmin; //tính cận
            if (g < minf)  Try(k + 1);}
        op = op-matrix[x[k-1]][x[k]]; 
        visited[v] = false;
        }//end if
    }//end for
}
int main(){
    op=0;
    x[1]=1;
    n=5;
        FILE *fp;
    fp=fopen("city.txt","r");
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            fscanf(fp,"%d\n",&matrix[i][j]);
        }
        
    }
    
    printf("Ma tran la:\n");
     for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
    Try (2);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",x[i]);
    }    
    printf("%d",minf);
}