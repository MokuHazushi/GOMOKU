### COMPILER 
CC		= g++
CFLAGS		= -std=c++0x -Wall -c
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

GL3_HEADERS	= "/usr/local/include/GL3"
GL_LIB 		= "GL"
# You can get the opengl libraries by installing GLUT with apt-get install freeglut3-dev
# GLUT depends on OpenGL, this way installing GLUT will trigger the dependencies needed

### FINAL TARGET
MAIN		= Main.o
TARGET		= gomoku

### TARGETS
all: $(TARGET)

$(TARGET) : $(OBJ)/$(MAIN) $(ENGINE_LIBFILE) $(GRAPHIC_LIBFILE)
	$(CC) $(LFLAGS) $< -o $@ \
		-L$(SDL_LIBFOLDER) -L$(LIB) \
		-l$(ENGINE_LIB) -l$(GRAPHIC_LIB) -l$(SDL_LIB) \
		-l$(GL_LIB) #CAREFUL ORDER MATTER


$(ENGINE_LIBFILE) : $(ENGINE_OBJS)
	$(AR) $(ARFLAGS) $(LIB)/$@ $^

$(OBJ)/engine/%.o: $(SRC)/engine/%.cpp
	mkdir -p $(OBJ)/engine
	$(CC) -o $@ $(CFLAGS) $< -I$(INCLUDE)


$(GRAPHIC_LIBFILE) : $(GRAPHIC_OBJS)
	$(AR) $(ARFLAGS) $(LIB)/$@ $^

$(OBJ)/graphic/%.o: $(SRC)/graphic/%.cpp
	mkdir -p $(OBJ)/graphic
	$(CC) -o $@ $(CFLAGS) $< -I$(INCLUDE) -I$(SDL_HEADERS) -I$(GL3_HEADERS)


$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ $(CFLAGS) $< -I$(INCLUDE) -I$(SDL_HEADERS)
	
clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/* $(TARGET)
