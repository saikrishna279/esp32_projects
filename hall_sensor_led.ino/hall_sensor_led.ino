//Simple sketch to access the internal hall effect detector on the esp32.
//values can be quite low. 
//and light up the led on PIN 5 as per the magnitude
//Upon reset, the initial value is stored and is used as offset (only negative offset)
//Sai Krishna 279 *androidwall.nrt@gmail.com*
#define LEDC_CHANNEL 0
#define LEDC_FREQUENCY 10000
#define LEDC_TIMER_BIT 16
#define LED_PINOUT 5

int val = 0,const_startupval;
void setup() {
  Serial.begin(115200);
  ledcSetup(LEDC_CHANNEL, LEDC_FREQUENCY, LEDC_TIMER_BIT);
  ledcAttachPin(LED_PINOUT, LEDC_CHANNEL);
  const_startupval = hallRead();
    }

void loop() {
  val = hallRead();
  Serial.println(val);//to graph 
  ledcWrite(LEDC_CHANNEL, val-const_startupval);
}
