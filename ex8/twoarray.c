#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    int raw, col;
    int **one, **two, **result;
    printf(" 행과 열을 입력해주십시오 : ");
    scanf("%d %d",&raw, &col);

    srand((unsigned int)time(NULL));

    one = (int**)malloc(sizeof(int *)*raw);
    two = (int**)malloc(sizeof(int *)*raw);
    result = (int**)malloc(sizeof(int *)*raw);

    for(int i=0 ;i<raw;i++){
	one[i] = (int*)malloc(sizeof(int)*col);
	two[i] = (int*)malloc(sizeof(int)*col);
	result[i] = (int*)malloc(sizeof(int)*col);
    }

    for(int i=0; i<raw; i++){
	for(int j=0 ;j<col ;j++){
	    one[i][j] = (int)((rand()%100)+1);
	    two[i][j] = (int)((rand()%100)+1);
	}
    }
    printf("one\n");
    for(int i=0; i<raw; i++){
	for(int j=0 ;j<col ;j++){
	    printf("[%d][%d] = %-3d ", i, j, one[i][j]);
	}
	printf("\n");
    }

    printf("\ntwo\n");
    for(int i=0; i<raw; i++){
	for(int j=0 ;j<col ;j++){
	    printf("[%d][%d] = %-3d ", i, j, two[i][j]);
	}
	printf("\n");
    }

    for(int i=0;i<raw;i++){
	for(int j=0;j<col;j++){
	    result[i][j]=one[i][j]+two[i][j];
	}
    }
    printf("\n2개의 배열의 요소를 합한 결과 배열입니다.\n");
    printf("result\n");
    for(int i=0;i<raw;i++){
	for(int j=0;j<col;j++){
	    printf("[%d][%d]= %-3d ", i, j, one[i][j]+two[i][j]);
	}
	printf("\n");
    }

    free(one);
    free(two);
    free(result);

    return 0;
}
