# MUSE - Music Using Simple Electronics

Play music using MIDI and simple circuits (such as touching an apple and a banana at the same time).

# Getting Started

Follow these instructions to get started.

## Install Arduino IDE

You'll need to install the Arduino IDE to program your device. You can download it [here](https://www.arduino.cc/en/Main/Software).


## Install Pololu Drivers

If you've purchased the kit for the Magical Musical Objects class at the Children's Museum of Bozeman STEAMlab, then the
Arduino you're using is called a Pololu A-Star Mini LV and it requires installing separate drivers for Windows. Follow [these
instructions, provided by Pololu](https://www.pololu.com/docs/0J61/6.1).

After the drivers have been installed, you should be able to select the Arduino Micro or Arduino Leonardo from the Board
menu as they use the same chip (ATmega 32U4). You can also add a Pololu A-Star 32U4 entry to the Board menu by following
the "Arduino add-on" section [here](https://github.com/pololu/a-star).

## Install MUSE library

Download the [MUSE Arduino library](https://github.com/AllwineDesigns/MUSE/archive/master.zip). Install the
library by following the instructions under [Importing a zip library](https://www.arduino.cc/en/Guide/Libraries#toc4) on Arduino's site.

## Playing music on your computer

To play music on your computer, there's some setup required so that your Arduino
can behave as a MIDI device.

### Install Hairless MIDI

MIDI is a protocol for digital music devices to communicate. Digital keyboards, for
example, use MIDI to communicate with your computer. Hairless MIDI allows your Arduino
to act as a MIDI device connected to your computer. You'll need to install and set
up Hairless MIDI by following the instructions [here](http://projectgus.github.io/hairless-midiserial/#getting_started). 

Windows users will need to download and install [loopMIDI](http://www.tobias-erichsen.de/software/loopmidi.html). Once installed,
run loopMIDI and click the + button to create a virtual MIDI port that Hairless MIDI will be able to send MIDI events to.

### MIDI synthesizer software

On a Mac, GarageBand is a great option for playing back your MIDI events. On Windows, [Anvil Studio](http://anvilstudio.com/) is a free application
that we used in the Magical Musical Objects class at the Children's Museum of Bozeman STEAMlab. You'll need to configure
your synthesizer to play the notes sent from 

## Play music on a digital keyboard (or other synthesizer)

To play music using a synthesizer, you can connect your Arduino using a MIDI cable (included with the kit, purchased from the Children's Museum of Bozeman STEAMlab). There's a single line
of code that you'll need to insert at the very top of your file to enable this behavior:

    #define MUSE_USE_SERIAL1
