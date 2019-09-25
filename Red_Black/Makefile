SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

Red_Black_Tree: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o 

run:
	make && ./Red_Black_Tree

