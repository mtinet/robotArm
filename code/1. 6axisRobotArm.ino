#include <Servo.h>

Servo m_grip; // 30: 그립 최대로 열기, 110: 그립 최대로 닫기, 동작 범위 벗어나지 않도록.
Servo m_wristRotate; // CW 0 ~ CCW180
Servo m_wristTilt; // 앞 0 ~ 뒤 180
Servo m_elbowTilt1; // 앞 180 ~ 뒤 0
Servo m_elbowTilt2; // 앞 180 ~ 뒤 0
Servo m_bodyRotate; // CW 0 ~ CCW180

int val_grip = 90; 
int val_wristRotate = 90; 
int val_wristTilt = 90; 
int val_elbowTilt1 = 90; 
int val_elbowTilt2 = 90; 
int val_bodyRotate = 90; 

int initialPosition = 90;   

void setup() {
  m_grip.attach(3); 
  m_wristRotate.attach(5); 
  m_wristTilt.attach(6); 
  m_elbowTilt1.attach(9); 
  m_elbowTilt2.attach(10); 
  m_bodyRotate.attach(11); 

  //Openning
  m_grip.write(initialPosition); 
  m_wristRotate.write(initialPosition); 
  m_wristTilt.write(initialPosition); 
  m_elbowTilt1.write(initialPosition); 
  m_elbowTilt2.write(initialPosition); 
  m_bodyRotate.write(initialPosition);   
  delay(500);
  m_grip.write(30); 
  m_wristRotate.write(0); 
  delay(500);
  m_grip.write(110); 
  m_wristRotate.write(180); 
  delay(700);

  //Initialize
  m_grip.write(initialPosition); 
  m_wristRotate.write(initialPosition); 
  m_wristTilt.write(initialPosition); 
  m_elbowTilt1.write(initialPosition); 
  m_elbowTilt2.write(initialPosition); 
  m_bodyRotate.write(initialPosition); 
  delay(1000);

  Serial.begin(9600);
  Serial.println("Program Start..");
}

void loop() {
  
}

void serialEvent() {
  if(Serial.available()){
    val_grip = Serial.parseInt();
    val_wristRotate = Serial.parseInt();
    val_wristTilt = Serial.parseInt();
    val_elbowTilt1 = Serial.parseInt(); 
    val_elbowTilt2 = Serial.parseInt();
    val_bodyRotate = Serial.parseInt();
  }    
  Serial.println(val_grip);
  Serial.println(val_wristRotate);
  Serial.println(val_wristTilt);
  Serial.println(val_elbowTilt1);
  Serial.println(val_elbowTilt2);
  Serial.println(val_bodyRotate);

  test(val_grip, val_wristRotate, val_wristTilt, val_elbowTilt1, val_elbowTilt2,val_bodyRotate); 
  // 똑바로 세우기 : 90 90 90 90 90 90
  // 기본자세 : 90 90 150 0 30 90
}


void test(int _val_grip, int _val_wristRotate, int _val_wristTilt, int _val_elbowTilt1, int _val_elbowTilt2, int _val_bodyRotate) {
  m_grip.write(_val_grip); 
  m_wristRotate.write(_val_wristRotate); 
  m_wristTilt.write(_val_wristTilt); 
  m_elbowTilt1.write(_val_elbowTilt1); 
  m_elbowTilt2.write(_val_elbowTilt2); 
  m_bodyRotate.write(_val_bodyRotate); 
  delay(500);
}

