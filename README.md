Attiny13 based pwm dimmer with memory using Arduino libraries. 


Pin definitions can be found at the top of the file. Code expects a power button, plus button, and minus button for stepping between settings. It has a pwm output and status led output. It will keep the last setting and power state between power cycles in eeprom. Holding down power button when power is applied will clear the eeprom. 
