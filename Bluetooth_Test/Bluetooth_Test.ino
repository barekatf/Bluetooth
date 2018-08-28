/*
COMMAND	        RESPONSE        COMMENT
AT	        OK              Used to verify communication
AT+VERSION	OKlinvorV1.8	The firmware version (version might depend on firmware)
AT+NAMExyz	OKsetname	Sets the module name to “xyz”
AT+PIN1234	OKsetPIN	Sets the module PIN to 1234
AT+BAUD1	OK1200	        Sets the baud rate to 1200
AT+BAUD2	OK2400	        Sets the baud rate to 2400
AT+BAUD3	OK4800	        Sets the baud rate to 4800
AT+BAUD4	OK9600	        Sets the baud rate to 9600
AT+BAUD5	OK19200	        Sets the baud rate to 19200
AT+BAUD6	OK38400	        Sets the baud rate to 38400
AT+BAUD7	OK57600	        Sets the baud rate to 57600
AT+BAUD8	OK115200	Sets the baud rate to 115200
AT+BAUD9	OK230400	Sets the baud rate to 230400
AT+BAUDA	OK460800	Sets the baud rate to 460800
AT+BAUDB	OK921600	Sets the baud rate to 921600
AT+BAUDC	OK1382400	Sets the baud rate to 1382400
*/
#include <SoftwareSerial.h>

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bt (bluetoothTx, bluetoothRx); // RX, TX

char cmd = 0;
char val = 0; 

void setup() {
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  bt.begin(115200);  // Start bluetooth serial at 115200
}

void loop() {
  if (bt.available()) {
    cmd = (char)bt.read();
    Serial.print(cmd);
  }
  if(Serial.available()) { 
    val = (char)Serial.read(); 
    bt. write(val); 
  }
}
