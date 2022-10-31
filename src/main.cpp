#include "Arduino.h"
#include <CAN.h>
#include "NewProtocol.h"
#include "SECCCan.h"

// Most cars support 11-bit adddress, others (like Honda),
// require 29-bit (extended) addressing, set the next line
// to true to use extended addressing
const bool useStandardAddressing = false;
String IDt = "12345678901234567890";
Payload_AuthorizeReq AReq;
Payload_AuthorizeRes ARes;
Payload_BootCnf BootCnf;
EVSEModelCan Canmodel;
void setup() {
  Serial.begin(115200);

  Serial.println("CAN OBD-II VIN reader");

  //CAN.setPins(5,4);
  
  // start the CAN bus at 500 kbps
  /*
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }*/



  //Canpacket_ProtocolSend(AReq);
  Canpacket_ProtocolSend(ARes);
  Canpacket_ProtocolSend(BootCnf);
}

void loop() {
    //Canunpacket_ProtocolRes(AReq);
    Canmodel.loop();
  /*
  // send the request for the first chunk
  if (useStandardAddressing) {
    CAN.beginPacket(0x7df, 8);
  } else {
    CAN.beginExtendedPacket(0x18db33f1, 8);
  }
  CAN.write(0x02); // Number of additional bytes
  CAN.write(0x09); // Request vehicle information
  CAN.write(0x02); // Vehicle Identification Number (VIN)
  CAN.endPacket();

  // wait for response
  while (CAN.parsePacket() == 0 ||
         CAN.read() != 0x10 || CAN.read() != 0x14 || // correct length
         CAN.read() != 0x49 ||                       // correct mode
         CAN.read() != 0x02 ||                       // correct PID
         CAN.read() != 0x01);

  // print out
  while (CAN.available()) {
    Serial.write((char)CAN.read());
  }
 

  // read in remaining chunks
  for (int i = 0; i < 2; i++) {
    // send the request for the next chunk
    if (useStandardAddressing) {
      CAN.beginPacket(0x7e0, 8);
    } else {
      CAN.beginExtendedPacket(0x18db33f1, 8);
    }
    CAN.write(0x30);
    CAN.endPacket();

    // wait for response
    while (CAN.parsePacket() == 0 ||
           CAN.read() != (0x21 + i)); // correct sequence number

    // print out
    if (CAN.read()== 0x20) {
      Serial.write((char)CAN.read());
    }
  }

  //Serial.println("That's all folks!");

  //while (1); // all done
  */
}