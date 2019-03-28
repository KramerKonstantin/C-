OUT_DIR := out

LIB_DIR := libs
LIB_NAME := mylib

STATIC_LIB_NAME := ${LIB_NAME}.a

MAJOR_VERSION := 5
MINOR_VERSION := 1
RELEASE_VERSION := 10
DYNAMIC_LIB_NAME := ${LIB_NAME}.so.${MAJOR_VERSION}.${MINOR_VERSION}.${RELEASE_VERSION}

BIN_DIR := bin

SOURCES := hello.cpp here.cpp bye.cpp
OBJECTS := $(patsubst %.cpp, ${OUT_DIR}/%.o, ${SOURCES})

all: make_libs

make_libs: static_lib dynamic_lib
	export LD_LIBRARY_PATH="./lib:$LD_LIBRARY_PATH"
	mkdir -p ${LIB_DIR}

static_lib: ${OBJECTS}
	@echo "\nMaking static lib..."
	mkdir -p ${LIB_DIR}
	ar rv ${LIB_DIR}/${STATIC_LIB_NAME} $^

dynamic_lib: ${OBJECTS}
	@echo "\nMaking dynamic lib..."
	mkdir -p ${LIB_DIR}
	g++ -fPIC -shared $^ -o ${LIB_DIR}/${DYNAMIC_LIB_NAME}

out/%.o: %.cpp mylib.h
	mkdir -p ${OUT_DIR}
	g++ -Wl,-rpath,./${LIB_DIR} -fPIC -c -o $@ $<

${SOURCES}: %:
	cp -nv back/$@ .

clean:
	rm -rf out
	rm -rf bin
	rm -rf libs

test:
	mkdir -p ${BIN_DIR}
	[ ! -f hello.cpp ] && mv -v ${SOURCES} back/ || true
	@echo "\nTesting static lib..."
	g++ main.cpp -o ${BIN_DIR}/main_static -L ${LIB_DIR} -l:${STATIC_LIB_NAME}
	${BIN_DIR}/main_static

	@echo "\nTesting dynamic lib..."
	${CXX} -Wl,-rpath,./${LIB_DIR} main.cpp -o ${BIN_DIR}/main_dynamic -L ${LIB_DIR} -l:${DYNAMIC_LIB_NAME}
	${BIN_DIR}/main_dynamic

