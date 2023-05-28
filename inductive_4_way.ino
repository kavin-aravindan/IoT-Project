// Ultrasonic sensor libraries
// #include <NewPing.h>

#include <Servo.h>

int type; // Type of circuit 
// 1 - 4 junction with 4 ultrasonic sensors
// 0 - 3 junction with 3 ultrasonic sensors


const int inductivePin_1 = 2;  // Pin connected to the inductive sensor
const int inductivePin_2 = 4;  // Pin connected to the inductive sensor
const int inductivePin_3 = 12;  // Pin connected to the inductive sensor
const int inductivePin_4 = 14;  // Pin connected to the inductive sensor


// Constants (won't change)

const int led_red_1 = 22;
const int led_red_2 = 23;
const int led_red_3 = 35;
const int led_red_4 = 15;

const int led_green_1 = 21;
const int led_green_2 = 27;
const int led_green_3 = 34;
const int led_green_4 = 19;


const int servoPin = 13;  // Pin connected to the servo motor

Servo servo;  // Create a servo object

// const unsigned int maxDistance = 200;  // Maximum distance to measure (in centimeters)

// Object instances for ultrasonic sensors
// NewPing sonar1(trigPin1, echoPin1, maxDistance);
// NewPing sonar2(trigPin2, echoPin2, maxDistance);
// NewPing sonar3(trigPin3, echoPin3, maxDistance);
// NewPing sonar4(trigPin4, echoPin4, maxDistance);

// Variables (will change)
// unsigned long currentMillis = 0;   // Current time in milliseconds
// unsigned long previousMillis = 0;  // Previous time for reading sensors

// int is_1_red= 0;
// int is_2_red= 0;
// int is_3_red= 0;
// int is_4_red= 0;

// int red_count_1= 0;
// int red_count_2= 0;
// int red_count_3= 0;
// int red_count_4= 0;

// int green_count_1= 0;
// int green_count_2= 0;
// int green_count_3= 0;
// int green_count_4= 0;



int count_arr[4];  //count the number of cars per road
int signal[4];  // 1 for green and 0 for red
int Timer[4];   // 0 for red and time remaining in millisecs for the green light
int light_index;
int multiplier;
int delay_per_read;
int threshold_time;
int flag_max_hit;
int servoPosition = 0;  // Initial position of the servo motor


void setup() {
  Serial.begin(9600);

  pinMode(led_red_1,OUTPUT);
  pinMode(led_red_2,OUTPUT);
  pinMode(led_red_3,OUTPUT);
  pinMode(led_red_4,OUTPUT);

  pinMode(led_green_1,OUTPUT);
  pinMode(led_green_2,OUTPUT);
  pinMode(led_green_3,OUTPUT);
  pinMode(led_green_4,OUTPUT);

  
  light_index = 0;
  for(int i = 1;i<4;i++)
  {Timer[i] = 0;}
  for(int i = 1;i<4;i++) 
  {signal[i] = 0;}
  for(int i =0;i<4;i++) 
  {count_arr[i] = 0;}
  Timer[light_index] = 5000;
  signal[light_index] = 1;
  multiplier = 1250;
  delay_per_read=250;
  threshold_time=30000;
  flag_max_hit=0;
  type=0;


  servo.attach(servoPin);  // Attach the servo to the specified pin
  servo.write(servoPosition);  // Set the initial position of the servo motor

}

