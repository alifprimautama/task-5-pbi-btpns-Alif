#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "Primxxx"
#define WIFI_PASSWORD "passwordapa123"

// Insert Firebase project API Key
#define API_KEY "AIzaSyAFPxF9xJm76ZxRfzMsugOre_ln3mTSSoE"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://test11-8315a-default-rtdb.firebaseio.com/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

//some importent variables
String sValue, sValue2;
bool signupOK = false;
int lampA = 1; 
int lampB = 2; 
int lampC = 3;
int lampD = 4;
int lampE = 5;
int lampF = 6;
int lampG = 7;

void setup() {
  Serial.begin(115200);
  
  pinMode(lampA,OUTPUT);
  pinMode(lampB,OUTPUT);
  pinMode(lampC,OUTPUT);
  pinMode(lampD,OUTPUT);
  pinMode(lampE,OUTPUT);
  pinMode(lampF,OUTPUT);
  pinMode(lampG,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  if (Firebase.ready() && signupOK ) {
    if (Firebase.RTDB.getString(&fbdo, "/lampuA")) {
      if (fbdo.dataType() == "string") {
        sValue = fbdo.stringData();
        int a = sValue.toInt();
        Serial.println(a);
        if (a == 1){
          digitalWrite(lampA,LOW);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,LOW);
          digitalWrite(lampE,LOW);
          digitalWrite(lampF,LOW);
          digitalWrite(lampG,LOW);
        }else if (a == 2) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampE,HIGH);
          digitalWrite(lampG,HIGH);
          digitalWrite(lampC,LOW);
          digitalWrite(lampF,LOW);
        }else if (a == 3 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampG,HIGH);
          digitalWrite(lampE,LOW);
          digitalWrite(lampF,LOW);
        }else if (a == 4 ) {
          digitalWrite(lampA,LOW);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,LOW);
          digitalWrite(lampE,LOW);
          digitalWrite(lampF,HIGH);
          digitalWrite(lampG,HIGH);  
      }else if (a == 5 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,LOW);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampE,LOW);
          digitalWrite(lampF,HIGH);
          digitalWrite(lampG,HIGH);
          }else if (a == 6 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,LOW);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampE,HIGH);
          digitalWrite(lampF,HIGH);
          digitalWrite(lampG,HIGH);
          }else if (a == 7 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,LOW);
          digitalWrite(lampE,LOW);
          digitalWrite(lampF,LOW);
          digitalWrite(lampG,LOW);
          }else if (a == 8 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampE,HIGH);
          digitalWrite(lampF,HIGH);
          digitalWrite(lampG,HIGH);
         }else if (a == 9 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampE,LOW);
          digitalWrite(lampF,HIGH);
          digitalWrite(lampG,HIGH);
         }else if (a == 0 ) {
          digitalWrite(lampA,HIGH);
          digitalWrite(lampB,HIGH);
          digitalWrite(lampC,HIGH);
          digitalWrite(lampD,HIGH);
          digitalWrite(lampE,HIGH);
          digitalWrite(lampF,HIGH);
          digitalWrite(lampG,LOW);
         }
      }
    }
  }
}