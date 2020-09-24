#include <Pixy2.h>


#include "Talkie.h"
#include "Vocab_US_Large.h"

Talkie voice;

Pixy2 pixy;
String signatureS;
String pureSig;
int sig;

void setup() {
    Serial.begin(115200);
    Serial.print("Starting...\n");

    pixy.init();

    #if defined(CORE_TEENSY)
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH); //Enable Amplified PROP shield
#endif
    voice.say(sp2_DANGER);
    voice.say(sp2_DANGER);
    voice.say(sp2_RED);
    voice.say(sp2_ALERT);
    voice.say(sp2_MOTOR);
    voice.say(sp2_IS);
    voice.say(sp2_ON);
    voice.say(sp2_FIRE);
}

void loop() {

int i;
//grab blocks!
pixy.ccc.getBlocks();

//if there are detect blocks, print them!
if (pixy.ccc.numBlocks)
{

  for (i-0; i<pixy.ccc.numBlocks; i++)
  {

    sig=pixy.ccc.blocks[i].m_signature;
    Serial.println(sig);

    switch(sig) {
      case 1: voice.say(sp2_DANGER);
      Serial.println("red");
      break;
      case 2: voice.say(sp2_RED);
      Serial.println("danger");
      break;
      default:
      break;
    }
  }
  
  
}

delay(2000);
}
