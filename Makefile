LIBS := -lglfw -lGL -lGLU -lXrandr

SRCS := \
	src/cg_main_glfw.c \
	src/cg_context.c

glfw:
	gcc $(SRCS) $(LIBS) -o CaptainGeek
