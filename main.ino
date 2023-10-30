//SQUID GAME RED LIGHT GREEN LIGHT USING ARDUINO UNO R3 AND ULTRA SONIC SENSOR.

#define trigPin 12  //for ultrasonic
#define echoPin 13  //for ultrasonic

int rled=10;  //for red led
int gled=11;  //for green led
int buzzer=9; //for buzzer
void setup() 
{
  // setup code here run once:
  pinMode(echoPin,INPUT);   //recieves signal
  pinMode(trigPin,OUTPUT);  //sends signal
  pinMode(rled,OUTPUT);     //for visual puropose of red light
  pinMode(gled,OUTPUT);     //for visual purpose of green ligth
  pinMode(buzzer,OUTPUT);   //output of buzzer is required when someone moves during red light
  Serial.begin(9600);       //starts serial communication, value 9600 is called 'baud rate/ of connection.
}

void loop()
{
  //main code here run repeatedly
  int rrn,grn,time,duration,distance,temp,progress,i;
  /*RRN for random delay of red light,GRN for green random dealy ,TIME to print distance& every seconds,
  DURATION to measure distance, TEMP to check if something moves during red light,PROGRESS to measure progress in percentage.*/
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("DISTANCE: ");
    Serial.println(distance);
    delay(10);
   for(i=0;i<1;i--)
   {
    if (distance>=30)
    {
      digitalWrite(buzzer,LOW);
      break;
    }
    else 
    {
      break;
    }
   }
  rrn=random(1000,10000);//gets random number between  1 and 10 second.
  Serial.print("RANDOM NUMBER:");       
  Serial.println(rrn);
  digitalWrite(gled,HIGH);  
  Serial.println("GREEN LED ON");
  
  //below for loop is in use to measure distance every second while time is less than delay of red random number.
    for(time=0;time<rrn;time=time+1000) 
    {
    
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("DISTANCE: ");
    Serial.println(distance);
    if(distance<5)
    Serial.println("WINNER" );
    delay(1000);//delay of 1 second.
    }
    delay(1000);
    digitalWrite(gled,LOW);
  Serial.println("GREEN led off:");
  
  //distance is assigned to temp variable so we can save distance after green light.
  temp=distance;
  Serial.print("Temp:");
  Serial.println(temp);
  
 //gets random delay number between 1 to 10 for green led light
  grn=random(1000,10000);
  Serial.print("random number");
  Serial.println(grn);

  //RED LED GETS TURN ON FROM HERE
  digitalWrite(rled,HIGH);
  Serial.println("RED LED ON");
  
  //for loop to measure distance every second while time is less than random green number.
    for(time=0;time<grn;time=time+1000)
    {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("DISTANCE: ");
    Serial.println(distance);
    /*below if statement check if distance after green light equal to currunt distance. if there is change in distance
        it will blow the buzzzer ending the trial.*/
      if(distance!=temp)
      {
       digitalWrite(buzzer,HIGH);
       Serial.println("GAME OVER");
      }
    delay(1000);
    }
   Serial.println("RED LED OFF:");
   digitalWrite(rled,LOW);
}
