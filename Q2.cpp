#include<iostream>
#include<vector>
using namespace std;





void Set_Queen(int **maze,int n,int *row,int *col,int ri){
    int flag=0,flag1=1,flag2=0,i=0,j=1;
    while(!flag2){
    int i=0;
        for(;i<n;i++){
            flag1=0;
            if(maze[i][j]!=1){
                for(int s=0;s<ri;s++){
                    if(i+j==row[s]+col[s] || i-j == row[s]-col[s] || i==row[s] || j== col[s]){
                        flag1=1;
                        break;
                    }
                }
                if(flag1==1){
                flag1=0;
                    continue;
                }
                else{
                    if(j==n-1){
                        flag1=1;
                        flag2=1;
                        row[ri]=i;
                        col[ri]=j;
                        break;
                    }
                    else{
                        flag1=1;
                        row[ri]=i;
                        col[ri]=j;
                        ri++;
                        maze[i][j]=1;
                        j++;
                        break;
                    }

                }

            }

        }
         if(flag1==0){
            for (int t = 0 ;t<n;t++){
                maze[t][j]=0;
            }
            j-=1;
            row[ri]=-1;
            col[ri]=-1;
            ri--;
        }
    }
    cout<<"\nPostions:"<<"\n";
    for (int i=0;i<n;i++)
    cout<<row[i]<<" "<<col[i]<<endl;
    cout<<"Board\n";
    for(int k=0;k<n;k++)
    {
    for(int l=0;l<n;l++){
    flag=0;
    for(int m=0;m<n;m++){
    if(k==row[m] && l ==col[m]){
    flag=1;
    break;
    }
    }
    if(flag==1)
    {cout<<"X,X"<<"  ";
    flag=0;
    }
    else
    cout<<k<<","<<l<<"  ";
    }
    cout<<endl<<endl;
    }
}








int main(){
int n;
cout<<"Enter Size Of Maze : ";
cin>>n;
int **maze = new int* [n];
for (int i=0;i<n;i++)
maze[i] = new int [n];
for (int i=0;i<n;i++)
for(int j=0;j<n;j++)
maze[i][j]=0;
int *row = new int [n];
int *col=new int [n];
for (int i=0;i<n;i++)
row[i]=col[i]=-1;
maze[0][0]=1;
row[0]=0;
col[0]=0;
Set_Queen(maze,n,row,col,1);

}
