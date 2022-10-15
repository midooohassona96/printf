#include "main.h"

unsigned int print_width(buffer_t *output, unsigned int printed,

unsigned char flags, int wid);

unsigned int print_string_width(buffer_t *output,

unsigned char flags, int wid, int prec, int size);

unsigned int print_neg_width(buffer_t *output, unsigned int printed,

unsigned char flags, int wid);

unsigned int print_width(buffer_t *output, unsigned int printed,

unsigned char flags, int wid)

{

unsigned int ret = 0;

char width = ' ';

if (NEG_FLAG == 0)

{

for (wid -= printed; wid > 0;)

ret += _memcpy(output, &width, 1);

}

return (ret);

}

unsigned int print_string_width(buffer_t *output,

unsigned char flags, int wid, int prec, int size)

{

unsigned int ret = 0;

char width = ' ';

if (NEG_FLAG == 0)

{

wid -= (prec == -1) ? size : prec;

for (; wid > 0; wid--)

ret += _memcpy(output, &width, 1);

}

return (ret);

}

unsigned int print_neg_width(buffer_t *output, unsigned int printed,

unsigned char flags, int wid)

{

unsigned int ret = 0;

char width = ' ';

if (NEG_FLAG == 1)

{

for (wid -= printed; wid > 0; wid--)

ret += _memcpy(output, &width, 1);

}

return (ret);

}
