vpath %.cpp src
vpath %.h include

OBJECTS=./obj/main.o ./obj/Goods.o ./obj/GoodsInfo.o ./obj/Manager.o ./obj/Menu.o ./obj/NMemFunc.o
CPPFLAGS=-Iinclude

all: $(OBJECTS)
	g++ $(OBJECTS) $(CPPFLAGS) -o ./lib/test

main.o: main.cpp include/Menu.h include/Manager.h include/Goods.h \
 include/Menu.h include/Goods.h include/NMemFunc.h
	g++ $(CPPFLAGS) -c $< -o ./obj/main.o

Goods.o: src/Goods.cpp include/NMemFunc.h include/Goods.h include/Menu.h
	g++ $(CPPFLAGS) -c $< -o ./obj/Goods.o

GoodsInfo.o: src/GoodsInfo.cpp include/GoodsInfo.h include/Goods.h include/Menu.h
	g++ $(CPPFLAGS) -c $< -o ./obj/GoodsInfo.o

Manager.o: src/Manager.cpp include/Manager.h include/Goods.h include/Menu.h include/NMemFunc.h include/GoodsInfo.h
	g++ $(CPPFLAGS) -c $< -o ./obj/Manager.o

Menu.o: src/Menu.cpp include/Menu.h include/Manager.h include/Goods.h \
 include/Menu.h include/Goods.h include/NMemFunc.h
	g++ $(CPPFLAGS) -c $< -o ./obj/Menu.o

NMemFunc.o: src/NMemFunc.cpp include/NMemFunc.h
	g++ $(CPPFLAGS) -c $< -o ./obj/NMemFunc.o

.PHONY: clean

clean:
	rm -f ./obj/*.o ./lib/test