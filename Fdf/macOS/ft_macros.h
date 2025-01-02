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
#ifndef FT_MACROS_H
# define FT_MACROS_H

// Default Mac Air M2: 1470 x 956; Large resolution: 1710 x 1112.
// Je recommande WIDTH plus de 1100, HEIGHT plus de 700.
# define WIDTH			1470
# define HEIGHT			956

// You have 0x424242 or 0xa6b1b3, this one is cool too.
# define BCKGRND_COLOR		0xa6b1b3

// Affiche le menu a une taille minimum.
# define MIN_MENU		500

// Couleur principale des lignes.
# define COLOR			0xffffff

// Change the color for menu, 0x7b8587 is good.
# define COLOR_HEADER		BCKGRND_COLOR
# define COLOR_MENU		0x2a2d2e

// For exiting.

# define MAIN_PAD_ESC		53

// For the ZOOM.

# define NUM_PAD_PLUS		69
# define MAIN_PAD_PLUS		24

# define NUM_PAD_MINUS		78
# define MAIN_PAD_MINUS		27

// For the TRANSLATION.

# define ARROW_LEFT		123
# define ARROW_RIGHT		124
# define ARROW_DOWN		125
# define ARROW_UP		126

// For Cohen SutherLand Clip.

# define LEFT			1
# define RIGHT			2

// For Rotation.

// alpha
# define NUM_PAD_1		83
# define NUM_PAD_4		86
# define MAIN_PAD_1		18
# define MAIN_PAD_2		19

// beta
# define NUM_PAD_2		84
# define NUM_PAD_5		87
# define MAIN_PAD_3		20
# define MAIN_PAD_4		21

// gamma
# define NUM_PAD_3		85
# define NUM_PAD_6		88
# define MAIN_PAD_5		23
# define MAIN_PAD_6		22

// For Projection.

# define KEY_R			15

// For Height.

# define MAIN_PAD_8		28
# define MAIN_PAD_9		25
# define NUM_PAD_8		91
# define NUM_PAD_9		92

// For split.

# define SEP			" \n"

#endif
