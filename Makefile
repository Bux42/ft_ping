NAME		= ft_ping
HPATH		= inc
INC			= -I$(HPATH)
FLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g3 #-fbounds-check
COMP		= gcc

SRCS	=	\
main/main.c\
socket/socket_init.c\
argv/argv_parser.c\
argv/ipv4_parser.c\
libstr/libstr_1.c\
libstr/strsplit.c

RED='\e[1;31m'
GRN='\e[1;32m'
YEL='\e[1;33m'
BLU='\e[1;34m'
MAG='\e[1;35m'
CYN='\e[1;36m'
END='\e[0m'

DIR_SRC		= $(addprefix $(SRCPATH)/, $(SRCS))
SRCPATH		= src

OBJ 		= $(SRCS:.c=.o)
OBJPATH		= objs
DIR_OBJ		= $(addprefix $(OBJPATH)/, $(OBJ))

all: $(NAME)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@printf "\33[KCompiling `printf $(RED)`$<`printf $(END)`\r"
	@$(COMP) $(FLAGS) -MMD -c $< -o $@ $(INC)

make_objs:
	@mkdir -p $(OBJPATH)
	@mkdir -p $(dir $(DIR_OBJ))

$(NAME): make_objs $(DIR_OBJ)
	@printf "\33[Kmain obj compil:\t`printf $(GRN)`done\t✅`printf $(END)`\n"
	@echo "videsvau" > auteur
	@$(COMP) $(DIR_OBJ) -o $(NAME) $(INCMAC) $(FLAGS)
	@printf "main compilation:\t`printf $(GRN)`done\t✅`printf $(END)`\n"

clean:
	@rm -rf $(DIR_OBJ)

fclean: rmtest
	@printf "\33[K`printf $(RED)`Crushing \t\t\t☠️`printf $(END)`\r"
	@rm -rf $(DIR_OBJ)
	@rm -rf $(NAME)
	@printf "\33[K`printf $(GRN)`Crushing done\t\t\t🗑️`printf $(END)`\n"

test:
	@mkdir test_dir
	@mkdir test_dir/test_rec
	@mkdir test_dir/test_rec2
	@touch test_dir/test_file
	@touch test_dir/test_file2
	@chmod 7000 test_dir/test_file
	@chmod 7777 test_dir/test_file2
	@ln -s test_dir/test_file test_dir/test_link

rmtest:
	@rm -rf test_dir

re: fclean all

.PHONY :			fclean clean re all make_objs test rmtest