cc = gcc

all : static_m dynamic_m shared_m

static_m: calcmain.c
	$(cc) -static -I./lib -L./lib -o static_m calcmain.c -ltest
dynamic_m: dynamic.c
	$(cc) -rdynamic -o dynamic_m dynamic.c -ldl
shared_m: calcmain.c
	$(cc) -I./lib -L./lib -o shared_m calcmain.c -ltest

