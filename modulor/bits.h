#define bit_set(byte, bit) do{ (byte) |= (uint8_t)(1 << bit); }while(0)
#define bit_clear(byte, bit) do{ (byte) &= (uint8_t)~(1 << bit); }while(0)
#define bit_flip(byte, bit) do{ (byte) ^= (uint8_t)(1 << bit); }while(0)
