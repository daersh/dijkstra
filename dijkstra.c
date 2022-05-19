#include <stdio.h>
int inf=100000;


void dijkatra(int n,const int test[][n], int *F ){
    int i,min;
    int e;           //엣지
    int vnear;       //다음 위치
    int touch[n];    //현재 위치
    int length[n];   // 가중치
    int count=0;

    for(int j=0;j<2*n;j++){    // F 초기화
        F[j]=-1;
    }

    for(i=0;i<n;i++){// touch 초기화, 측정 행렬 length에 저장
        touch[i]=0;
        length[i]=test[0][i];
    }

    for(int j=1;j<n;j++){

        min=inf;
        for(i=1;i<n;i++) //인접 노드의 가중치가 가장 작은 부분을 vnear에 저장
            if(length[i]>=0 &&length[i]<min){
                min= length[i];
                vnear=i;    
            }
        
        // F에 연결된 노드 두개 저장
        e=touch[vnear]; 
        F[count]=e;
        count++;
        F[count]=vnear;
        count++;

        for(i=1;i<n;i++){
            if(length[vnear]+test[vnear][i]<length[i])  //선택된 노드와 연결된 노드의 가중치 합이 더 작은 값을 도출하는 지 비교
            {
                length[i]=length[vnear]+test[vnear][i]; //더 작은 값을 저장
                touch[i]=vnear;      //다음 노드를 현재 위치로 수정
            }
        }
        length[vnear]=-1;   //가장 낮은 가중치를 찾은 노드는 -1을 주어 반복문에서 더이상 실행하지 않도록 함

    }
}


void printnode(int n, int a[][n], int *F){
    printf("  ****인접 행렬****\n");
    for(int i=0;i<n;i++){   
        for(int j=0;j<n;j++){
        if(a[i][j]==inf) 
            printf("  ∞");
        else 
            printf("  %d", a[i][j]);
        }
          printf("\n");
    }
        printf("  ****연결된 엣지****\n");

    int count=0;
     while(F[count]!=-1){
        printf(" (%d,%d), ", F[count],F[count+1]);
        count+=2;
     }
    printf("\n\n");
}

int main(){
    int n;  //행렬 가로,세로 크기
    int a[6][6]={           
        {0,5,inf,2,4,inf},
        {5,0,3,3,inf,inf},
        {inf,3,0,3,4,2},
        {2,3,3,0,1,inf},
        {4,inf,4,1,0,2},
        {inf,inf,2,inf,2,0}
    };
    int b[7][7]={
        { 0,7,inf,inf,3,10,inf},
	{ 7,0,4,10,2,6,inf},
	{ inf,4,0,2,inf,inf,inf},
	{ inf,10,2,0,11,9,4},
	{ 3,2,inf,11,0,inf,5},
	{ 10,6,inf,9,inf,0,inf},
	{ inf,inf,inf,4,5,inf,0} 
	};

    int c[6][6]={
        {0,2,5,1,inf,inf},
        {2,0,3,2,inf,inf},
        {5,3,0,3,1,5},
        {1,2,3,0,1,inf},
        {inf,inf,1,1,0,2},
        {inf,inf,5,inf,2,0}
    };

    n=6;
    int F2[n];
    dijkatra(n,a,F2);
    printnode(n,a,F2);
    n=6;
     dijkatra(n,c,F2);
    printnode(n,c,F2);
    n=7;
     dijkatra(n,b,F2);
    printnode(n,b,F2);
    
    return 0;
}