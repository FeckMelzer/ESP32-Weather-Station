/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "Your Network SSID";
const char* password = "Your Network Password";

#define DHTPIN 27     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readDHTTemperature() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float t = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String readDHTHumidity() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
    #weather {
      max-width: 500px;
      padding: 10px 20px;
      background: #f4f7f8;
      margin: 10px auto;
      padding: 20px;
      border-radius: 8px;
    }
    #weather h1 {
      color: #5974d6;
      margin: 0 0 15px 0;
    }
    #city {
      background: rgba(255, 255, 255, .1);
      border: none;
      border-radius: 4px;
      font-size: 15px;
      margin: 0;
      outline: 0;
      padding: 10px;
      width: 100%;
      box-sizing: border-box;
      -webkit-box-sizing: border-box;
      -moz-box-sizing: border-box;
      background-color: #e8eeef;
      color: #8a97a0;
      -webkit-box-shadow: 0 1px 0 rgba(0, 0, 0, 0.03) inset;
      box-shadow: 0 1px 0 rgba(0, 0, 0, 0.03) inset;
      margin-bottom: 30px;
    }
    #weather h2 {
      margin: 5px 0 5px 0;
    }
    #submit {
      position: relative;
      display: block;
      padding: 19px 39px 18px 39px;
      color: #FFF;
      margin: 0 auto;
      background: #5974d6;
      font-size: 18px;
      text-align: center;
      font-style: normal;
      width: 50%;
      border: none;
      margin-bottom: 10px;
    }
    #submit:hover {
      background: #213787;
    }
    #error {
      text-align: left;
      font-size: 14px;
      color: #c11b1b;
    }
    #output {
      margin-bottom: 10px;
    }
    #weather.sunny {
      background: linear-gradient(to right top,#ff4e50, #ff713e, #ff932b, #ffb41d, #f9d423);
    }
    #weather.cloudy {
      background: linear-gradient(to right top, #63747c, #71858e, #7f96a0, #8da8b2, #9bbac5);
    }
    #weather.rainy {
      background: linear-gradient(to right top, #637c7b, #718e8c, #7ea09e, #8db2b0, #9bc5c3);
    }
    #location {
      font-size: 24px;
    }
    #description {
      font-size: 18px;
    }
  </style>
</head>
<body>
  <h2>ESP32 DHT Server</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="dht-labels">Temperature</span> 
    <span id="temperature">%TEMPERATURE%</span>
    <sup class="units">&deg;C</sup>
  </p>
  <p>
    <i class="fas fa-tint" style="color:#00add6;"></i> 
    <span class="dht-labels">Humidity</span>
    <span id="humidity">%HUMIDITY%</span>
    <sup class="units">%</sup>
  </p>
  <div id="weather">
    <h1>Weather</h1>
    <div id="output">
      <div id="location"></div>
      <h2 id="temp"></h2>
      <div id="description"></div>
      <div id="error"></div>
    </div>
    <form>
      <input type="text" id="city" placeholder="Enter city">
      <input type="button" id="submit" onclick="getWeather()" value="Submit">
    </form>
  </div>

  <script lang="text/javascript">
    const getWeather = () => {
      document.getElementById('error').innerHTML = ''
      const cityName = document.getElementById('city').value
      const key = '33feeb29ab8bb8336ef7d4295a68a7ce'
      const url = 'https://api.openweathermap.org/data/2.5/weather?q=' + cityName + '&appid=' + key
      fetch(url)
        .then((resp) => {
          return resp.json()
        })
        .then((data) => drawWeather(data))
        .catch(() => { 
          document.getElementById('error').innerHTML = 'Please enter a valid city'
        })
    }
    
    const drawWeather = (data) => {
      const celcius = Math.round(parseFloat(data.main.temp) - 273.15)
      const description = data.weather[0].description

      document.getElementById('description').innerHTML = description
      document.getElementById('temp').innerHTML = celcius + '&deg;'
      document.getElementById('location').innerHTML = data.name
      
      let weather = document.getElementById('weather')
      if( description.indexOf('rain') >= 0 ) {
        weather.className = 'rainy';
      } else if( description.indexOf('cloud') >= 0 ) {
        weather.className = 'cloudy';
      } else if( description.indexOf('sunny') >= 0  || description.indexOf('clear') >= 0) {
        weather.className = 'sunny';
      }
    }
  </script>
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000 ) ;

</script>
</html>)rawliteral";

// Replaces placeholder with DHT values
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return readDHTTemperature();
  }
  else if(var == "HUMIDITY"){
    return readDHTHumidity();
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  dht.begin();
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTHumidity().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}
