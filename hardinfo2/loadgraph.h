/*
 * Simple Load Graph
 * Copyright (C) 2006 Leandro A. F. Pereira <leandro@linuxmag.com.br>
 *
 * The Simple Load Graph is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License, version 2.1, as published by the Free Software Foundation.
 *
 * The Simple Load Graph is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the Simple Load Graph; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307 USA. 
 */


#ifndef __LOADGRAPH_H__
#define __LOADGRAPH_H__

#include <stdlib.h>
#include <gtk/gtk.h>
#include <math.h>

typedef struct _LoadGraph LoadGraph;

typedef enum {
    LG_COLOR_GREEN = 0x4FB05A,
    LG_COLOR_BLUE  = 0x4F58B0,
    LG_COLOR_RED   = 0xB04F4F
} LoadGraphColor;

struct _LoadGraph {
    GdkPixmap     *buf;
    GtkWidget     *area;

    GdkGC         *grid;
    GdkGC         *trace;

    gint     	  *data;
    gfloat         scale;

    gint	   size;
    gint	   width, height;
    LoadGraphColor color;    
    
    gint	   max_value;
};

LoadGraph 	*load_graph_new(gint size);
void 		 load_graph_destroy(LoadGraph *lg);
void		 load_graph_configure_expose(LoadGraph *lg);
GtkWidget 	*load_graph_get_framed(LoadGraph *lg);

void		 load_graph_update(LoadGraph *lg, gint value);
void		 load_graph_set_max(LoadGraph *lg, gint value);
int		 load_graph_get_max(LoadGraph *lg);
void		 load_graph_set_color(LoadGraph *lg, LoadGraphColor color);
void		 load_graph_clear(LoadGraph *lg);

#endif	/* __LOADGRAPH_H__ */
