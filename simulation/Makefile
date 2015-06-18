
EXEC = simulateur

all: $(EXEC)

view:$(EXEC)
	./$^

$(EXEC): main.c sdl.cpp sdl.hpp ../color.cpp ../color.hpp
	g++ $^ `sdl-config --cflags --libs` -lm -o $@