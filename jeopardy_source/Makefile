CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
EXEC = jeopardy

.PHONY: all clean

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(BINDIR)
