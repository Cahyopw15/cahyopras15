#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid     = "iPhone";
const char* password = "Bandung2021";

// supabase credentials
String API_URL = "https://stzmwkrsdeuuvkddedlv.supabase.co";
String API_KEY = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InN0em13a3JzZGV1dXZrZGRlZGx2Iiwicm9sZSI6ImFub24iLCJpYXQiOjE2Nzk4OTgwMjcsImV4cCI6MTk5NTQ3NDAyN30.s88mg7Vl59Dz1KkbKqIU3CHxa95ao7nOIpI9JJxstYs";
String TableName = "kebisingan";
const int httpsPort = 443;

// Sending interval of the packets in seconds
int sendinginterval = 1200; // 20 minutes
//int sendinginterval = 120; // 2 minutes

HTTPClient https;
HTTPClient client;
WiFiClientSecure Client;

char objetJson[128];

void setup() {

  Client.setInsecure();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // put your setup code here, to run once:
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(14, INPUT);
  pinMode(27, INPUT);
  Serial.begin(9600);
}
long mic1, mic2, mic3, mic4, nilaidB1, nilaidB2, nilaidB3, nilaidB4 ; //nilaidB2, nilaidB3, nilaidB4


void loop() {
if (WiFi.status() == WL_CONNECTED) {
  // put your main code here, to run repeatedly:
mic1 = analogRead(13);
mic2 = analogRead(12);
mic3 = analogRead(14);
mic4 = analogRead(27);

////////////DATA FIX KALIBRASI SENSOR1-4///////////////////
nilaidB1 = (mic1-1724.2)/1.7068; //fix data pin mic1 d13 keluaran 1700an-1800
nilaidB2 = (mic2-780.95)/3.4252; //FIXdata pin mic2 d12 keluaran 905-1018an
nilaidB3 = (mic3-2290.6)/4.8495; //fix data mic3 d14 keluaran 2500an
nilaidB4 = (mic4-3283.6)/3.6033; //fix data mic3 d14 keluaran 3208-3332an

//////////////////////////////MACAM-MACAM DATA KALIBRASI SENSOR 1-4/////////////////////////
//nilaidB1 = (mic1-1273.3)/3.5781; //fix data pin mic1 d13 keluaran 1400an
//nilaidB1 = (mic1-1273.3)/3.5781; //fix data pin mic1 d13 keluaran 1950-2104an
//nilaidB1 = (mic1-131.41)/5.6275; //fix data pin mic1 d13 keluaran 400an
//nilaidB1 = (mic1-1870.8)/5.1999; //fix data pin mic1 d13 keluaran 2100an
//nilaidB1 = (mic1-1870.8)/5.1999; //fix data pin mic1 d13 keluaran 1800an

//nilaidB2 = (mic2-1724.2)/1.7068; //fix data pin mic2 d13 keluaran 1700an-1800
//nilaidB2 = (mic2-93.937)/3.1752; //FIXdata pin mic2 d12 keluaran 200an

//nilaidB3 = (mic3-1870.8)/5.1999; //fix data pin mic3 d13 keluaran 1800an
//nilaidB3 = (mic3-1870.8)/5.1999; //fix data pin mic1 d13 keluaran 2100an
//nilaidB3 = (mic3-2190)/4.8495; //fix data mic3 d14 keluaran 2356-2519an


//nilaidB4 = (mic4-3183.6)/3.6033; //fix data mic3 d14 keluaran 3300an
//nilaidB = (mic4-3283.6)/3.6033; //fix data mic3 d14 keluaran 3208-3332an

//nilaidB = (mic1-764.57)/3.1023;keluaran 901 mic1 d13
//nilaidB = (mic1-1575.7)/3.5301;
//nilaidB = (mic1-117.5)/3.5285; //mic13 keluaran 1700
//nilaidB = (mic1-1724.2)/1.7068; //sudah benar y=mx+c
//nilaidB = (mic2-1724.2)/1.7068; //sudah benar

//nilaidB = 0.1767*mic2-241.13; (rumus alternatif, langsung masukkan nilai tanpa di cari x nya dahulu)
//////////////////////////////////////////////////////////////////////////////////////////////////////


//Serial.println((String)"Mikrofon 1 ADC : " + mic1);
Serial.println((String)"Mikrofon 1 dB : " + nilaidB1+(String)" dB");

//Serial.println((String)"Mikrofon 2 ADC: " + mic2);
Serial.println((String)"Mikrofon 2 dB : " + nilaidB2+(String)" dB");

//Serial.println((String)"Mikrofon 3 ADC : " + mic3);
Serial.println((String)"Mikrofon 3 dB : " + nilaidB3+(String)" dB");

//Serial.println((String)"Mikrofon 4 ADC: " + mic4);
Serial.println((String)"Mikrofon 4 dB : " + nilaidB4+(String)" dB");

https.begin(client,API_URL+"/rest/v1/"+TableName);
https.addHeader("Content-Type", "application/json");
https.addHeader("Prefer", "return=representation");
https.addHeader("apikey", API_KEY);
https.addHeader("Authorization", "Bearer " + API_KEY);
const size_t CAPACITY = JSON_OBJECT_SIZE(3);
  StaticJsonDocument<CAPACITY> doc;

  JsonObject obj= doc.to<JsonObject>();
  obj ["kebisingan"] = "1";
  obj ["Sensor1"] = nilaidB1;
  obj ["Sensor2"] = nilaidB2;
  obj ["Sensor3"] = nilaidB3;
  obj ["Sensor4"] = nilaidB4;

  serializeJson (doc, objetJson);
  Serial.println("Objet json: ");
  Serial.print(objetJson);
    
  int httpCode = client.PATCH(String(objetJson));

    if (httpCode > 0) {
        Serial.println();
        Serial.printf("Código de respuesta: %d\t", httpCode);
      
        if (httpCode == HTTP_CODE_OK) {
          String payload = client.getString();
          Serial.println(payload);
        }
      }
        else {
          Serial.printf("Error de la solicitud, error: %s\n", client.errorToString(httpCode).c_str());
        }
    client.end();
    else {
     Serial.println("Conexión perdida");
     }  
int httpCode = https.POST("{\"Sensor1\":" + String(nilaidB1)+ ",\"Sensor2\":"+ String(nilaidB2)+",\"Sensor3\":" + String(nilaidB3)+",\"Sensor4\":" + String(nilaidB4)+"}" );   //Send the request
String payload = https.getString(); 
Serial.println(httpCode);   //Print HTTP return code
Serial.println(payload);    //Print request response payload
https.end();
}

delay(10000);
}
