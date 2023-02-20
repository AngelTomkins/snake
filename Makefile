CFLAGS = -std=c++20 -I. -I include -lSDL2_image -lSDL2 -lSDL2_ttf  `sdl2-config  --libs --cflags` -g -Wall

TARGET = a.out
$(TARGET): src/*.cpp src/*.hpp
		#x86_64-w64-mingw32-gcc $(CFLAGS) -o $(TARGET) src/*.cpp $(LDFLAGS)
		gcc $(CFLAGS) -o $(TARGET) src/*.cpp $(LDFLAGS)
	
test: ./a.out
	./a.out

clean: ./a.out
	rm ./a.out
