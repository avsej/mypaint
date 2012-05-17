/* brushlib - The MyPaint Brush Library
 * Copyright (C) 2008 Martin Renold <martinxyz@gmx.ch>
 * Copyright (C) 2012 Jon Nordby <jononor@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "mypaint-surface.h"

int
mypaint_surface_draw_dab(MyPaintSurface *self,
                       float x, float y,
                       float radius,
                       float color_r, float color_g, float color_b,
                       float opaque, float hardness,
                       float alpha_eraser,
                       float aspect_ratio, float angle,
                       float lock_alpha,
                       float colorize
                       )
{
    assert(self->draw_dab);
    return self->draw_dab(self, x, y, radius, color_r, color_g, color_b,
                   opaque, hardness, alpha_eraser, aspect_ratio, angle, lock_alpha, colorize);
}


void
mypaint_surface_get_color(MyPaintSurface *self,
                        float x, float y,
                        float radius,
                        float * color_r, float * color_g, float * color_b, float * color_a
                        )
{
    assert(self->get_color);
    self->get_color(self, x, y, radius, color_r, color_g, color_b, color_a);
}

void
mypaint_surface_destroy(MyPaintSurface *self)
{
    assert(self->destroy);
    self->destroy(self);
}

float mypaint_surface_get_alpha (MyPaintSurface *self, float x, float y, float radius)
{
    float color_r, color_g, color_b, color_a;
    mypaint_surface_get_color (self, x, y, radius, &color_r, &color_g, &color_b, &color_a);
    return color_a;
}