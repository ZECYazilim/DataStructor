all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/AvlEkle.cpp -o ./lib/AvlEkle.o
	g++ -c -I "./include" ./src/AvlDugum.cpp -o ./lib/AvlDugum.o
	g++ -c -I "./include" ./src/OKuyruk.cpp -o ./lib/OKuyruk.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	
bagla:
	g++ ./lib/AvlEkle.o ./lib/Dugum.o ./lib/AvlDugum.o ./lib/OKuyruk.o ./lib/main.o -o ./bin/program
	
calistir: 
	./bin/program