TARGET_NAME	:= primetest

LIBS 		:= PrimalityUtilities
LBUID_DIR 	:= .build
LIBS_TARGET := lib/PrimalityUtilities/$(LBUID_DIR)/libPrimalityUtilities.a
LIBS_DIRS 	:= $(dir $(LIBS_TARGET))

INCLD_NAME 	:= include

SRC_DIR     := src
INCLDS 		:= $(shell find . -type d -name '$(INCLD_NAME)' 2>/dev/null)
INCLD_DIRS 	:= $(INCLDS:./%=%)
BUILD_DIR   := .build
OBJ_DIR 	:= $(BUILD_DIR)/objects
EXEC_DIR 	:= $(BUILD_DIR)/release

TARGET 		:= $(EXEC_DIR)/$(TARGET_NAME)

ALL_SRCS  	:= $(shell find $(SRC_DIR) -type f -name '*.c' 2>/dev/null)
SOURCES		:= $(ALL_SRCS:$(SRC_DIR)/%=%)
OBJECTS     := $(SOURCES:%.c=$(OBJ_DIR)/%.o)
DEPS 		:= $(OBJECTS:.o=.d)

CC 			:= clang
CFLAGS 		:= -std=c17 -Wall -Wextra -Werror -Wshadow -Wvla -Walloca -Wundef -Wfloat-equal \
				-Wstrict-prototypes -Wconversion -Wswitch-enum -Wswitch-default -Wimplicit-fallthrough \
				-Wunreachable-code -Wformat=2 -Wparentheses -Wmisleading-indentation -Wpedantic -pedantic -O2

CPPFLAGS 	:= $(addprefix -I,$(INCLD_DIRS)) -MMD -MP
LDFLAGS 	:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS 		:= $(addprefix -l,$(LIBS))

RM          := rm -f
MAKEFLAGS 	+= --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)


.PHONY: all
all: build

$(TARGET): $(OBJECTS) $(LIBS_TARGET)
	$(DIR_DUP)
	$(CC) $(OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@
	$(info [LINKING] $@ : $(CC) $(OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@)

$(LIBS_TARGET):
	$(foreach d, $(LIBS_DIRS:%$(LBUID_DIR)/=%), $(MAKE) -C $d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
	$(info [COMPILED] $@ : $(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS))

-include $(DEPS)

.PHONY: build
build: $(TARGET)  ## Compile project

.PHONY: re
re:  ## Recompile project
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean
clean:  ## Remove all object and dep files
	for f in $(LIBS_DIRS:%$(LBUID_DIR)/=%); do $(MAKE) -C $$f clean; done
	$(info $(RM) $(OBJECTS) $(DEPS))
	$(RM) $(OBJECTS) $(DEPS)

.PHONY: fclean
fclean: clean  ## Remove all executable files + object + dep files
	for f in $(LIBS_DIRS:%$(LBUID_DIR)/=%); do $(MAKE) -C $$f fclean; done
	$(info $(RM) $(TARGET))
	$(RM) $(TARGET)

.DEFAULT_GOAL := help
.PHONY: help
help:  ## Show this output, i.e. help to use the commands
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' Makefile | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

info-%:
	@make --dry-run --always-make $* | grep -v "info"

print-%:
	@$(info '$*'='$($*)')


.SILENT:

