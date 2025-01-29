#include <iostream>

extern "C" int calc_next_char(std::string* source) {
    static thread_local size_t i = 0;
    if(!source) i = 0;
    if(i >= source->size()) 
        return EOF;
    return (*source)[i++];
}
#define PCC_GETCHAR(auxil) calc_next_char((std::string*)auxil)

#include "gen/calc.c"

int main() {
    std::string source = "5 + 6;";

    calc_context_t *ctx = calc_create(&source);
    while (calc_parse(ctx, NULL));
    calc_destroy(ctx);
    return 0;
}