void loop() {

int max_cars=threshold_time/multiplier;  
  // currentMillis = millis();
  // read1();
  // read2();
  // read3();
  // read4();
  // red_count_1+= green_count_1;
  // green_count_1=0;

  // red_count_2+= green_count_2;
  // green_count_2=0;
  
  // red_count_3+= green_count_3;
  // green_count_3=0;

  // red_count_4+= green_count_4;
  // green_count_4=0;



   signal[light_index] = 1;


   if(light_index==0)
   {
   digitalWrite(led_red_1,LOW);
   digitalWrite(led_red_2,HIGH);
   digitalWrite(led_red_3,HIGH);
   digitalWrite(led_red_4,HIGH);

   digitalWrite(led_green_1,HIGH);
   digitalWrite(led_green_2,LOW);
   digitalWrite(led_green_3,LOW);
   digitalWrite(led_green_4,LOW);

   }
   else if(light_index==1)
   {
   digitalWrite(led_red_2,LOW);
   digitalWrite(led_red_1,HIGH);
   digitalWrite(led_red_3,HIGH);
   digitalWrite(led_red_4,HIGH);

   digitalWrite(led_green_2,HIGH);
   digitalWrite(led_green_1,LOW);
   digitalWrite(led_green_3,LOW);
   digitalWrite(led_green_4,LOW);
   }
   else if(light_index==2)
   {
   digitalWrite(led_red_3,LOW);
   digitalWrite(led_red_2,HIGH);
   digitalWrite(led_red_1,HIGH);
   digitalWrite(led_red_4,HIGH);

   digitalWrite(led_green_3,HIGH);
   digitalWrite(led_green_2,LOW);
   digitalWrite(led_green_1,LOW);
   digitalWrite(led_green_4,LOW);
   }
   else if(type==1 && light_index==3)
   {
   digitalWrite(led_red_4,LOW);
   digitalWrite(led_red_2,HIGH);
   digitalWrite(led_red_3,HIGH);
   digitalWrite(led_red_1,HIGH);

   digitalWrite(led_green_4,HIGH);
   digitalWrite(led_green_2,LOW);
   digitalWrite(led_green_3,LOW);
   digitalWrite(led_green_1,LOW);
   }
   



if (light_index == 0 && signal[light_index] == 0) {
    // Rotate the servo motor to a specific position
    servoPosition = 180;  // Set the desired position (e.g., 180 degrees)
    servo.write(servoPosition);  // Rotate the servo motor to the specified position
  }
     

  // LED green triger
  if(flag_max_hit<max_cars && count_arr[light_index] > 0 && count_arr[light_index] <= max_cars){ 
      Timer[light_index] += (multiplier * count_arr[light_index]);
      flag_max_hit+=count_arr[light_index];
      count_arr[light_index] = 0;
      }
  else if(flag_max_hit<max_cars && count_arr[light_index] > max_cars ){
    Timer[light_index] += multiplier*max_cars;
    flag_max_hit+=count_arr[light_index];
    count_arr[light_index] -= max_cars;
  }

  Timer[light_index] -= 1;

  count_arr[0] +=read1();
  
  count_arr[1] +=read2();

  count_arr[2] +=read3();

  if(type==1)
  count_arr[3] +=read4();

  Serial.println("Count arr:-");

  Serial.println(count_arr[0]);
  Serial.println(count_arr[1]);
  Serial.println(count_arr[2]);
  if(type==1)
  Serial.println(count_arr[3]);
  Serial.println();

  Serial.println("Timer:-");

  Serial.println(Timer[0]);
  Serial.println(Timer[1]);
  Serial.println(Timer[2]);
  if(type==1)
  Serial.println(Timer[3]);
  Serial.println();


if (light_index != 0 || signal[light_index] != 0) {
    // Reset the servo motor position
    servoPosition = 0;  // Set the initial position (e.g., 0 degrees)
    servo.write(servoPosition);  // Rotate the servo motor to the specified position
  }  



  if(Timer[light_index] == 0 || Timer[light_index] < 0)
  {
    signal[light_index] = 0;
    //LED Red triger 
    Timer[light_index]=0;
    flag_max_hit=0;
    if(light_index==0)
    {
    digitalWrite(led_green_1,LOW);
    digitalWrite(led_red_1,HIGH);
    }
    else if(light_index==1)
    {
    digitalWrite(led_green_2,LOW);
    digitalWrite(led_red_2,HIGH);
    }
    else if(light_index==2)
    {
    digitalWrite(led_green_3,LOW);
    digitalWrite(led_red_3,HIGH);
    }
    else if(light_index==3)
    {
    digitalWrite(led_green_4,LOW);
    digitalWrite(led_red_4,HIGH);
    }
  if(type==1)
  light_index = (light_index+1)%4;
  else
  light_index = (light_index+1)%3;
   
  Serial.println("Light switching");
  Serial.println(light_index);
    if(Base_condition(count_arr)) 
    { 
      Serial.println("base condition hits");
      Timer[light_index] = 5000;
    }
  }
  if(type==1)
  Timer[light_index]=Timer[light_index]-(delay_per_read*4);
  else
  Timer[light_index]=Timer[light_index]-(delay_per_read*3);
   
}







int read1(){
  int val = digitalRead(inductivePin_1);  // Read the value from the inductive sensor
  delay(delay_per_read);
  return val;
}
int read2(){
  int val = digitalRead(inductivePin_2);  // Read the value from the inductive sensor
  delay(delay_per_read);
  return val;
}
int read3(){
 int val = digitalRead(inductivePin_3);  // Read the value from the inductive sensor
  delay(delay_per_read);
  return val;
}
int read4(){
  int val = digitalRead(inductivePin_4);  // Read the value from the inductive sensor
  delay(delay_per_read);
  return val;
}

int Base_condition(int* count_arr){
  int check = 1;
  if(type==1)
  {
    for(int i =0;i<4;i++) 
    {
      if(count_arr[i] != 0)
      {
        check = 0;
        break;
      }
    } 
  }
  else 
  {
    for(int i =0;i<3;i++) 
    {
      if(count_arr[i] != 0)
      {
        check = 0;
        break;
      }
    }
  }
  return check;
}





 



