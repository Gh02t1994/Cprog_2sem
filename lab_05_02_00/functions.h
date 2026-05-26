#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include "const.h"
#include "codes.h"

int calc_avg(FILE *f, double *avg);

double search_nearest(FILE *f, double avg);

#endif
