#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct custom_mutator {
    int seed;
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
    mutator->seed = seed;
    srand(seed);

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
 * @param[in] add_buf Buffer containing the additional test case
 * @param[in] add_buf_size Size of the additional test case
 * @param[in] max_size Maximum size of the mutated output. The mutation must not
 *     produce data larger than max_size.
 * @return Size of the mutated output.
 */
size_t afl_custom_fuzz(custom_mutator_t *data,  // afl state
                                  uint8_t *buf,
                                  size_t buf_size,    // input data to be mutated
                                  uint8_t **out_buf,  // output buffer
                                  uint8_t *add_buf,
                                  size_t add_buf_size,  // add_buf can be NULL
                                  size_t max_size)
{
    // This function can be named either "afl_custom_fuzz" or "afl_custom_mutator"
    // A simple test shows that "buf" will be the content of the current test case
    // "add_buf" will be the next test case ( from AFL++'s input queue )

    // Here we implement our own custom mutator

    int val = rand() % 255;

    memset(buf, val, buf_size);
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

