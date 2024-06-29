// Define Arduino pin numbers connected to the IC's inputs for two motors
const int IN1_Motor1 = 9;  // IN1 pin for PWM for Motor 1
const int IN2_Motor1 = 10;  // IN2 pin for PWM for Motor 1

const int IN1_Motor2 = 11;  // IN1 pin for PWM for Motor 2
const int IN2_Motor2 = 12;  // IN2 pin for PWM for Motor 2

void setup() {
  // Initialize serial communication at 9600 bps:
  Serial.begin(9600);

  // Set motor control pins as outputs for both motors
  pinMode(IN1_Motor1, OUTPUT);
  pinMode(IN2_Motor1, OUTPUT);

  pinMode(IN1_Motor2, OUTPUT);
  pinMode(IN2_Motor2, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming string
    String data = Serial.readStringUntil('\n');

    // Extract pwm1, pwm2, and command
    int firstSpaceIndex = data.indexOf(' ');
    int secondSpaceIndex = data.indexOf(' ', firstSpaceIndex + 1);

    int pwm1 = data.substring(0, firstSpaceIndex).toInt();
    int pwm2 = data.substring(firstSpaceIndex + 1, secondSpaceIndex).toInt();

    analogWrite(IN1_Motor1, pwm1);
    digitalWrite(IN2_Motor1, LOW);

    analogWrite(IN1_Motor2, pwm2);
    digitalWrite(IN2_Motor2, LOW);
  
  }
}


