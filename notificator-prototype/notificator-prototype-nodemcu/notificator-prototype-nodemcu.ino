#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Galaxy S9 de Lucas";
const char* password = "12345678";

void setup () {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(D1, INPUT);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.print("Connecting..");


  }

}

void loop() {

  if (digitalRead(D1) == HIGH) {

    Serial.print("inicio conexão");

    if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

      HTTPClient http;  //Declare an object of class HTTPClient

      http.begin("http://agile-harbor-96428.herokuapp.com/api/v1/notifications/1");  //Specify request destination
      int httpCode = http.GET();                                                                  //Send the request

      if (httpCode > 0) { //Check the returning code

        String payload = http.getString();   //Get the request response payload
        Serial.println(payload);                     //Print the response payload

      }

      http.end();   //Close connection

    }

    delay(120000);


  }


}
