CC = gcc
LD = gcc

CFLAGS = -O2 -g -Iinclude -MT $@ -MMD -MP -MF
LDFLAGS = -O2 -g

YAVM_SOURCES = $(shell find src/ -type f -name '*.c')
YAVM_OBJECTS = $(patsubst %.c,%.o, $(YAVM_SOURCES))

YAVM_CFLAGS = $(CFLAGS) src/.deps -c
YAVM_LDFLAGS = $(LDFLAGS)
YAVM_NAME = "yavm"


.PHONY: all
all: $(YAVM_NAME)
	@echo "Done."

.PHONY: clean
clean: clean/$(YAVM_NAME)
	@echo "Done."

### YAVM
$(YAVM_NAME): $(YAVM_OBJECTS)
	@echo "  LD      $(YAVM_NAME)"
	@$(LD) $^ $(YAVM_LDFLAGS) -o $@

.c.o: src/.deps/%d
	@echo "  CC      $@"
	@$(CC) $(YAVM_CFLAGS) $< -o $@

.PRECIOUS: src/.deps/%.d
src/.deps/%.d: ;

.PHONY: clean/$(YAVM_NAME)
clean/$(YAVM_NAME):
	@rm -vrf $(YAVM_OBJECTS) $(YAVM_NAME) src/.deps
