// Ultrasonic sensor libraries
#include <NewPing.h>

// Constants (won't change)
const int trigPin1 = 2;  // Trigger pin for sensor 1
const int echoPin1 = 3;  // Echo pin for sensor 1
const int trigPin2 = 4;  // Trigger pin for sensor 2
const int echoPin2 = 5;  // Echo pin for sensor 2
const int trigPin3 = 6;  // Trigger pin for sensor 3
const int echoPin3 = 7;  // Echo pin for sensor 3
const int trigPin4 = 8;  // Trigger pin for sensor 4
const int echoPin4 = 9;  // Echo pin for sensor 4

const unsigned int maxDistance = 200;  // Maximum distance to measure (in centimeters)

// Object instances for ultrasonic sensors
NewPing sonar1(trigPin1, echoPin1, maxDistance);
NewPing sonar2(trigPin2, echoPin2, maxDistance);
NewPing sonar3(trigPin3, echoPin3, maxDistance);
NewPing sonar4(trigPin4, echoPin4, maxDistance);

// Variables (will change)
unsigned long currentMillis = 0;   // Current time in milliseconds
unsigned long previousMillis = 0;  // Previous time for reading sensors

int is_1_red= 0;
int is_2_red= 0;
int is_3_red= 0;
int is_4_red= 0;

int red_count_1= 0;
int red_count_2= 0;
int red_count_3= 0;
int red_count_4= 0;

int green_count_1= 0;
int green_count_2= 0;
int green_count_3= 0;
int green_count_4= 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();
  read1();
  read2();
  read3();
  read4();
  red_count_1+= green_count_1;
  green_count_1=0;

  red_count_2+= green_count_2;
  green_count_2=0;
  
  red_count_3+= green_count_3;
  green_count_3=0;

  red_count_4+= green_count_4;
  green_count_4=0;
}

void read1(){
  int distance = sonar1.ping_cm();
  int val= (distance<=50);
  if(is_1_red==1 && val==1){
    red_count_1++;
  }else{
    green_count_1++;
  }
}
void read2(){
  int distance = sonar2.ping_cm();
  int val= (distance<=50);
  if(is_2_red==1 && val==1){
    red_count_1++;
  }else{
    green_count_1++;
  }
}
void read3(){
  int distance = sonar3.ping_cm();
  int val= (distance<=50);
  if(is_3_red==1 && val==1){
    red_count_3++;
  }else{
    green_count_3++;
  }
}
void read4(){
  int distance = sonar4.ping_cm();
  int val= (distance<=50);
  if(is_4_red==1 && val==1){
    red_count_4++;
  }else{
    green_count_4++;
  }
}
