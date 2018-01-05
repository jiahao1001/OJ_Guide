list_1: list_1.cpp
	g++ $< -o $@ 

list_1_debug: list_1.cpp
	g++ $< -o $@ -g

linkList: linkList.c
	cc $< -o $@

clean:
	rm -rf list_1 list_1_debug linkList