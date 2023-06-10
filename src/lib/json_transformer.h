#ifndef JSON_TRANSFORMER_H
#define JSON_TRANSFORMER_H
#include <stdint.h>
#include <stdbool.h>

#define NUMBER_OF_CONFIGS 9
#define NUMBER_OF_STEPS 10
#define NUMBER_OF_INPUTS_AND_OUTPUTS 10

typedef bool (*InputFunction)(int);
typedef void (*OutputFunction)(int);

typedef struct {
    InputFunction function;
    int value;
} Input;

typedef struct {
    OutputFunction function;
    int value;
} Output;

typedef struct {
    Input inputs[NUMBER_OF_INPUTS_AND_OUTPUTS];
    Output outputs[NUMBER_OF_INPUTS_AND_OUTPUTS];
} Steps;

typedef struct {
    Steps steps[NUMBER_OF_STEPS];
} Config;

typedef struct {
    Config config[NUMBER_OF_CONFIGS];
} Configs;

Configs *json_transformer();

#endif /* HEADER_FILE_H */