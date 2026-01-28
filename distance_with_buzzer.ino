const int trigPin = 11;           //connects to the trigger pin on the distance sensor
const int echoPin = 12;           //connects to the echo pin on the distance sensor

float distance = 0;               //stores the distance measured by the distance sensor

void setup()
{
  Serial.begin (9600);        //set up a serial connection with the computer
  pinMode(trigPin, OUTPUT);   //the trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);    //the echo pin will measure the duration of pulses coming back from the distance sensor
}

void loop() {
  distance = getDistance();   //variable to store the distance measured by the sensor
  Serial.print(distance);     //print the distance that was measured
  Serial.println(" in");      //print units after the distance

  if (distance <= 3) {                       //if the object is close(0-3 in) beep quickly
    tone(3,312,500);//the inbuilt tone function has 3 perimeters: (pin of buzzer, frequency, duration)

  } else if (3 < distance && distance < 6) { //if the object is a medium distance(3-6) in beep at medium pace
    tone(3,312,250);
    tone(3,312,250);

  } else if (6 < distance && distance < 12) {                                    //if the object is far away(6-12 in) beep slowly
    tone(3,312,100);
    tone(3,312,100);
    tone(3,312,100);
    tone(3,312,100);
    tone(3,312,100);
  } else {//for distances above 12 in no signal


  }


  delay(500);      //delay 50ms between each reading
}

//RETURNS THE DISTANCE MEASURED BY THE DISTANCE SENSOR
float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a signal to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time


  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)


  return calculatedDistance;              //send back the distance that was calculated
}


