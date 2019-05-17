#ifndef OTSMOLYAK_SMOLPACK_HXX
#define OTSMOLYAK_SMOLPACK_HXX

namespace OTSMOLPACK
{

# define maxdim 40

extern double int_smolyak(int, int, double(*ff)(int, double x[]), int);

} /* namespace OTSMOLPACK */

#endif /* OTSMOLYAK_SMOLPACK_HXX */
