# **************************************************************************** #
# GENERIC_VARIABLES

OBJ_DIR = build

# **************************************************************************** #
# COMPILER_OPTIONS

C_COMPILER = clang
C_STANDART = -std=c99
C_CFLAGS =  $(CFLAGS) $(CPPFLAGS) -Wall -Werror -Wextra
C_LFLAGS =  $(CFLAGS) $(CPPFLAGS) -Wall -Werror -Wextra

NASM_COMPILER = nasm
NASM_FORMAT = -f macho64
NASM_FLAGS = 

# **************************************************************************** #
# TEST_LIBASM TARGET DESCRIPTION

TEST_LIBASM_NAME = test_libasm
TEST_LIBASM_PATH = unit_tests
TEST_LIBASM_FILE = ./test_libasm
TEST_LIBASM_SRCS = ut_strlen.c ut_memcmp.c ut_memcpy.c main.c ut_memchr.c ut_memset.c ut_strcpy.c ut_strcmp.c ut_read_write.c ut_strdup.c
TEST_LIBASM_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(TEST_LIBASM_SRCS))
TEST_LIBASM_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(TEST_LIBASM_SRCS))
TEST_LIBASM_LIBS = -l asm -L .
TEST_LIBASM_INCS = -I .

# **************************************************************************** #
# ASM TARGET DESCRIPTION

ASM_NAME = asm
ASM_PATH = .
ASM_FILE = ./libasm.a
ASM_SRCS = ft_read.s ft_memchr.s ft_memset.s ft_strcpy.s ft_strdup.s ft_strcmp.s ft_write.s ft_strlen.s ft_memcmp.s ft_memcpy.s
ASM_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ASM_SRCS))
ASM_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ASM_SRCS))
ASM_LIBS = 
ASM_INCS = 

# **************************************************************************** #
# GENERIC RULES

.PHONY: all re clean fclean
.DEFAULT_GOAL = all

all: $(ASM_FILE) $(TEST_LIBASM_FILE)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(ASM_FILE) $(TEST_LIBASM_FILE)

re: fclean all

$(TEST_LIBASM_FILE): $(ASM_FILE) $(TEST_LIBASM_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(TEST_LIBASM_FILE) $(TEST_LIBASM_OBJS)  $(TEST_LIBASM_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(TEST_LIBASM_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(TEST_LIBASM_INCS) -o $@ -c $< -MMD

$(OBJ_DIR)/%.s.o: $(TEST_LIBASM_PATH)/%.s
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(NASM_COMPILER) $(NASM_FLAGS) $< -o $@ $(NASM_FORMAT) -MD $(OBJ_DIR)/`basename $@ .o`.d -I$(TEST_LIBASM_PATH)

$(ASM_FILE): $(ASM_OBJS)
	@ar rc $(ASM_FILE) $(ASM_OBJS)
	@ranlib $(ASM_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ASM_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ASM_INCS) -o $@ -c $< -MMD

$(OBJ_DIR)/%.s.o: $(ASM_PATH)/%.s
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(NASM_COMPILER) $(NASM_FLAGS) $< -o $@ $(NASM_FORMAT) -MD $(OBJ_DIR)/`basename $@ .o`.d -I$(ASM_PATH)

-include $(TEST_LIBASM_DEPS) $(ASM_DEPS)
