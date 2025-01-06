/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gestion des touches du clavier.                                LINUX   */
/* ************************************************************************** */
#ifndef FT_MACROS_H
# define FT_MACROS_H

// Je recommande WIDTH plus de 1700, HEIGHT plus de 1200.
# define WIDTH			1700
# define HEIGHT			1200

// You have 0x424242 or 0xa6b1b3, this one is cool too.
# define BCKGRND_COLOR		0xa6b1b3

// Affiche le menu à une taille minimum.
# define MIN_MENU		500

// Couleur principale des lignes.
# define COLOR			0xffffff

// Change the color for menu, 0x7b8587 is good.
# define COLOR_HEADER		BCKGRND_COLOR
# define COLOR_MENU		0x2a2d2e

// For exiting and Reset.

# define MAIN_PAD_ESC		65307
# define KEY_R			114

// For the ZOOM.

# define NUM_PAD_PLUS		65451
# define MAIN_PAD_PLUS		61

# define NUM_PAD_MINUS		65453
# define MAIN_PAD_MINUS		41

// For the TRANSLATION.

# define ARROW_LEFT		65361
# define ARROW_RIGHT		65363
# define ARROW_DOWN		65364
# define ARROW_UP		65362

// For COHEN SUTHERLAND CLIP.

# define LEFT			1
# define RIGHT			2

// For ROTATION.

// alpha
# define NUM_PAD_1		65436
# define NUM_PAD_4		65430
# define MAIN_PAD_1		49
# define MAIN_PAD_2		50

// beta
# define NUM_PAD_2		65433
# define NUM_PAD_5		65437
# define MAIN_PAD_3		51
# define MAIN_PAD_4		52

// gamma
# define NUM_PAD_3		65435
# define NUM_PAD_6		65432
# define MAIN_PAD_5		53
# define MAIN_PAD_6		54

// For PROJECTION.

# define KEY_I			105

// For HEIGHT.

# define NUM_PAD_8		65431
# define NUM_PAD_9		65434
# define MAIN_PAD_8		56
# define MAIN_PAD_9		57

// For SPLIT.

# define SEP			" \n\t"

#endif
