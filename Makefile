LIBS := -lglfw -lGL -lGLU -lXrandr

SRCS := \
	src/cg_main_glfw.c \
	src/cg_context.c \
	src/cg_pair.c

glfw:
	gcc $(SRCS) $(LIBS) -o CaptainGeek
