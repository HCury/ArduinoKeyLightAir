@echo off
:: Replace COM3 with the port your Arduino is connected to
mode COM3 BAUD=9600 PARITY=N DATA=8 STOP=1

:: Send a '1' to turn on the LED
echo 2 > COM3
