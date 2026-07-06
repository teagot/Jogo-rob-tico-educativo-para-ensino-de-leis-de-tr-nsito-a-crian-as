#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

char comando;

#define JOY_X 34
#define JOY_Y 35

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) { deviceConnected = true; };
    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      pServer->getAdvertising()->start(); // Reinicia para o carro achar de novo
      Serial.println("Carro desconectado. Aguardando...");
    }
};

void setup() {
  Serial.begin(115200);
  BLEDevice::init("Controle_Remoto_ESP32");
  
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );

  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->start();
  
  Serial.println("Controle (Server) ligado! Esperando o carro (Beetle)...");

  pinMode (JOY_X, INPUT);
  pinMode (JOY_Y, INPUT);
}

void loop() {

  int x = analogRead (JOY_X);
  int y = analogRead (JOY_Y);

  if (Serial.available() > 0) {
    comando = Serial.read();
  }

  if (deviceConnected) {

    if (y < 1000) {
    // Exemplo: enviando 'W' a cada 2 segundos para testar
    comando = 'W';
    pCharacteristic->setValue("W");
    pCharacteristic->notify(); 
    Serial.println("Enviando comando: W");
    }

    else if (y > 3000) {
      comando = 'S';
      pCharacteristic->setValue("S");
      pCharacteristic->notify();
      Serial.println("Enviando comando: S");
    }

    else if (x < 1000) {
      comando = 'A';
      pCharacteristic->setValue("A");
      pCharacteristic->notify();
      Serial.println("Enviando comando: A");
    }

      else if (x > 3000) {
        comando = 'D';
        pCharacteristic->setValue("D");
        pCharacteristic->notify();
        Serial.println("Enviando comando: D");
      }

      else{
        comando = 'P';
        pCharacteristic->setValue("P");
        pCharacteristic->notify();
        Serial.println("Enviando comando: P");
      }
      delay (100);
  }
}