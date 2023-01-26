CC = gcc  # C compiler
CFLAGS = -fPIC -Wall -Werror -Wextra -Wno-unused-result -Wno-unused-parameter -O2 -lSDL2main -lSDL  # C flags
LDFLAGS = -shared   # linking flags
RM = rm -f   # rm command
TARGET_LIB = libengine.so  # engine lib

SRCS = main.c  # source files
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
