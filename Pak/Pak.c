#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fann.h"

int q;
char answer[255];
void train(char *, char *);

int main(int argc, char* argv[])
{
	if (argc < 4)
		return 1;

	if (fopen("classify.net", "r") == NULL)
        {
		printf("We did not find train file\nDo you want to train?\n");
		printf("filename or 'no'\n");
		scanf("%s", answer);
		if (strcmp(answer, "no") != 0)
			train(answer, "classify.net");
		return 0;
        }

 	struct fann *x = fann_create_from_file("classify.net");
	float input[3];
	for (q = 1; q <= 3; q++)
		input[q-1] = (float) *argv[q]-'0';

 	float *output = fann_run(x, input);
	printf("%.lf\n", *output);

 	return 0;
}

void train(char *fromwhere, char *towhere) {
	struct fann *x = fann_create_standard(4, 6, 2);
	fann_train_on_file(x, fromwhere, 200, 1, 0.01);
	fann_save(x, towhere);
	printf("Well done! The end!\n");
	fann_destroy(x);
}
