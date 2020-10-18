#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

my_assert(int expression){
    if(expression==NULL){
	printf("%s:%d:%s failed 중지됨\n",__FILE__,__LINE__,__func__);
	exit(1);	
    }
}

void foo(int num){
    my_assert( ((num >= 0) && (num <= 100)) );
    printf("foo: num = %d\n", num);
}

main(int argc, char *argv[]){
    int num;
    if (argc < 2) {
	fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber<= 100)\n");
	exit(1);
    }
    num = atoi(argv[1]);
    foo(num);
} 
