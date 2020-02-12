# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 10:49:29 by cochapel          #+#    #+#              #
#    Updated: 2020/01/28 15:13:59 by cochapel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	ft_minirt.c \
						ft_data_to_screen.c \
						ft_camera.c \
						ft_save.c \
						error/ft_error.c \
						error/ft_error1.c \
						error/ft_error2.c \
						error/ft_error3.c \
						error/ft_error4.c \
						error/ft_error5.c \
						error/ft_error6.c \
						error/ft_error7.c \
						error/ft_error8.c \
						error/ft_error9.c \
						error/ft_utils.c \
						fonctions/ft_free.c \
						fonctions/ft_vector.c \
						fonctions/ft_vector2.c \
						fonctions/ft_vector3.c \
						fonctions/ft_other.c \
						fonctions/ft_color.c \
						lights/ft_light_shapes.c \
						lights/ft_set_lights.c \
						lights/ft_light_norm.c \
						lights/ft_light_norm2.c \
						read_scene/ft_read.c \
						read_scene/ft_fonctions.c \
						read_scene/ft_read_fcts.c \
						read_scene/ft_read_fcts2.c \
						read_scene/ft_read_fcts3.c \
						read_scene/ft_add.c \
						read_scene/ft_add2.c \
						shapes/ft_set_shapes.c \
						shapes/ft_plane.c \
						shapes/ft_sphere.c \
						shapes/ft_square.c \
						shapes/ft_square2.c \
						shapes/ft_triangle.c \
						shapes/ft_triangle2.c \
						shapes/ft_cyl.c \
						shapes/ft_cyl2.c \
						

OBJS				= ${SRCS:.c=.o}

NAME				= miniRT.out

FLAGS				= -Wall -Wextra -Werror

FRAMEWORKS			= -framework OpenGl -framework AppKit

MLX					=  minilibx/libmlx.a

LIBFT				= libft/libft.a

all :				${NAME}

${NAME} :			minilibx_all libft_all ${OBJS}
					mkdir -p saved_pictures
					gcc -o miniRT.out ${FLAGS} ${FRAMEWORKS} ${MLX} ${LIBFT} ${SRCS}

clean :				libft_clean minilibx_clean
					rm -rf ${OBJS}

fclean :			libft_fclean minilibx_clean clean
					rm -rf ${NAME} saved_pictures

re :				fclean all

libft_all :	
					make -C libft all
				
libft_clean :	
					make -C libft clean

libft_fclean :	
					make -C libft fclean

minilibx_all :
					make -C minilibx all

minilibx_clean :
					make -C minilibx clean


.PHONY:				all clean fclean re
