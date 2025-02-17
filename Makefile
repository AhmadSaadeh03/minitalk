CC= cc

CFLAGS= -Wall -Wextra -Werror

SERVER=server
CLIENT=client

LIBFT_DIR = libft
LIBFT_A = libft/libft.a

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER) : $(OBJS_SERVER) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $@ -L $(LIBFT_DIR) -lft

$(CLIENT) : $(OBJS_CLIENT) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $@ -L $(LIBFT_DIR) -lft

$(OBJS_CLIENT): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_SERVER): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A) : 
	make -C $(LIBFT_DIR)

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
