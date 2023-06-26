# *************************************
# Voyager Infrastructure - gXServer
# 'Makefile'
# Author: Juan Carlos Juárez
# Contact: jc.juarezgarcia@outlook.com
# *************************************

voyagergxserver: main.o gxserver.o memorymanager.o memoryqueryhandler.o
	-rm -r build
	mkdir build
	g++ -g -std=c++17 main.o gxserver.o memorymanager.o memoryqueryhandler.o -o ./build/voyagergxserver -lzmq -lrocksdb -pthread
	rm *.o

main.o: ./src/main.cxx
	g++ -g -std=c++17 -c ./src/main.cxx -o main.o -lzmq -lrocksdb -pthread

gxserver.o: ./src/gXServer.cxx ./src/gXServer.h
	g++ -g -std=c++17 -c ./src/gXServer.cxx -o gxserver.o -lzmq -lrocksdb -pthread

memorymanager.o: ./src/MemoryManager.cxx ./src/MemoryManager.h
	g++ -g -std=c++17 -c ./src/MemoryManager.cxx -o memorymanager.o -lzmq -lrocksdb -pthread

memoryqueryhandler.o: ./src/MemoryQueryHandler.cxx ./src/MemoryQueryHandler.h
	g++ -g -std=c++17 -c ./src/MemoryQueryHandler.cxx -o memoryqueryhandler.o -lzmq -lrocksdb -pthread

clean:
	-rm *.o
	-rm *.deb
	-rm -r build
