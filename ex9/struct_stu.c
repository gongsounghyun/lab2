#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct grade{
    char name[20];    
    int middle_grade;
    int final_grade;
};

int main(){
    int middle, final, count, i;
    char name;
    char search_name[20];
    printf("학생의 수를 입력해주십시오.");
    scanf("%d", &count);

    struct grade *gra = (struct grade*)malloc(sizeof(struct grade)*count);
    for(int i=0;i<count;i++){
        printf("학생의 이름과 중간 성적 기말 성적을 띄어쓰기로 구분후 입력.");
	scanf("%s %d %d",gra[i].name, &gra[i].middle_grade, &gra[i].final_grade);
    }
    for(int i=0;i<(sizeof(struct grade)/28)*count;i++){
	printf("name : %s, middle_grade : %d, final_grade : %d\n", gra[i].name, gra[i].middle_grade, gra[i].final_grade);
    }
    
    printf("찾으시려는 학생의 이름을 입력해 주십시오. 종료를 원하시면 0을 입력");
    scanf("%s",search_name);
    if(search_name == 0){
    	exit(1);
    }
    else{
    	for(int i=0;i<(sizeof(struct grade)/28)*count;i++){
    		if(strcmp(gra[i].name,search_name)==0){
    			printf("name : %s, middle_grade : %d, final_grade : %d\n", gra[i].name, gra[i].middle_grade, gra[i].final_grade);
    			break;
    		}else if(i == count-1){
    			printf("찾으시는 학생이 존재하지 않습니다.\n");
    		}
    	}
    }

    free(gra);
}
