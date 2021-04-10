#サフィックスルールの無効にする
MAKEFLAGS += --no-builtin-rules
PROG:=z80_1B_sim

TOOLS :=conv_bit_row fetch_num
REG   :=access_reg
FETCH :=fetch_data
DECODE:=decode_asm decode_filter read_op_list
EXEC  :=exec_op exec_func_list cal_op
MAIN  :=read_bin_file main
SRC   :=${TOOLS} ${REG} ${FETCH} ${DECODE} ${EXEC} ${MAIN}

all: ${PROG}

${PROG}: $(addsuffix .o, ${SRC})
	g++ -Wall -std=c++20 -g3 -o $@ $^

%.o: %.cpp
	g++ -Wall -std=c++20 -g3 -c $^

.PHONY: clean
clean:
	-@rm *.o
	-@rm *.exe