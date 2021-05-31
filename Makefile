CC=clang
AFL-CC=afl-clang

libafl_custom_postprocessor: custom_postprocessor.c
	$(CC) custom_postprocessor.c -g -shared -fPIC -o libafl_custom_postprocessor.so

libafl_custom_mutator: custom_mutator.c
	$(CC) custom_mutator.c -g -shared -fPIC -o libafl_custom_mutator.so

example: example.c
	$(AFL-CC) example.c -g -o example


all: libafl_custom_mutator libafl_custom_postprocessor
