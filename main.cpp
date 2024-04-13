#include <iostream>
#include <bitset>

//the function inverts only even or odd bits, depending on the flag set
// (by default, inverted even bits are set)
void invert_bits (uint32_t* var, uint32_t len, bool even_flag = 1) {

    uint8_t mask;
    if (even_flag) mask = 0b01010101;
    else mask = 0b10101010;

    //Inverting occurs bitwise
    //With a variable length exceeding the size of the number,
    // the cycle repeatedly passed through the number
    // and returned it to its original state, therefore a restriction was set
    for(int a = 0; a < len && a < sizeof(*var); a++) {
        *var ^= (mask << (a << 3));
    }
}


int main() {
    uint32_t num = 0b11111111;
    std::cout << std::bitset<32>(num) << '\n';
    invert_bits(&num, 2, 0);
    std::cout << std::bitset<32>(num) << '\n';
    return 0;
}
