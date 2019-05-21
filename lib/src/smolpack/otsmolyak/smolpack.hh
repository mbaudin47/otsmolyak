#ifndef OTSMOLYAK_SMOLPACK_HXX
#define OTSMOLYAK_SMOLPACK_HXX

# define maxdim 40

extern double int_smolyak(int, int, double(*ff)(int, double *x, void *state), int, void *state);

#endif /* OTSMOLYAK_SMOLPACK_HXX */
