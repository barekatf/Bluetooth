// The serial port:
import processing.serial.*; 

Serial myPort; 

boolean forward = false; 
boolean backward = false; 
boolean right = false; 
boolean left = false; 


void setup() {
  size(300,200);
  colorMode(HSB, height, height, height);  
  noStroke();
  background(0);

  // Open the port you are using at the rate you want:
  myPort = new Serial(this, "COM6",115200);

}

void draw() { 
  sendBT(); 
}

void sendBT() { 
  if (forward) myPort.write('w');
  if (backward) myPort.write('s');
  if (right) myPort.write('d');
  if (left) myPort.write('a');
}

void keyPressed() { 
  print(key); 
  if (key == 'w') forward = true; 
  if (key == 's') backward = true; 
  if (key == 'd') right = true;
  if (key == 'a') left = true; 
}

void keyReleased() { 
  forward = false; 
  backward = false; 
  right = false; 
  left = false; 
}
