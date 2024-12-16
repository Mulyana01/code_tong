#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
Servo myservo;
#define trigPin 9
#define echoPin 10
long duration;
int distance = 0;
int pos = 0;
void setup()
{
    myservo.attach(6);
    pinMode(trigPin, OUTPUT); // setting triggerpin sebagai output
    pinMode(echoPin, INPUT);  // setting echopin sebagai Input
    Serial.begin(9600);    // setting kecepatan pengiriman serial monitor
}
void loop()
{
    digitalWrite(trigPin, HIGH);       // aktifkan sensor ultrasonic
    delayMicroseconds(10);             // selama 10 microseconds
    digitalWrite(trigPin, LOW);        // matikan sensor ultrasonic
    duration = pulseIn(echoPin, HIGH); // baca rentan waktu dari trigPin High sampai echoPin high
    distance = duration * 0.034 / 2;   // konversi selang waktu ke CM

    if (distance < 10) // Hanya menampilkan jarak jika jaraknya kurang dari 300 cm / 3 meter
    {
        Serial.println(distance); // kirim data jarak ke PC
        myservo.write(140);
        delay(3000);
    }

    else
    {
        myservo.write(0);
    }
}