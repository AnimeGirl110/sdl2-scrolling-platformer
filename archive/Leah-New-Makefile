# MAKE COMMANDS
.PHONY: all clean git run

# PROJECT FOLDERS
BLD_DIR := build
EMS_DIR := C:/Users/gcyua/OneDrive/Documents/Projects/WebAssemblyProjects/emsdk/upstream/emscripten
EMS_EMS := $(EMS_DIR)/system/include
EMS_SDL := $(EMS_DIR)/cache/sysroot/include
IMG_DIR := images
INC_DIR := include
OBJ_DIR := obj
PUB_DIR := public
SRC_DIR := src

# INCLUDES
INC := -I $(INC_DIR) -I $(EMS_SDL) -I $(EMS_EMS)

# INTEROPERABILITY
EXPORT_FUNCS	:= '_resize', '_main'
EXTRA_FUNCS		:= 'cwrap', 'ccall'
IMG_TYPES			:= 'png', 'jpg'

# COMPILER
COMP       := em++
COMP_FLAGS := -MMD -MP -Wall -Wextra -std=c++17 -ggdb
EMS_FLAGS	 := --shell-file $(BLD_DIR)/index-shell.html \
							--preload-file images \
							--emrun \
							-s USE_WEBGL2=1 \
							-s USE_SDL=2 \
							-s USE_SDL_IMAGE=2 \
							-s SDL2_IMAGE_FORMATS="[$(IMG_TYPES)]" \
							-s EXPORTED_FUNCTIONS="[$(EXPORT_FUNCS)]" \
							-s EXPORTED_RUNTIME_METHODS="[$(EXTRA_FUNCS)]" \
							-s ALLOW_MEMORY_GROWTH=1 \
							-s LLD_REPORT_UNDEFINED
OUT				 := -o $(PUB_DIR)/index.html

# FILES
EXE := $(PUB_DIR)/index.html
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# MAKE ALL
all: $(EXE)

$(EXE): $(OBJ) | $(PUB_DIR)
	$(COMP) $(EMS_FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(COMP) $(INC) $(COMP_FLAGS) -c $< -o $@

$(PUB_DIR) $(OBJ_DIR):
	mkdir $@
	Xcopy $(BLD_DIR)\public $(PUB_DIR) /S /E /H /Y

# MAKE CLEAN
clean:
	rmdir $(PUB_DIR) $(OBJ_DIR) /S /Q

# MAKE GIT
git:
	git add -A
	git commit -m "$(msg)"
	git log

# MAKE RUN
run:
	emrun --browser chrome $(PUB_DIR)/index.html

# INCLUDE GENERATED MAKEFILES
-include $(OBJ:.o=.d)
