/*
Copyright (C) 2014 Jerome Revaud

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "std.h"
//#include <jpeglib.h>
//#include <png.h>
#include <setjmp.h>
#include "io.h"


void output_correspondences( const char* out_filename, const corres_t* corres, int nb, float fx, float fy ) 
{
  //assert(0<fx && fx<=2);
  //assert(0<fy && fy<=2);
  FILE* f = out_filename ? fopen(out_filename,"w") : stdout;
  for(int i=0; i<nb; i++) {
    const corres_t* r = corres + i; // one row
    fprintf(f, "%g %g %g %g %g %g\n",fx*r->x0,fy*r->y0,fx*r->x1,fy*r->y1,r->maxima,r->score);
  }
  if(out_filename)
    fclose(f);
}
