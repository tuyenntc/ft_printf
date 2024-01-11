#OPT=-00
#generate files that encode make rules for the .h dependencies
#DEPFLAGS=-MP -MD
#automatically add the -I onto each included directory:
#CFLAGS=-Wall -Wextra -Werror -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)
#for-style iteration (foreach) and regular expression completions (wildcard)
#CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
#regular expression replacement
#OBJECTS=$(patsubst %.c,%.o,$(CFILES))
#DEPFILES=$(patsubst %.c,%.c,$(CFILES))
#all: $(BINARY)
#$(BINARY): $(OBJECTS)
#	$(CC) -o $@ $^

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
LIBC=ar rcs
RM=rm -f
CFILES := $(wildcard *.c)
OBJECTS=$(CFILES:.c=.o)

all:$(NAME)

$(NAME):$(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^
clean:
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY:	all clean fclean re
