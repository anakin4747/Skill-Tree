avr-gcc -Os -DF_CPU=1000000L -o blink blink.c -mmcu=attiny85
avr-objcopy -R .eeprom -O ihex blink blink.hex
