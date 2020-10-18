#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    void *handle;
    int (*add)(int, int), (*divide)(int, int), (*multiply)(int, int), (*subtract)(int, int);
    char *error;

    handle = dlopen("./lib/libtest.so",RTLD_LAZY);
    if(!handle){
	fputs(dlerror(), stderr);
	exit(1);
    }
    add = dlsym(handle, "add");
    if((error = dlerror())!=NULL){
	fprintf(stderr, "%s", error);
	exit(1);
    }
    divide = dlsym(handle, "divide");
    if((error = dlerror())!=NULL){
	fprintf(stderr, "%s", error);
	exit(1);
    }
    multiply = dlsym(handle, "multiply");
    if((error = dlerror())!=NULL){
	fprintf(stderr, "%s", error);
	exit(1);
    }
    subtract = dlsym(handle, "subtract");
    if((error = dlerror())!=NULL){
	fprintf(stderr, "%s", error);
	exit(1);
    }

    (*add)(5,3);
    printf("\n");
    (*subtract)(5,3);
    printf("\n");
    (*multiply)(5,3);
    printf("\n");
    (*divide)(5,3);
    printf("\n");
    dlclose(handle);


    return 0;

}
