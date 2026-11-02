# include <Wire.h>
# include <LiquidCrystal_I2C.h>
# include <DHT.h>

# define DHTPIN A0
# define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  lcd.print("PROJECT IS READY");
  lcd.setCursor(0,1);
  lcd.print("MY 1ST PROJECT");
  delay(3000);
  lcd.clear();

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)){
    
    lcd.print("SENSOR ERROR!!");
    return;
  }

  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print(" degree Celsius");

  delay(4000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  delay(8000);
  lcd.clear();
  lcd.print("THANK YOU ");
}
