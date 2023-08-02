LIBNAME 	:= PrimalityUtilities
TARGET_NAME	:= lib$(LIBNAME).a

SRC_DIR     := src
INCLD_DIR 	:= include
BUILD_DIR   := .build
OBJ_DIR 	:= $(BUILD_DIR)/objects

TARGET 		:= $(BUILD_DIR)/$(TARGET_NAME)

ALL_SRCS  	:= $(shell find $(SRC_DIR) -type f -name '*.c' 2>/dev/null)
SOURCES		:= $(ALL_SRCS:$(SRC_DIR)/%=%)
OBJECTS     := $(SOURCES:%.c=$(OBJ_DIR)/%.o)
DEPS 		:= $(OBJECTS:.o=.d)

CC 			:= clang
CFLAGS 		:= -std=c17 -Wall -Wextra -Werror -Wshadow -Wvla -Walloca -Wundef -Wfloat-equal \
				-Wstrict-prototypes -Wconversion -Wswitch-enum -Wswitch-default -Wimplicit-fallthrough \
				-Wunreachable-code -Wformat=2 -Wparentheses -Wmisleading-indentation -Wpedantic -pedantic -O2
CPPFLAGS 	:= -I $(INCLD_DIR) -MMD -MP
LDFLAGS 	:=
AR 			:= ar
ARFLAGS 	:= -r -c -s

RM          := rm -f
MAKEFLAGS 	+= --no-print-directory
DIR_DUP     = mkdir -p $(@D)


.PHONY: all
all: build

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)
	$(info [BUILD] $@ : $(AR) $(ARFLAGS) $(TARGET) $(OBJECTS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
	$(info [COMPILED] $@ : $(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS))

-include $(DEPS)

.PHONY: build
build: $(TARGET)
	$(shell ranlib $(TARGET))
	$(info [RANLIB] $(TARGET))

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean
clean:
	$(info $(RM) $(OBJECTS) $(DEPS))
	$(RM) $(OBJECTS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(info $(RM) $(TARGET))
	$(RM) $(TARGET)

info-%:
	@make --dry-run --always-make $* | grep -v "info"

print-%:
	@$(info '$*'='$($*)')


.SILENT:

