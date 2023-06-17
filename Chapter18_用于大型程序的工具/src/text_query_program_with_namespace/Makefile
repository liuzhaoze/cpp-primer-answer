CC = clang++            # 编译器
# CFLAGS = -Wall -D DEBUG # 编译选项
CFLAGS = -Wall          # 编译选项
TARGET = a.exe          # 目标文件名

# 源文件列表 $(wildcard *.cpp) 表示当前工作目录下的所有 .cpp 文件
SRC = $(wildcard *.cpp) ../../../lib/StrBlob.cpp ../../../lib/strip.cpp
# 目标文件列表 $(patsubst %.cpp, %.o, $(SRC)) 表示将 SRC 变量中所有的 .cpp 替换为 .o
OBJ = $(patsubst %.cpp, %.o, $(SRC))

# $@ 表示冒号左边的目标
# $^ 表示冒号右边的所有依赖
# $< 表示冒号右边的第一个依赖

$(TARGET) : $(OBJ) # 链接（将所有的 .o 链接为目标文件）
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp # 编译（将所有的 .cpp 文件编译为对应的 .o 文件）
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	rm -f $(OBJ) $(TARGET)
