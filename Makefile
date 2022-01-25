
CFLAGS=$$(pkg-config --cflags gtk4) -Wall  -pedantic -O3 -std=c18 
LIBS=$$(pkg-config --libs gtk4)
BUILD=build
TARGET=langton
CC=gcc
MODULES=\
main.o\
ui.o\
view.o\
model.o\
controler.o


all: prepare $(MODULES)
	$(CC) $(CFLAGS) $(MODULES) $(LIBS) -o $(BUILD)/$(TARGET)


main.o: app/main.c src/view.h src/ui.h
	$(CC) $(CFLAGS) -c app/main.c -o main.o

ui.o: src/ui.c src/ui.h
	$(CC) $(CFLAGS) -c src/ui.c -o ui.o


view.o: src/view.c src/view.h src/ui.h src/controler.h src/model.h
	$(CC) $(CFLAGS) -c src/view.c -o view.o


model.o: src/model.c src/model.h
	$(CC) $(CFLAGS) -c src/model.c -o model.o


controler.o: src/controler.c src/controler.h src/model.h
	$(CC) $(CFLAGS) -c src/controler.c -o controler.o


prepare:
	mkdir -pv $(BUILD)

clean:
	rm -frv $(BUILD)	
	rm -fv *.o

exec: all
	$(BUILD)/$(TARGET)


