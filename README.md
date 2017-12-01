# SimpleExpressions: Make your robots cute and noisy

![image of a cute robot](https://raw.githubusercontent.com/s00500/SimpleExpressions/master/docs/greencheck.jpg)

This library simply takes a 7 LED Circle module and a buzzer to do lots of funny things, see for yourself.
The reason I made this was that I wanted to have a simple way to make combine mouths and sounds on this funny little Robots

You can buy these little ws2812 circles for a dollar or two at aliexpress and other china marketplaces and they are a really simple way to make some funny output. And a beeper or buzzer is available literally everywhere.

![The main parts](https://raw.githubusercontent.com/s00500/SimpleExpressions/master/docs/parts.png)


### Dependencies

Internally the library uses the **Adafruit NeoPixel Library**, so make sure you have this one installed

### Install

The library can be installed **manually** (by unzipping and copying the files to the "libraries" directory) or using the **Arduino Library installer**, there is not to much to care about, just make sure the **Adafruit NeoPixel Library** is also installed.

### Supported Platforms

The sound are taken from BQs Zowie. The Library supports all Arduino boards (that are compatible with the NeoPixel Library) and also the ESP8266 and ESP32

### Functions

Just see the example how everything works together

- SimpleExpressions.**init(ledPin, buzzerPin);**
Initializes the library with the given pins

- SimpleExpressions.**clearMouth();**
Clears the mouth and sets all pixels off

- SimpleExpressions.**printMouth(mouthNumber, red, green, blue);**
Prints a mouth by its number and using the given color, useful to iterate through all of them (use **frameCount** or **colorFrameCount** to determine the maximum number)
(use without the colorvalues for multicolor mouths)

- SimpleExpressions.**writeMouth("cross", red, green, blue);**
Does basically the same but you can select the mouth by its name (use without the colorvalues for multicolor mouths)

- SimpleExpressions.**writeMouthGeneric(moutharray)**
**Advanced:** Write a mouth straight from your code with color values fo all of the pixels

- SimpleExpressions.**playSound(SOUND_NUMBER);**
Plays a sound by its number using the constants you can find below.

- SimpleExpressions.**_tone(noteFrequency, noteDuration, silentDuration);**
Similar to the arduino tone function, but also working on ESP32 (using ledc)

- SimpleExpressions.**bendTones(note1Frequency, note2Frequency, prop, noteDuration, ilentDuration);**
Similar to the arduino tone function, but also working on ESP32 (using ledc)


### Available mouth shapes

#### single color shapes

- **zeros**
- **happySmall**
- **happyFull**
- **sadSmall**
- **sadFull**
- **neutral**
- **circle**
- **center**
- **hook**
- **upsidedownhook**
- **kooh**
- **upsidedownkooh**
- **cross**
- **rect**
- **leftarrow**
- **rightarrow**
- **lefthalf**
- **righthalf**

#### multi color shapes

- **colorCircle**

### Available SOUNDS

- **S_CONNECTION**
- **S_DISCONNECTION**
- **S_BUTTON_PUSHED**
- **S_MODE1**
- **S_MODE2**
- **S_MODE3**
- **S_SURPRISE**
- **S_OHOOH**
- **S_OHOOH2**
- **S_CUDDLY**
- **S_SLEEPING**
- **S_HAPPY**
- **S_SUPER_HAPPY**
- **S_HAPPY_SHORT**
- **S_SAD**
- **S_CONFUSED**
- **S_FART1**
- **S_FART2**
- **S_FART3**

- **PIRATES** The complete **PIRATES OF THE CARIBBEAN** theme (highly experimental, but funny =P)

### TODO

- If you have new Ideas for different shapes or multicolor shapes just write them down and create a pull request (Or if you are not familiar with git draw them and post an issue)
- Calculate frame count from arraysize
- Example for **writeMouthGeneric()**
- Currently I am happy with it, any Ideas? let me know

### Buy me a coffee ☕️

If you like the library and all my other projects maybe think about [buying me a coffee](https://paypal.me/lukasbachschwell/3).? I really like [coffee](https://paypal.me/lukasbachschwell/3). ☕️ 🙃

![another image of a cute robot](https://raw.githubusercontent.com/s00500/SimpleExpressions/master/docs/bluearrow.jpg)
