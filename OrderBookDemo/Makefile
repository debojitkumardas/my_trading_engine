SRC_DIR=./src/
BIN_DIR=./bin/
GTEST_DIR=./OrderBookTests/lib/googletest/
# LIB_DIR=$(GTEST_DIR)lib/
TEST_DIR=./OrderBookTests/tests/

CXX=g++
DEPFLAGS=-MD -MP
CXXFLAGS=-Wall -Werror -Wextra -Wshadow -pedantic -pthread -lpthread -std=c++17 -I . -I$(GTEST_DIR) -I$(GTEST_DIR)include/ $(DEPFLAGS)

SRC=$(wildcard $(SRC_DIR)*.cpp)
HDR=$(patsubst %.cpp, $(BIN_DIR)%.d, $(notdir $(SRC)))
OBJ=$(patsubst %.cpp, $(BIN_DIR)%.o, $(notdir $(SRC)))
BIN=$(BIN_DIR)main

# ********************************************************
TEST_SRC=$(wildcard $(TEST_DIR)*.cpp)
TEST_OBJ=$(patsubst %.cpp, $(TEST_DIR)%.o, $(notdir $(TEST_SRC)))
TEST_BIN=$(TEST_DIR)SomeTest
# ********************************************************

GTEST_SRC=$(wildcard $(GTEST_DIR)src/*.cc)
# GTEST_HDR=$(patsubst %.cc, $(GTEST_DIR)bin/%.d, $(notdir $(GTEST_SRC)))
# GTEST_OBJ=$(patsubst %.cc, $(GTEST_DIR)bin/%.o, $(notdir $(GTEST_SRC)))
# MAIN_A=$(GTEST_DIR)bin/gtest_main.a
# TEST_A=$(GTEST_DIR)bin/gtest.a

all: $(BIN)

debug: CXXFLAGS += -DDEBUG -g
debug: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tests: $(TEST_BIN)

$(TEST_BIN): $(TEST_OBJ) $(OBJ) gtest_main.a
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_DIR)%.o: $(TEST_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.o: $(GTEST_SRC)
	$(CXX) $(CXXFLAGS) -c $(GTEST_DIR)src/gtest_main.cc

gtest-all.o: $(GTEST_SRC)
	$(CXX) $(CXXFLAGS) -c $(GTEST_DIR)src/gtest-all.cc

clean:
	rm -rf $(HDR) $(OBJ) $(BIN) $(TEST_OBJ) $(TEST_BIN) gtest*

clean_o:
	rm -rf .cache compile_commands.json

run_with_valgrind_log:
	valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --log-file=valfile=valgrind_out.txt ./bin/main
