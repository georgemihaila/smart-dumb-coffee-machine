Without spending a lot of money, I wanted to wake up to already brewed coffee. Here's how to make a smart dumb coffee machine using an ESP8266, HomeBridge and Google Assistant

Materials needed:

1. Dumb coffee machine
2. 1 x ESP8266
3. 1 x 5V relay
4. 1 x 3.3V PSU

You can start the coffee machine by pressing the start button so it's obvious that inside it there's a circuit that has to be closed.

After opening it up and finding the main control board, I discovered I had to close the circuit between the red and blue contacts.
![board](https://i.imgur.com/9EkeDSV.jpg)

I soldered two wires to a contact on each side,
![soldered wire](https://i.imgur.com/fuij3WG.jpg)
tested

![test](https://media1.giphy.com/media/eNM8gIAjgCTsQDTKvk/giphy.gif)

and put the circuit board back in its place.

I connected the wires to a relay (a transistor would have worked just fine)
![relay](https://i.imgur.com/n0FAVP8.jpg)

Used a cheap (as in expensive and low-quality) 3.3V PSU that needed an additional capacitor to power up the ESP8266 properly
![cheap PSU](https://i.imgur.com/moc9qiP.jpg)

Tested the whole thing again, split the power cord such that I could power everything up, tucked the whole thing in an empty spot on the inside and closed everything up. 
![final_inside](https://i.imgur.com/QNcE8Py.jpg)

Set up a stateless switch in HomeBridge pointing to the ESP8266, refreshed my Google Home connection and that was it.

![final](https://media0.giphy.com/media/S6rch403uXkhebA1om/giphy.gif)

Using the Google Clock app, I can start the coffee machine when my alarm rings in the morning.
