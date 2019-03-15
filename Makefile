# all:
#	gcc -g -Wall main.c reader.c word.c dict.c tree.c -o reader
# run:
#	valgrind ./reader.out

OBJ = dict.o tree.o reader.o word.o
PROG1 = wf1
PROG2 = wf2
CFLAGS += -Wall -g
CXXFLAGS += -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread 
HDR = dict.h reader.h word.h tree.h

#g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
#        -pthread -c ${GTEST_DIR}/src/gtest-all.cc


all : $(PROG1) $(PROG2)

$(PROG1) : $(OBJ) main.c
	$(CC) -o $@ $^ $(CFLAGS) -DLIST=dict

$(PROG2) : $(OBJ) main.c
	$(CC) -o $@ $^ $(CFLAGS) -DLIST=tree_from_dict

main.c : $(HDR)
$(OBJ) : $(HDR)

gtest-all.o : ${GTEST_DIR}/src/gtest-all.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean: 
	$(RM) $(OBJ) $(PROG)
