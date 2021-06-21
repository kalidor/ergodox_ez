#!/usr/bin/env bash
make ergodox_ez:kalidor
echo "Push reset button on Ergodox-EZ keyboard"
sleep 3
teensy_loader_cli -v -mmcu=atmega32u4 ergodox_ez_kalidor.hex

echo ""
echo "Remember to setxfrmap us intel to get azerty keyoard. Yeah, I know..."
