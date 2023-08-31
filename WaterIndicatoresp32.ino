// // /*************************************************************

// //   This sketch shows how to write values to Virtual Pins

// //   NOTE:
// //   BlynkTimer provides SimpleTimer functionality:
// //     http://playground.arduino.cc/Code/SimpleTimer

// //   App dashboard setup:
// //     Value Display widget attached to Virtual Pin V5
// //  *************************************************************/

// // /* Fill-in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID           "TMPL3_BG4wTfm"
// #define BLYNK_TEMPLATE_NAME         "water"
// #define BLYNK_AUTH_TOKEN            "GUygV_nlV9SQYhtYVIRpNnFcma9d4yfQ"

// // // /* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial




// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>

// // // Your WiFi credentials.
// // // Set password to "" for open networks.
// char ssid[] = "iotdata";
// char pass[] = "12345678";
// int tankdepth = 20;

// BlynkTimer timer;

// void waterlevel(){
//   digitalWrite(trig, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trig, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trig, LOW);
//   long t = pulseIn(echo, HIGH);
//   long cm = t / 29 / 2;
//   Serial.println(cm);
//   long level=tankdepth-cm;
//   if(level < 0)
//   level=0;
//   level=map(level,0,tankdepth-3,0,100);
//   // Serial.println(level);
//   // Blynk.virtualWrite(V0, level);
// }


// // // This function sends Arduino's up time every second to Virtual Pin (5).
// // // In the app, Widget's reading frequency should be set to PUSH. This means
// // // that you define how often to send data to Blynk App.
// // // void myTimerEvent()
// // // {
// // //   // You can send any value at any time.
// // //   // Please don't send more that 10 values per second.
// // //   Blynk.virtualWrite(V5, millis() / 1000);
// // // }

// #define trig D2
// #define echo D0

// #include <ESP8266WiFi.h>

// char ssid[] = "iotdata";
// char pass[] = "12345678";
// int tankdepth = 20;

// void setup() {
//   pinMode(trig, OUTPUT);
//   pinMode(echo, INPUT);
//   Serial.begin(115200);
// }

// void loop() {
//   digitalWrite(trig, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trig, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trig, LOW);
  
//   long t = pulseIn(echo, HIGH);
//   Serial.print(t);
//   long cm = t / 29 / 2;
  
//   Serial.println(cm);
  
//   long level = tankdepth - cm;
//   if (level < 0)
//     level = 0;
//   level = map(level, 0, tankdepth - 3, 0, 100);
  
//   Serial.println("Water Level: " + String(level) + "%");
  
//   delay(1000); // Delay to control the rate of serial output
// }

// #define trigPin D0
// #define echoPin D2

// void setup() {
//   Serial.begin(115200);
//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
// }

// void loop() {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   long duration = pulseIn(echoPin, HIGH);
//   long distance = (duration * 0.0343) / 2; // Calculate distance in centimeters

//   Serial.print("Duration: ");
//   Serial.print(duration);
//   Serial.print(" microseconds, Distance: ");
//   Serial.print(distance);
//   Serial.println(" cm");

//   delay(1000);
// }

// void setup() {
//   Serial.begin(9600);

//   // Test digital pins from D0 to D13
//   for (int pin = 0; pin <= 13; pin++) {
//     pinMode(pin, OUTPUT);
//     digitalWrite(pin, HIGH);
//     delay(500);
//     digitalWrite(pin, LOW);
//     delay(500);
//     Serial.println("All good");
//   }


// }

// void loop() {
//   // Nothing to do in loop
// }

// int trig=7;

// int echo=6;
// long duration;
// long distance;

// void setup(){
// Serial.begin(9600);
// pinMode(7,OUTPUT);
// pinMode(6,INPUT);

// }

// void loop(){
//   digitalWrite(trig, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trig, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trig, LOW);

//   duration = pulseIn(echo, HIGH);
//   distance = duration /29 /2;// Calculate distance in centimeters

//   Serial.print("Duration: ");
//   Serial.print(duration);
//   delay(1000);
//   Serial.print(" microseconds, Distance: ");
//   Serial.print(distance);
//   Serial.println(" cm"); 
// }

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3_BG4wTfm"
#define BLYNK_TEMPLATE_NAME "water"
#define BLYNK_AUTH_TOKEN "MscLBAb7Wo5Y0ON6ddLt2f1PDdXuYTxT"

// /* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
 #include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Airsky_5Ghz";
char pass[] = "Baski@2020";
char auth[] = "MscLBAb7Wo5Y0ON6ddLt2f1PDdXuYTxT";
int tankdepth = 22;

#define trig 13
#define echo 14

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void waterlevel(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  long level=tankdepth-cm;
  if(level < 0)
  level=0;
  level=map(level,0,tankdepth-3,0,100);
  Serial.println(level);
  Blynk.virtualWrite(V0, level);
}


void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, waterlevel);
}

void loop()
{

  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}


