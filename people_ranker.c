#include<stdio.h>
#include<stdlib.h>
 struct looks{
        char name[20];
        int fav_no;
        int face;
        int personality;
        int IQ;
    };

struct looks compare(struct looks*,int);

int main()
{

    int a;
    printf("enter the no of ppl ur databasing\n");
    scanf("%d",&a);
    struct looks *p=malloc(sizeof(struct looks)*a);
    
    for(int i=0;i<a;i++){
        printf("enter details\n");
        scanf(" %s %d %d %d %d",(p+i)->name,&(p+i)->fav_no,&(p+i)->face,&(p+i)->personality,&(p+i)->IQ);
    }

    printf("the best looking guy is\n");

    struct looks best=compare(p,a);

    printf("%s",best.name);


}
struct looks compare (struct looks *p,int n){
    int maxsum;
    maxsum=(p->face+p->personality+p->IQ);
    struct looks a1=p[0];
    for(int i=0;i<n;i++){
        if(((p+i)->face+(p+i)->personality+(p+i)->IQ)>maxsum){
            maxsum=((p+i)->face+(p+i)->personality+(p+i)->IQ);
            a1=*(p+i);
        }
        else continue;
    }

    return a1;
}