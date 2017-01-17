#ifndef MUSE_INCLUDE
#define MUSE_INCLUDE

#ifndef MUSE_TIMERS
#define MUSE_TIMERS 20
#endif

#ifndef MUSE_DIGITAL_INPUTS
#define MUSE_DIGITAL_INPUTS 16
#endif

#include <Arduino.h>
#include <MIDI.h>

#ifdef MUSE_USE_SERIAL1
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
#else
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);
#endif

enum MUSENote {
    MUSE_C_1 = 0,
    MUSE_CS_1 = 1,
    MUSE_D_1 = 2,
    MUSE_DS_1 = 3,
    MUSE_E_1 = 4,
    MUSE_F_1 = 5,
    MUSE_FS_1 = 6,
    MUSE_G_1 = 7,
    MUSE_GS_1 = 8,
    MUSE_A_1 = 9,
    MUSE_AS_1 = 10,
    MUSE_B_1 = 11,
    MUSE_C0 = 12,
    MUSE_CS0 = 13,
    MUSE_D0 = 14,
    MUSE_DS0 = 15,
    MUSE_E0 = 16,
    MUSE_F0 = 17,
    MUSE_FS0 = 18,
    MUSE_G0 = 19,
    MUSE_GS0 = 20,
    MUSE_A0 = 21,
    MUSE_AS0 = 22,
    MUSE_B0 = 23,
    MUSE_C1 = 24,
    MUSE_CS1 = 25,
    MUSE_D1 = 26,
    MUSE_DS1 = 27,
    MUSE_E1 = 28,
    MUSE_F1 = 29,
    MUSE_FS1 = 30,
    MUSE_G1 = 31,
    MUSE_GS1 = 32,
    MUSE_A1 = 33,
    MUSE_AS1 = 34,
    MUSE_B1 = 35,
    MUSE_C2 = 36,
    MUSE_CS2 = 37,
    MUSE_D2 = 38,
    MUSE_DS2 = 39,
    MUSE_E2 = 40,
    MUSE_F2 = 41,
    MUSE_FS2 = 42,
    MUSE_G2 = 43,
    MUSE_GS2 = 44,
    MUSE_A2 = 45,
    MUSE_AS2 = 46,
    MUSE_B2 = 47,
    MUSE_C3 = 48,
    MUSE_CS3 = 49,
    MUSE_D3 = 50,
    MUSE_DS3 = 51,
    MUSE_E3 = 52,
    MUSE_F3 = 53,
    MUSE_FS3 = 54,
    MUSE_G3 = 55,
    MUSE_GS3 = 56,
    MUSE_A3 = 57,
    MUSE_AS3 = 58,
    MUSE_B3 = 59,
    MUSE_C4 = 60,
    MUSE_CS4 = 61,
    MUSE_D4 = 62,
    MUSE_DS4 = 63,
    MUSE_E4 = 64,
    MUSE_F4 = 65,
    MUSE_FS4 = 66,
    MUSE_G4 = 67,
    MUSE_GS4 = 68,
    MUSE_A4 = 69,
    MUSE_AS4 = 70,
    MUSE_B4 = 71,
    MUSE_C5 = 72,
    MUSE_CS5 = 73,
    MUSE_D5 = 74,
    MUSE_DS5 = 75,
    MUSE_E5 = 76,
    MUSE_F5 = 77,
    MUSE_FS5 = 78,
    MUSE_G5 = 79,
    MUSE_GS5 = 80,
    MUSE_A5 = 81,
    MUSE_AS5 = 82,
    MUSE_B5 = 83,
    MUSE_C6 = 84,
    MUSE_CS6 = 85,
    MUSE_D6 = 86,
    MUSE_DS6 = 87,
    MUSE_E6 = 88,
    MUSE_F6 = 89,
    MUSE_FS6 = 90,
    MUSE_G6 = 91,
    MUSE_GS6 = 92,
    MUSE_A6 = 93,
    MUSE_AS6 = 94,
    MUSE_B6 = 95,
    MUSE_C7 = 96,
    MUSE_CS7 = 97,
    MUSE_D7 = 98,
    MUSE_DS7 = 99,
    MUSE_E7 = 100,
    MUSE_F7 = 101,
    MUSE_FS7 = 102,
    MUSE_G7 = 103,
    MUSE_GS7 = 104,
    MUSE_A7 = 105,
    MUSE_AS7 = 106,
    MUSE_B7 = 107,
    MUSE_C8 = 108,
    MUSE_CS8 = 109,
    MUSE_D8 = 110,
    MUSE_DS8 = 111,
    MUSE_E8 = 112,
    MUSE_F8 = 113,
    MUSE_FS8 = 114,
    MUSE_G8 = 115,
    MUSE_GS8 = 116,
    MUSE_A8 = 117,
    MUSE_AS8 = 118,
    MUSE_B8 = 119,
    MUSE_C9 = 120,
    MUSE_CS9 = 121,
    MUSE_D9 = 122,
    MUSE_DS9 = 123,
    MUSE_E9 = 124,
    MUSE_F9 = 125,
    MUSE_FS9 = 126,
    MUSE_G9 = 127
};

