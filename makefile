edit: main.o Image.o Pixel.o
	g++ -o edit main.o Image.o Pixel.o

main.o: main.cpp
	g++ -c main.cpp

Image.o: Image.cpp Image.h
	g++ -c Image.cpp

Pixel.o: Pixel.cpp Pixel.h
	g++ -c Pixel.cpp

clean:
	rm edit main.o Image.o Pixel.o


