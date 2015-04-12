.PHONY: all rebuild clean run dirtree

EXTERNALS	:= externals
BUILD		:= build
DIST		:= dist
TEST		:= test
RES		:= resources

TGT		:= Simple
TGT_TEST	:= Simple_test

RM		:= rm
MKDIR		:= mkdir
FIND		:= find
CP		:= cp
VALGRIND	:= valgrind

## Compilation common flags
#CXX			:= g++-4.9
#CXXFLAGS_COMMON	:= -std=c++14 -Wall -Iinclude-I$(EXTERNALS)/msm/include -I$(EXTERNALS)/di/include -I$(EXTERNALS)/SFML/include

CXX			:= clang++
CXXFLAGS_COMMON		:= -stdlib=libc++ -std=c++1y -Iinclude -I$(EXTERNALS)/msm/include -I$(EXTERNALS)/di/include -I$(EXTERNALS)/SFML-2.2/include
#cmake -DCMAKE_CXX_COMPILER="clang++" -DCMAKE_CXX_FLAGS="-std=c++1y -stdlib=libc++ -U__STRICT_ANSI__"

CXXFLAGS		:= $(CXXFLAGS_COMMON)
DEPSFLAGS		:= -MMD -MP

## Linker common flags
LIB			:= lib/$(CXX)
LD_FLAGS_BASIC		:= -L$(LIB) -lsfml-graphics -lsfml-window -lsfml-system -lX11
LD_FLAGS		:= $(LD_FLAGS_BASIC) -lpthread

## Runtime flags
LD_LIBRARY_PATH 	:= $(LIB):$(LD_LIBRARY_PATH)

## Source objects
CPP_FILES		:= $(shell $(FIND) src -iname *.cpp)
OBJS			:= $(patsubst src%, $(BUILD)/$(DIST)%,$(patsubst %.cpp, %.o, $(CPP_FILES)))
DEPS			:= $(OBJS:.o=.d)

## Test objects
CPP_TEST_FILES		:= $(filter-out src/main.cpp, $(shell $(FIND) src test -iname *.cpp))
TEST_OBJS		:= $(patsubst src%, $(BUILD)/$(TEST)%, $(patsubst test%, $(BUILD)/$(TEST)%,$(patsubst %.cpp, %.o, $(CPP_TEST_FILES))))
TEST_DEPS		:= $(TEST_OBJS:.o=.d)		

## Test specific compilation and linking flags
GMOCK	        	:= $(EXTERNALS)/gmock-1.7.0
LD_FLAGS_TEST		:= $(LD_FLAGS_BASIC) -lgmock -lpthread
CXXFLAGS_TEST		:= $(CXXFLAGS_COMMON) -I$(GMOCK)/include -I$(GMOCK)/gtest/include -Itest/mocks

## Targets
all: $(BUILD)/$(DIST)/$(TGT) 

rebuilt: clean all

test: $(BUILD)/$(TEST)/$(TGT_TEST)
	./$(BUILD)/$(TEST)/$(TGT_TEST)

valgrind: $(BUILD)/$(TEST)/$(TGT_TEST)
	$(VALGRIND) --leak-check=yes ./$(BUILD)/$(TEST)/$(TGT_TEST)

dirtree:
	@$(MKDIR) -p $(foreach directory, $(OBJS), $(shell dirname $(directory)))

dirtree_tst:
	@$(MKDIR) -p $(foreach directory, $(TEST_OBJS), $(shell dirname $(directory)))

run: $(BUILD)/$(DIST)/$(TGT) $(BUILD)/$(DIST)/$(RES)
	@cd $(BUILD)/$(DIST) && ./$(TGT)

clean:
	@$(RM) -Rf $(BUILD)

$(BUILD)/$(TEST)/$(TGT_TEST): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS_TEST) -o $(BUILD)/$(TEST)/$(TGT_TEST) $(shell $(FIND) $(BUILD)/$(TEST) -iname *.o) $(LD_FLAGS_TEST)

$(BUILD)/$(DIST)/$(TGT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/$(DIST)/$(TGT) $(shell $(FIND) $(BUILD)/$(DIST) -iname *.o) $(LD_FLAGS)

$(BUILD)/$(DIST)/%.o: src/%.cpp |  dirtree
	$(CXX) $(CXXFLAGS) $(DEPSFLAGS) -c $< -o $@

$(BUILD)/$(TEST)/%.o: test/%.cpp |  dirtree_tst
	$(CXX) $(CXXFLAGS_TEST) $(DEPSFLAGS) -c $< -o $@

$(BUILD)/$(TEST)/%.o: src/%.cpp |  dirtree_tst
	$(CXX) $(CXXFLAGS_TEST) $(DEPSFLAGS) -c $< -o $@

$(BUILD)/$(DIST)/$(RES):
	@$(CP) -Rf $(RES)/* $(BUILD)/$(DIST)/

-include $(DEPS)
-include $(TEST_DEPS)