class MUSETimer {
  private:
      void (*callback)();
      unsigned long lastUpdate;
      unsigned long interval;
      
  public: 
      MUSETimer() {
      }
      MUSETimer(void (*func)(), unsigned long i) : 
          callback(func), interval(i), lastUpdate(0) {
      }

      bool isReady() {
        return millis()-lastUpdate > interval;
      }

      void callCallback() {
        callback();
        lastUpdate = millis();
      }
};

// defaults to pullup resistor and readings must be sustained for 50 milliseconds for a change to be detected (debounced)
class MUSEDigitalInput {
    private:
        bool state;
        bool lastReading;
        unsigned long int lastReadingTime;

        int pin;
        unsigned int debounce_time;

        void (*callback)(bool);

    public:
        MUSEDigitalInput() {
        }
        MUSEDigitalInput(void (*func)(bool), int p, bool pullup=1, unsigned int deb=50) : callback(func), pin(p), debounce_time(deb) {
            state = HIGH;
            lastReading = HIGH;
            lastReadingTime = millis();

            if(pullup) {
                pinMode(pin, INPUT_PULLUP);
            } else {
                pinMode(pin, INPUT);
            }
        }

        void callCallback() {
            callback(state);
        }

        bool didStateChange() {
            int reading = digitalRead(pin);
            if(reading != lastReading) {
              lastReading = reading;
              lastReadingTime = millis();
            }

            if(millis()-lastReadingTime > debounce_time) {
                if(lastReading != state) {
                  state = lastReading;
                  return true;
                }
            }
            return false;
        }
};

class MUSE {
    private:
        unsigned long int baud;
        MUSETimer timers[MUSE_TIMERS];
        int numTimers;

        MUSEDigitalInput digitalInputs[MUSE_DIGITAL_INPUTS];
        int numDigitalInputs;

    public:
        MUSE(unsigned long int b = 115200) : baud(b), numTimers(0), numDigitalInputs(0) {
        }

        void registerTimerCallback(void (*func)(), unsigned long i) {
            timers[numTimers] = MUSETimer(func, i);
            numTimers++;
        }

        void registerDigitalInputCallback(void (*func)(bool), int p, bool pullup=0, unsigned int deb=50) {
            digitalInputs[numDigitalInputs] = MUSEDigitalInput(func,p,pullup,deb);
            numDigitalInputs++;
        }

        void setup() {
            MIDI.begin(MIDI_CHANNEL_OFF);
            Serial.begin(baud); 
        }

        void loop() {
            for(int i = 0; i < numTimers; i++) {
                if(timers[i].isReady()) {
                  timers[i].callCallback();
                }
            }

            for(int i = 0; i < numDigitalInputs; i++) {
                if(digitalInputs[i].didStateChange()) {
                    digitalInputs[i].callCallback();
                }
            }
        }

        void noteOn(MUSENote note) {
            MIDI.sendNoteOn((int)note, 90, 5);
        }

        void noteOff(MUSENote note) {
            MIDI.sendNoteOff((int)note, 0, 5);
        }

        void noteOn(int note) {
            MIDI.sendNoteOn(note, 90, 5);
        }

        void noteOff(int note) {
            MIDI.sendNoteOff(note, 0, 5);
        }

        void playNote(MUSENote note, int duration) {
            MIDI.sendNoteOn((int)note, 90, 5);
            delay(duration);
            MIDI.sendNoteOff((int)note, 0, 5);
            delay(10);
        }

        void rest(int duration) {
            delay(duration);
        }
};

#endif
