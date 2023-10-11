#include<stdio.h>
#include<stdlib.h>

void increment(int**p,int,int);
int win(int**p,int);
void display(int **p);
int main(){
    int arr[7][6];
    //init arr to 0
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            *(*(arr+i)+j)=0;
        }
    }
    int run=1;
    int winn=0;
while(run){

    int col;
   printf("\nplayer 1 select col\n");
   scanf(" %d",&col);
   increment(arr,col,1);
   display(arr);
   winn=win(arr,1);
   if(winn){printf("\nplayer1 wins");exit(0);}

   printf("\nplayer 2 select col\n");
   scanf(" %d",&col);
   increment(arr,col,2);
   display(arr);
   run=win(arr,2);
   if(winn){printf("\nplayer2 wins");exit(0);}
   

    }

}
void increment(int **arr,int col,int num){
    for(int i=0;i<7;i++){
        if((*(*(arr+i)+col)==0)&&i!=7)continue;
        if(*(*(arr+i)+col)!=0){
            *(*(arr+(i-1))+col)=num;
            break;
        }
        if(i==7){
            *(*(arr+(i))+col)=num;
            break;
        }
    }
}
void display(int **arr){ //prints array
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            printf(" %d",*(*(arr+i)+j));
        }
        printf("\n");
    }
}
int win(int **arr,int num){
    int w=0;
    for(int j=0;j<7;j++){ //VERTICAL CHECKER
       for(int i=0;i<3;i++){
             if((*(*(arr+i)+j))==0)continue;
             if(((*(*(arr+i)+j))==num)&&(i==0|i==1|i==2)){
                if((*(*(arr+i)+j))==(*(*(arr+(i+1))+j))==(*(*(arr+(i+2))+j))==(*(*(arr+(i+3))+j)))return 1;
             }
             

      }
    }
    for(int i=0;i<6;i++){ //HORIZONTAL CHECKER
        for(int j=0;j<4;j++){
            if((*(*(arr+i)+j))==0)continue;
             if(((*(*(arr+i)+j))==num)&&(j==0|j==1|j==2|j==3)){
                if((*(*(arr+i)+j))==(*(*(arr+i)+j+1))==(*(*(arr+(i))+j+2))==(*(*(arr+(i))+j+3)))return 1;
             }
        }
    }

    //DIAGONOL CHECKER


}
