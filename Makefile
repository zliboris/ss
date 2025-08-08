# Kompajler i flagovi
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinc

# Flex/Bison alati
LEX := flex
YACC := bison

# Direktorijumi
SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
MISC_DIR := misc

ASM_DIR := $(SRC_DIR)/assembler
LNK_DIR := $(SRC_DIR)/linker
EMU_DIR := $(SRC_DIR)/emulator

# Binari
BIN_ASM := asembler
BIN_LINK := linker
BIN_EMU := emulator

# Flex/Bison fajlovi
LEX_SRC := $(MISC_DIR)/lexer.l
YACC_SRC := $(MISC_DIR)/parser.y
LEX_OUT := $(ASM_DIR)/lex.yy.cpp
YACC_OUT := $(ASM_DIR)/parser.tab.cpp
YACC_HDR := $(SRC_DIR)/assembler/parser.tab.hpp

# Pronađi sve .cpp fajlove po komponentama
ASM_SRC := $(wildcard $(ASM_DIR)/*.cpp)
LNK_SRC := $(wildcard $(LNK_DIR)/*.cpp)
EMU_SRC := $(wildcard $(EMU_DIR)/*.cpp)

# Objektni fajlovi (menjamo src -> obj)
ASM_OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(ASM_SRC:.cpp=.o))
LNK_OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(LNK_SRC:.cpp=.o))
EMU_OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(EMU_SRC:.cpp=.o))

# Dodaj parser/lexer objektne fajlove
ASM_OBJ += $(OBJ_DIR)/assembler/parser.tab.o $(OBJ_DIR)/assembler/lex.yy.o

# Targeti
.PHONY: all clean

all: $(BIN_ASM) $(BIN_LINK) $(BIN_EMU)

# Binari
$(BIN_ASM): $(ASM_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_LINK): $(LNK_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_EMU): $(EMU_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Kompajliraj svaki .cpp fajl u .o u obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Flex i Bison
$(LEX_OUT): $(LEX_SRC) $(YACC_HDR)
	$(LEX) -o $@ $<

$(YACC_OUT) $(YACC_HDR): $(YACC_SRC)
	$(YACC) -d -o $(YACC_OUT) $<

# Kompajliraj parser.tab.cpp
$(OBJ_DIR)/assembler/parser.tab.o: $(YACC_OUT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Kompajliraj lex.yy.cpp
$(OBJ_DIR)/assembler/lex.yy.o: $(LEX_OUT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Čišćenje
clean:
	rm -rf $(OBJ_DIR) $(BIN_ASM) $(BIN_LINK) $(BIN_EMU) \
	       $(LEX_OUT) $(YACC_OUT) $(YACC_HDR)

