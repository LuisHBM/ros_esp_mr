const uint8_t R_PWM = 12;
const uint8_t R_BACK = 14;
const uint8_t R_FORW = 27;

const uint8_t L_PWM = 33;
const uint8_t L_BACK = 25;
const uint8_t L_FORW = 26;

const uint8_t channel_L = 0;
const uint8_t channel_R = 0;

void setup() {
  Serial.begin(115200);
}

void pin_def() {
  const int freq = 5000;
  const int res = 8;

  pinMode(L_BACK, OUTPUT);
  pinMode(L_FORW, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_BACK, OUTPUT);
  pinMode(R_FORW, OUTPUT);
  pinMode(R_PWM, OUTPUT);

  ledcAttachPin(R_PWM, channel_R);
  ledcAttachPin(L_PWM, channel_L);
  ledcSetup(channel_R, freq, res);
  ledcSetup(channel_L, freq, res);
}

void loop() {
  move_foward();
  delay(2000);
}

void move_foward() {
  Serial.println("Moving foward");

  digitalWrite(L_FORW, 1);
  digitalWrite(R_FORW, 1);
  ledcWrite(channel_L, 200);
  ledcWrite(channel_R, 200);
}

void move_backward() {
  Serial.println("Moving foward");

  digitalWrite(L_FORW, 0);
  digitalWrite(R_FORW, 0);
  ledcWrite(channel_L, 200);
  ledcWrite(channel_R, 200);
}

void move_left() {
  Serial.println("Moving foward");

  digitalWrite(L_FORW, 0);
  digitalWrite(R_FORW, 1);
  ledcWrite(channel_L, 0);
  ledcWrite(channel_R, 200);
}

void move_right() {
  Serial.println("Moving foward");

  digitalWrite(L_FORW, 1);
  digitalWrite(R_FORW, 0);
  ledcWrite(channel_L, 200);
  ledcWrite(channel_R, 0);
}