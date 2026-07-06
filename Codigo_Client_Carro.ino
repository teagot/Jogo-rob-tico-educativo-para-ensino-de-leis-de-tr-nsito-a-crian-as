#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
static BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");

static BLEAdvertisedDevice* myDevice;
bool conectado = false;

#define AIN1 3
#define AIN2 4
#define BIN1 6
#define BIN2 7

// Função que roda quando o carro recebe um comando do controle
static void notifyCallback(BLERemoteCharacteristic* pBLERemoteCharacteristic, 
                           uint8_t* pData, size_t length, bool isNotify) {
    char comando = (char)pData[0];
    Serial.print("BEETLE RECEBEU COMANDO: ");
    Serial.println(comando);

          if (comando == 'W') {
        // digitalWrite(PINO_MOTOR, HIGH); 
        Serial.println("Ação: Motores para frente!");
        digitalWrite (AIN1, HIGH);
        digitalWrite (AIN2, LOW);
        digitalWrite (BIN1, HIGH);
        digitalWrite (BIN2, LOW);
    }

    else if(comando == 'A') {
      Serial.println("Ação: Motores para esquerda!");
      digitalWrite (AIN1, HIGH); //low > high inverti esquerda e direita (vale pra tudo)
      digitalWrite (AIN2, LOW); //high > low
      digitalWrite (BIN1, LOW); //high > low
      digitalWrite (BIN2, HIGH); //low > high
    }
    
    else if (comando == 'S') {
      Serial.println("Ação: Motores para trás!");
      digitalWrite (AIN1, LOW);
      digitalWrite (AIN2, HIGH);
      digitalWrite (BIN1, LOW);
      digitalWrite (BIN2, HIGH);
    }

    else if(comando == 'D') {
      Serial.println("Ação: Motores para direita!");
      digitalWrite (AIN1, LOW); //high > low
      digitalWrite (AIN2, HIGH); //low > high
      digitalWrite (BIN1, HIGH); //low > high
      digitalWrite (BIN2, LOW); //high > low
    }

    else if (comando == 'P') {
      Serial.println("Ação: Motores parados!");
      digitalWrite (AIN1, LOW);
      digitalWrite (AIN2, LOW);
      digitalWrite (BIN1, LOW);
      digitalWrite (BIN2, LOW);
    }
                           }

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    if (advertisedDevice.isAdvertisingService(serviceUUID)) {
      BLEDevice::getScan()->stop();
      myDevice = new BLEAdvertisedDevice(advertisedDevice);
    }
  }
};

bool conectarAoControle() {
    BLEClient* pClient = BLEDevice::createClient();
    if (!pClient->connect(myDevice)) return false;

    BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
    if (pRemoteService == nullptr) return false;

    BLERemoteCharacteristic* pRemoteChar = pRemoteService->getCharacteristic(charUUID);
    if (pRemoteChar == nullptr) return false;

    // Registra para receber as notificações do controle
    if(pRemoteChar->canNotify())
        pRemoteChar->registerForNotify(notifyCallback);

    conectado = true;
    return true;
}

void setup() {
  Serial.begin(115200);
  BLEDevice::init("");
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);

  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);
}

void loop() {
  if (myDevice != nullptr && !conectado) {
    if (conectarAoControle()) Serial.println("Conectado ao Controle!");
  }
  
  if (!conectado) {
    BLEDevice::getScan()->start(5, false);
  }
  delay(1000);
}