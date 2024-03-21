#include <ESP8266WiFi.h>

//here you have to insert your desired credentials
const char* ssid = "***";
const char* password = "***";

const int WorkingLED = D1;
const int SuccessLED = D2;

const int dataPin = D8;
const int latchPin = D7;
const int clockPin = D6;

//create byte variables that have only one segment set to HIGH
// byte a = B00000001;
// byte b = B00000010;
// byte c = B00000100;
// byte d = B00001000;
// byte e = B00010000;
// byte f = B00100000;
// byte g = B01000000;
// byte dot = B10000000;

String lastSegment;

String getLastIPAddressSegment(IPAddress ip) {
  String ipString = ip.toString();
  int lastDotIndex = ipString.lastIndexOf('.');

  return ipString.substring(lastDotIndex + 1);
}

int slotNumber[5] = {14, 13, 11, 7, 0};
int digits[10] = {191, 134, 219, 207, 230, 237, 253, 135, 255, 239};
int digitsNoDot[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

void showOnDisplay(String segment) {
  int segmentLength = segment.length();
  for (int positionOfCharinSegment = 0; positionOfCharinSegment < segmentLength; positionOfCharinSegment++) {
    byte positionOnDisplay = 0;
    int character = segment.substring(positionOfCharinSegment, positionOfCharinSegment + 1).toInt(); // Convert char to integer
    bool showDot = (positionOfCharinSegment == segmentLength - 1); // Show dot for last character

    if (positionOfCharinSegment >= 0 && positionOfCharinSegment <= 4) {
      positionOnDisplay = slotNumber[positionOfCharinSegment];
    }

    if (character >= 0 && character <= 9) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, MSBFIRST, positionOnDisplay);
      shiftOut(dataPin, clockPin, MSBFIRST, (showDot ? digits : digitsNoDot) [character]);
      digitalWrite(latchPin, 1);
    }
  }
}

void fadeInLED(int LED) {
  for (int fade = 0; fade < 1024; fade++) {
    analogWrite(LED, fade);
    delay(1);
  }
}

void fadeOutLED(int LED) {
  for (int fade = 1023; fade >= 0; fade--) {
    analogWrite(LED, fade);
    delay(1);
  }
}

void blinkLED(int LED) {
  fadeInLED(LED);
  fadeOutLED(LED);
}

void connectToWiFi() {
  Serial.println("Connecting to the WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Waiting for connection");
  while (WiFi.status() != WL_CONNECTED) {
    blinkLED(WorkingLED);
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  fadeInLED(SuccessLED);

  lastSegment = getLastIPAddressSegment(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  
  pinMode(WorkingLED, OUTPUT);
  pinMode(SuccessLED, OUTPUT);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  delay(1000);
  
  connectToWiFi();
}

void loop() {
  showOnDisplay(lastSegment);
}
