#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

my_perror(const char *str){
    printf("%s:%s\n",str, strerror(errno));
}

main(int argc, int* argv[]){
    FILE *f; 
    
    if(argc<2){
	printf("Usage : perror_use file_name");
	exit(1);
    }
    
    if((f=fopen(argv[1],"r"))==NULL){
	my_perror("my_perror");
	exit(1);
    }
    printf("Open a file \%s\n", argv[1]);
    fclose(f);
}
