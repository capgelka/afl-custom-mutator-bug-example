#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct custom_mutator {
} custom_mutator_t;

/**
 * Initialize this custom mutator
 *
 * @param[in] afl a pointer to the internal state object. Can be ignored for
 * now.
 * @param[in] seed A seed for this mutator - the same seed should always mutate
 * in the same way.
 * @return Pointer to the data object this custom mutator instance should use.
 *         There may be multiple instances of this mutator in one afl-fuzz run!
 *         Return NULL on error.
 */
custom_mutator_t *afl_custom_init(void *afl, unsigned int seed)
{
    custom_mutator_t* mutator = (custom_mutator_t*) malloc(sizeof(custom_mutator_t));
    return mutator;
}

/**
 * Perform custom mutations on a given input
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param[in] buf Pointer to input data to be mutated
 * @param[in] buf_size Size of input data
 * @param[out] out_buf the buffer we will work on. we can reuse *buf. NULL on
 * error.
 * @return Size of the mutated output.
 */
size_t afl_custom_post_process(custom_mutator_t *data, 
                               unsigned char *buf,
                               size_t buf_size,
                               unsigned char **out_buf)

{

    for (int i = 0; i < buf_size; i++) {
        if (buf[i] > 127) {
            buf[i] -= 127;
        }
    }
    *out_buf = buf;
    return buf_size;
}

/**
 * Deinitialize everything
 *
 * @param data The data ptr from afl_custom_init
 */
void afl_custom_deinit(custom_mutator_t *data)
{
    free(data);
    return;
}

