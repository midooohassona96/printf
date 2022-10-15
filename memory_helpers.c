#include "main.h"

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);

void free_buffer(buffer_t *output);

buffer_t *init_buffer(void);

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)

{

unsigned int index;

for (index = 0; index < n; index++)

{

*(output->buffer) = *(src + index);

(output->len)++;

if (output->len == 1024)

{

write(1, output->start, output->len);

output->buffer = output->start;

output->len = 0;

}

else

(output->buffer)++;

}

return (n);

}

void free_buffer(buffer_t *output)

{

free(output->start);

free(output);

}

buffer_t *init_buffer(void)

{

buffer_t *output;

output = malloc(sizeof(buffer_t));

if (output == NULL)

return (NULL);

output->buffer = malloc(sizeof(char) * 1024);

if (output->buffer == NULL)

{

free(output);

return (NULL);

}

output->start = output->buffer;

output->len = 0;

return (output);

}
