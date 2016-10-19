#include <MUSE.h>

MUSE muse;

void setup() {
  muse.setup();

  muse.registerDigitalInputCallback(middleC, 2);
}

void loop() {
  muse.loop();
}

void middleC(bool released) {
  if(released) {
    muse.noteOff(MUSE_C4);
  } else {
    muse.noteOn(MUSE_C4);
  }
}

