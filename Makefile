# Kompajler i opcije
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinc

FLEX := flex
BISON := bison

# Fajlovi za leksičku i sintaksnu analizu
LEX_SRC := misc/scanner.l
YACC_SRC := misc/parser.y
LEX_GEN := src/lex.yy.cpp
YACC_GEN_CPP := src/parser.tab.cpp
YACC_GEN_HPP := inc/parser.tab.hpp

# Folderi
SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

# Izvršni fajlovi
EXEC_ASM := assembler
EXEC_LNK := linker
EXEC_EMU := emulator

# Izvorni fajlovi
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Izvršne mete
all: $(EXEC_ASM) $(EXEC_LNK) $(EXEC_EMU)

# Flex i Bison generisanje
$(LEX_GEN): $(LEX_SRC)
	$(FLEX) -o $@ $<

$(YACC_GEN_CPP) $(YACC_GEN_HPP): $(YACC_SRC)
	$(BISON) -d -o $(YACC_GEN_CPP) $<

# Kompajliranje .cpp fajlova u .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Asembler
$(EXEC_ASM): $(OBJ_DIR)/assembler.o $(OBJ_DIR)/parser.tab.o $(OBJ_DIR)/lex.yy.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Linker
$(EXEC_LNK): $(OBJ_DIR)/linker.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Emulator
$(EXEC_EMU): $(OBJ_DIR)/emulator.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Posebno kompajliranje za flex i bison fajlove
$(OBJ_DIR)/parser.tab.o: $(YACC_GEN_CPP) $(YACC_GEN_HPP)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(YACC_GEN_CPP) -o $@

$(OBJ_DIR)/lex.yy.o: $(LEX_GEN)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(LEX_GEN) -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC_ASM) $(EXEC_LNK) $(EXEC_EMU) \
	       $(LEX_GEN) $(YACC_GEN_CPP) $(YACC_GEN_HPP)

.PHONY: all clean
