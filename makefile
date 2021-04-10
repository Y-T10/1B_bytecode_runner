#サフィックスルールの無効にする
MAKEFLAGS+= --no-builtin-rules

#生成されるプログラム
OutputProgram:=simBOBO

#ソースファイルのディレクトリ
SrcDir:=src

TOOLS :=conv_bit_row fetch_num
REG   :=access_reg
FETCH :=fetch_data
DECODE:=decode_asm decode_filter read_op_list
EXEC  :=exec_op exec_func_list cal_op
MAIN  :=read_bin_file main

#プログラムに必要なファイル一覧
SRC   :=${TOOLS} ${REG} ${FETCH} ${DECODE} ${EXEC} ${MAIN}

#プログラムを生成する
.PHONY: all
all: ${OutputProgram}

#オブジェクトファイルのリンク
${OutputProgram}: $(addsuffix .o, ${SRC})
	g++ -Wall -std=c++20 -g3 -o $@ $^

#ソースコードのコンパイル
%.o: ${SrcDir}/%.cpp
	g++ -Wall -std=c++20 -g3 -c $^

#中間生成物を削除する
.PHONY: clean
clean:
	-@rm *.o

#生成されたものを全て削除する
.PHONY: all_clean
all_clean: clean
	-@rm *.exe