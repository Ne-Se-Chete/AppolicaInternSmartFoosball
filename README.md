
![Header](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/Header.png)

# AppolicaSmartJagi

This project was developed during our internship at Appolica as part of an IoT system designed for a foosball table. Our system is built around an ESP32 microcontroller and integrates various sensors and components to automate score tracking, provide real-time statistics, and offer a modern twist to the classic foosball game.


# Hardware Components

![foosball img](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/foosball1.jpg?raw=true)

- ESP32: The central microcontroller used for handling all the inputs, outputs, and Wi-Fi communication.
- Phototransistors: Initially, we started with photoresistors to detect the ball passing through the goals. However, we found that photoresistors were too slow to handle fast-paced foosball shots. We switched to phototransistors because of their faster response time, making them better suited for this application.
- Lasers: Paired with the phototransistors, lasers are used to detect when a goal is scored. The laser beams are positioned across the goalposts, and when interrupted by the ball, the phototransistor registers the event.
- Buzzer: A buzzer is used to provide audible feedback when a goal is scored.
- Display: A local display shows the current score, providing immediate feedback to players.
- Manual Buttons: We added manual "+" and "-" buttons to allow players to adjust the score in case of system errors or missed detections.

# Demo
We installed the frontend on a TV in the office:
![office](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/office.jpg?raw=true)
We developed a mobile version:
![mobile1](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/mobile1.jpg?raw=true)
![mobile1](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/mobile2.jpg?raw=true)
![mobile1](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/mobile3.jpg?raw=true)


# Usage

- Connect the ESP32 to the foosball table with the phototransistors, lasers, buzzer, display, and buttons as in the wiring diagram.
- Upload the code to the ESP32 (make sure you change the pins in the code accordinly to the schematic)
- ![wiring](https://github.com/Ne-Se-Chete/AppolicaInternSmartFoosball/blob/main/images/wiring.png?raw=true)

- Make sure you align the phototransistors to be lighted by the lasers.
- Power On: Power on the ESP32, and it will automatically start detecting goals and updating the display.
- View Stats: Open the Bubble.io app (unfortunately closed source) to view real-time scores and statistics.
- Adjust Scores: Use the manual buttons on the foosball table to adjust the score if needed.

# Future Improvements
- Enhanced Accuracy: Further fine-tuning of the phototransistor and laser setup to ensure 100% accurate goal detection.
- Additional Features: Integration of player identification for personalized statistics and tracking.
- Discord / Slack bot for even more fun!

# Development
How we worked:

Simeon - Bubble.io app
Valeri - Bubble.io app + Embedded
Borislav - Bubble.io app + vacation
Yasen - Embedded

# Contribute
This project was developed by [Ne Se Chete]. We appreciate any feedback or suggestions for further improvements!


# License

This project is licensed under the [MIT license](./LICENSE). Please see the LICENSE file for more details.


