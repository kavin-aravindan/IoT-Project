// Ultrasonic sensor libraries
// #include <NewPing.h>
#include Ultrasonic.h



// Constants (won't change)
#define trigPin1 = 2;  // Trigger pin for sensor 1
#define echoPin1 = 3;  // Echo pin for sensor 1
#define trigPin2 = 4;  // Trigger pin for sensor 2
#define echoPin2 = 5;  // Echo pin for sensor 2
#define trigPin3 = 6;  // Trigger pin for sensor 3
#define echoPin3 = 7;  // Echo pin for sensor 3
#define trigPin4 = 8;  // Trigger pin for sensor 4
#define echoPin4 = 9;  // Echo pin for sensor 4

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

Ultrasonic ultrasonic1(trigPin1,echoPin1);
Ultrasonic ultrasonic2(trigPin2,echoPin2);
Ultrasonic ultrasonic3(trigPin3,echoPin3);
Ultrasonic ultrasonic4(trigPin4,echoPin4);



int count_arr[4];  //count the number of cars per road
int signal[4];  // 1 for green and 0 for red
int Timer[4];   // 0 for red and time remaining in millisecs for the green light
int light_index;



void setup() {
  Serial.begin(9600);
  light_index = 0;
  Timer[light_index] = 5000;
  for(int i = 1;i<4;i++) Timer[i] = 0;
  signal[light_index] = 1;
  for(int i = 1;i<4;i++) signal[i] = 0;
  for(int i =0;i<4;i++) count_arr[i] = 0; 
}

void loop() {
  int multiplier = 1250;
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
  // LED green triger
  if(arr[light_index] > 0 && arr[light_index] <= 24){ 
      Timer[light_index] += multiplier * count_arr[light_index];
      count_arr[light_index] = 0;
      }
  else if(count_arr[light_index] > 24 ){
    Timer[light_index] += multiplier * count_arr[light_index];
    count_arr[light_index] -= 24;
  }

  Timer[light_index] -= 1;

  count_arr[0] +=read1();
  count_arr[1] +=read2();
  count_arr[2] +=read3();
  count_arr[3] +=read4();

  if(Timer[light_index] == 0 || Timer[light_index] < 0){
    signal[light_index] = 0;
    //LED Red triger 
    light_index = (light_index+1)%4;
    if(Base_condition(count_arr)) Timer[light_index] = 5000;
  }  
}







int read1(){
  float distance = ultrasonic1.read();
  int val= (distance<=10);
  if(val == 1) return 1;
  else return 0;
  delay();
}
int read2(){
  float distance = ultrasonic2.read();
  int val= (distance<=10);
  if(val == 1) return 1;
  else return 0;
  delay();
}
int read3(){
  float distance = ultrasonic3.read();
  int val= (distance<=10);
  if(val == 1) return 1;
  else return 0;
  delay();
}
int read4(){
  float distance = ultrasonic4.read();
  int val= (distance<=10);
  if(val == 1) return 1;
  else return 0;
  delay();
}

int Base_condition(int * count_arr){
  int check = 1;
  for(int i =0;i<4;i++){
    if(count_arr[i] != 0){
      check = 0;
      break;
    }
  }
  return check;
}





 




