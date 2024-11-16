
compile: compile_libs compile_fdf reset_libs

fast_run: compile_libs compile_fdf reset_libs
	@./fdf

full_run: update_libs compile_libs compile_fdf reset_libs
	@./fdf

compile_fdf:
	@cc srcs/*.c \
	-I./includes \
	\
	-I./libs/libft \
	-I./libs/get_next_line \
	-I./libs/minilibx-linux \
	\
	libs/libft/libft.a \
	libs/get_next_line/get_next_line.a \
	\
	-L./libs/minilibx-linux \
	-lmlx -lX11 -lXext -lm -o fdf

compile_libs:
	@make -sC libs/libft
	@make -sC libs/get_next_line
	@make -sC libs/minilibx-linux
	@make clean -sC libs/libft
	@make clean -sC libs/get_next_line

valgrind: compile
	valgrind ./fdf

update_libs:
	@git submodule update --init --recursive --remote

reset_libs:
	@cd libs/get_next_line && rm -f *.a
	@cd libs/libft && rm -f *.a


git_push: update_libs
	@git add .
	@read -p "Enter commit message: " message; \
    git commit -m "$$message"
	@git push
