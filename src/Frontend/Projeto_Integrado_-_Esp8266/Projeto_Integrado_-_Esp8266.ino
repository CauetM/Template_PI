#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Villella";
const char* password = "26541915";

ESP8266WebServer server(80);

int situação = 0;





void handleRoot() {
  analogRead(situação);
 Serial.print(analogRead(A0));
situação = analogRead(A0);
  String textoHTML;

  if(situação > 20){

textoHTML = "<b>Status da planta: HIDRATADA!</b> ";

  
   
  server.send(200, "text/html", textoHTML);

 

  }
  if(situação <= 20){

textoHTML = "<b>Status da planta: DESIDRATADA!</b>  ";
 
   
  server.send(200, "text/html", textoHTML);

 
}
}
void handleNotFound(){
  analogRead(situação);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  (situação);
}

void setup(void){
 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  
   Serial.print("Sinal: ");
  Serial.print(analogRead(A0));
  delay(100);

  server.handleClient();
}
