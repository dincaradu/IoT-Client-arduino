# IoT Client Arduino

Example sketch built for ESP8266 board, with 2LEDs, and a 4-digit 7-segment display, with connection to server through WebSockets v2 and the ability to receive new sketches Over The Air.


## Functionalities

- You can upload a new sketch Over The Air
- Acts as a WiFi Access Point for setting up WiFi credentials through a webpage accessible at 10.1.1.1
- Connects to the WiFi network
- Connects through WebSockets and emits a keep_alive event to a server at 2-second intervals 
  (Please note that it uses WebSockets v2 and is not compatible with the more recent versions 3 or 4. Sample server code here: https://github.com/dincaradu/IoT-server-nestjs)
- Blinks yellow LED while connecting to the WiFi
- Fades in a green LED after it is connected to the WiFi
- Displays the last 3-digit segment of the local IP on the display


## Board, Sensors, and other attachments

- ESP8266WiFi
- Green LED
- Yellow LED
- 4 digits 7 segments display


## Other required components

- 6 x 150Ohm resistors
- 2 x Shift Registers 74HC595
- a bunch of wires :))

Hope it helps! Have fun!
