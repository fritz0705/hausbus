#include <stdint.h>

extern const unsigned long F_CPU;
extern const unsigned long BAUD;

extern volatile uint8_t *const DDR_RGB;
extern volatile uint8_t *const PORT_RGB;
extern const uint8_t PIN_RED;
extern const uint8_t PIN_BLUE;
extern const uint8_t PIN_GREEN;

extern volatile uint8_t *const DDR_STATUS;
extern volatile uint8_t *const PORT_STATUS;
extern const uint8_t PIN_STATUS;
