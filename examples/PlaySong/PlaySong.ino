#include <MUSE.h>

MUSE muse;

void setup() {
  muse.setup();

  muse.registerDigitalInputCallback(twinkleTwinkle, 2);
}

void loop() {
  muse.loop();
}

void twinkleTwinkle(bool released) {
  if(!released) {
    muse.playNote(MUSE_C4, 250);
    muse.playNote(MUSE_C4, 250);
    muse.playNote(MUSE_G4, 250);
    muse.playNote(MUSE_G4, 250);
    muse.playNote(MUSE_A4, 250);
    muse.playNote(MUSE_A4, 250);
    muse.playNote(MUSE_G4, 500);
    muse.playNote(MUSE_F4, 250);
    muse.playNote(MUSE_F4, 250);
    muse.playNote(MUSE_E4, 250);
    muse.playNote(MUSE_E4, 250);
    muse.playNote(MUSE_D4, 250);
    muse.playNote(MUSE_D4, 250);
    muse.playNote(MUSE_C4, 500);
  }
}

