// Define Trig and Echo pin:
#define trigPin 2
#define echoPin 3
#define ledPin 4 
#define buttonPin 5

// Define variables:
long duration;
int distance;
int buttonState;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  //buttonState = 1;
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);

  buttonState = digitalRead(buttonPin);
  
  
  // Calculate the distance:
  distance = duration * 0.034 / 2;
  
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);

  //if (buttonState == 1){

  if (distance < 20){
    digitalWrite(ledPin, HIGH);
    }

   if (distance > 20 ){

    digitalWrite(ledPin, LOW);
    
    }
   
  
}
