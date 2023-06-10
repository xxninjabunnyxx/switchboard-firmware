#include <stdio.h>
#include <stdlib.h>
#include "json_transformer.h"
#include "config_functions.h"

Configs  *create_config_table() {
        Configs *configs = malloc(sizeof(Configs));;

        for (int config_index = 0; config_index < NUMBER_OF_CONFIGS; config_index++) {
            for (int step_index = 0; step_index < NUMBER_OF_STEPS; step_index++) {
                for (int input_index = 0; input_index < NUMBER_OF_INPUTS_AND_OUTPUTS; input_index++) {
                    configs->config[config_index].steps[step_index].inputs[input_index].function = input_always_true;
                    configs->config[config_index].steps[step_index].inputs[input_index].value = 0;
                }

                for (int output_index = 0; output_index < NUMBER_OF_INPUTS_AND_OUTPUTS; output_index++) {
                    configs->config[config_index].steps[step_index].outputs[output_index].function = output_nothing;
                    configs->config[config_index].steps[step_index].outputs[output_index].value = 0;
                }
            }
        }
        
        return configs;
}

// create default layout

void *create_default_layout(Configs* config_struct) {
    for(int step_index = 0; step_index < NUMBER_OF_STEPS; step_index++) {
        for (int input_index = 0; input_index < NUMBER_OF_INPUTS_AND_OUTPUTS; input_index++) {
            config_struct->config[0].steps[step_index].inputs[input_index].function = input_always_true;
            config_struct->config[0].steps[step_index].inputs[input_index].value = 0;
        }

        for (int output_index = 0; output_index < NUMBER_OF_INPUTS_AND_OUTPUTS; output_index++) {
            config_struct->config[0].steps[step_index].outputs[output_index].function = output_nothing;
            config_struct->config[0].steps[step_index].outputs[output_index].value = 0;
        }
    }
}


Configs *json_transformer() {
    Configs *c = create_config_table();
    return c;
}