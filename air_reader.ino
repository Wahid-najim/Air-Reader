#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define DHT11 sensor
#define DHTPIN 2 // DHT11 data pin connected to Arduino A1
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// MQ-6 Gas Sensor
#define MQ6PIN A0 // MQ-6 analog pin connected to Arduino A0

// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // Initialize the LCD and turn on backlight
  lcd.init();
  lcd.backlight();

  // Start DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature and humidity
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Read gas value
  int gasValue = analogRead(MQ6PIN);

  // Display Temperature and Humidity
  lcd.clear();
  lcd.setCursor(0, 0); // Start at character 0 on line 0
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1); // Line 2
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print(" %");

  // Display Gas value if above 150
 
    lcd.setCursor(0, 2); // Line 3
    lcd.print("Gas Value: ");
    lcd.print(gasValue);
    

  if (gasValue > 150){
    lcd.setCursor(0,3);
    lcd.print("Air-Quality: Danger");
  }else{
     lcd.setCursor(0,3);
    lcd.print("Air-Quality: Safe");
  }
  

  // Delay before next reading
  delay(2000); // Wait for 2 seconds
}
