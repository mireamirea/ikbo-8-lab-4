#include <stdio.h>
#include <stdlib.h>
#include "fann.h"
#include "floatfann.c"

int main(int argc, char *argv[])
{
    fann_type *calc_out;
    fann_type input[3];
    struct fann *ann = fann_create_from_file("input.net");
    if (!ann) printf("error");
    else
    {
    input[0] = atoi(argv[1]);
    input[1] = atoi(argv[2]);
    input[2] = atoi(argv[3]);
    calc_out = fann_run(ann, input);
    if (calc_out[0] < 0) calc_out[0] = calc_out[0] * (-1);
    printf("%0.f\n", calc_out[0]);
    fann_destroy(ann);
    }
    return 0;
}
