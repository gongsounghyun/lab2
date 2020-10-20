#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	char *name;
	int middle;
	int final;
};
struct node *root = NULL;

int compare(const void *cp1, const void *cp2){
	return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}
void print_node(const void *nodeptr, VISIT order, int level){
	if (order == preorder || order == leaf)
		printf("이름 = %-20s, 중간 성적 = %d, 기말 성적 = %d\n", (*(struct node **)nodeptr)->name, (*(struct node **)nodeptr)->middle, (*(struct node **)nodeptr)->final);
	}
int main(){
	int count;
	char *nameptr = (char*)malloc(20*count);
	printf("학생 수를 입력해주십시오 : ");
	scanf("%d",&count);
	struct node *nodeptr = (struct node*)malloc(sizeof(struct node)*count);
	struct node **ret;
	int i = 0;
	printf("학생의 인원만큼 이름 중간 성적 기말 성적을 입력해주십시오\n");
	while (scanf("%s%d%d", nameptr, &nodeptr->middle, &nodeptr->final)){
		nodeptr->name = nameptr;
		ret = (struct node **) tsearch((void *) nodeptr,(void **) &root, compare);
		printf("\"%s\" 님이 ", (*ret)->name);
		if (*ret == nodeptr)
			printf("트리에 추가되었습니다.\n");
		else{
			printf("트리에 이미 존재합니다.\n");
			i--;
		}
		nameptr += strlen(nameptr) + 1;
		nodeptr++;
		i++;
		if(i==count)
			break;
	}
	twalk((void *) root, print_node);
}
