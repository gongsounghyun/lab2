OBJECTS = add.o subtract.o multiply.o divide.o

all : libtest.a libtest.so.1.0.1

add.o :
	gcc -c add.c

divide.o :
	gcc -c divide.c

subtract.o :
	gcc -c subtract.c

multiply.o :
	gcc -c multiply.c

libtest.a : $(OBJECTS)
	ar rcs libtest.a $(OBJECTS)
	
libtest.so.1.0.1 : $(OBJECTS)
	gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0.1 $(OBJECTS)
	ln -s libtest.so.1.0.1 libtest.so.1
	ln -s libtest.so.1.0.1 libtest.so
