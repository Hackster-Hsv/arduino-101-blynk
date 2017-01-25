#define BLYNK_PRINT Serial

#include <BlynkSimpleCurieBLE.h>
#include <CurieBLE.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "youAuthToken";

BLEPeripheral  blePeripheral;

int clicks = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);

  blePeripheral.setLocalName("Blynk");
  blePeripheral.setDeviceName("Blynk");
  blePeripheral.setAppearance(384);

  Blynk.begin(blePeripheral, auth);

  blePeripheral.begin();

  Serial.println("Waiting for connections...");
}

BLYNK_READ(1) {
  Blynk.virtualWrite(1, clicks);
}

BLYNK_WRITE(2) {
  clicks += 1;
}

void loop() {
  Blynk.run();
  blePeripheral.poll();
}
