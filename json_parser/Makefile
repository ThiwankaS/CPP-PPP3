NAME	= json_parser

CMD		= g++

STD		= -std=c++20

WARN	= -Wall -Werror -Wextra

FLAGS	= $(WARN) $(STD) -O0 -g

SRCS	= \
	JSON.cpp\
	main.cpp

OBJS	= $(SRCS:.cpp=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CMD) $(FLAGS) $(OBJS) -o $@

%.o		: %.cpp
	$(CMD) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
