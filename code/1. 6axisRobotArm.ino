#include <Servo.h>

Servo m_grip; // 30: 그립 최대로 열기, 110: 그립 최대로 닫기, 동작 범위 벗어나지 않도록.
Servo m_wristRotate; // CW 0 ~ CCW180
Servo m_wristTilt; // 앞 180 ~ 뒤 0
Servo m_elbowTilt1; // 앞 0 ~ 뒤 180
Servo m_elbowTilt2; // 앞 180 ~ 뒤 0
Servo m_bodyRotate; // CW 0 ~ CCW180


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

  Serial.begin(9600);
  Serial.println("Program Start..");
}

void loop() {
  m_grip.write(0);
}
