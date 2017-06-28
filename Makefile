### COMPILER 
CC		= g++
CFLAGS		= -Wall -c
LFLAGS		= -Wall
AR		= ar
AFLAGS		= -cr

### FOLDERS
TARGET		= gomoku
INCLUDE		= include
SRC		= src
OBJ		= obj
LIB		= lib
BIN		= bin

### ENGINE MODULE
ENGINE_SRC 	= $(wildcard $(SRC)/engine/*.cpp) 
ENGINE_OBJS 	= $(addprefix $(OBJ)/engine/,$(notdir $(ENGINE_SRC:.cpp=.o)))
ENGINE_LIB	= "gmEngine"

### GRAPHIC MODULE
GRAPHIC_SRC	= $(wildcard $(SRC)/graphic/*.cpp)
GRAPHIC_OBJS	= $(addprefix $(OBJ)/graphic/,$(notdir $(GRAPHIC_SRC:.cpp=.o)))
GRAPHIC_LIB	= "gmGraphic"

### TARGETED LIBS
ENGINE_LIBFILE	= "libgmEngine.a"
GRAPHIC_LIBFILE	= "libgmGraphic.a"

### EXTERNAL LIBS
SDL_HEADERS	= "/usr/local/include/SDL2"
SDL_LIBFOLDER	= "/usr/local/lib"
SDL_LIB		= "SDL2"

### FINAL TARGET
MAIN		= Main.o
TARGET		= gomoku

### TARGETS
all: $(TARGET)

$(TARGET) : $(OBJ)/$(MAIN) $(ENGINE_LIBFILE) $(GRAPHIC_LIBFILE)
	$(CC) $(LFLAGS) $< -o $@ \
		-L$(SDL_LIBFOLDER) -L$(LIB) \
		-l$(SDL_LIB) -l$(ENGINE_LIB) -l$(GRAPHIC_LIB)


$(ENGINE_LIBFILE) : $(ENGINE_OBJS)
	$(AR) $(ARFLAGS) $(LIB)/$@ $^

$(OBJ)/engine/%.o: $(SRC)/engine/%.cpp
	mkdir -p $(OBJ)/engine
	$(CC) -o $@ $(CFLAGS) $< -I$(INCLUDE)


$(GRAPHIC_LIBFILE) : $(GRAPHIC_OBJS)
	$(AR) $(ARFLAGS) $(LIB)/$@ $^

$(OBJ)/graphic/%.o: $(SRC)/graphic/%.cpp
	mkdir -p $(OBJ)/graphic
	$(CC) -o $@ $(CFLAGS) $< -I$(INCLUDE) -I$(SDL_HEADERS)


$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ $(CFLAGS) $< -I$(INCLUDE)
	
clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*
