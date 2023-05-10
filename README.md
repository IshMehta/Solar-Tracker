# Solar-Tracker
Final project for CS 3651- Prototyping Intelligent Devices


![Final Build](/Image/IMG.jpg)


## Description
Solar energy is one form of energy cleaner than fossil fuels, and can be harnessed even more effectively with a device that can follow the sun’s movements and have dust on the surface automatically cleared.

For this project, we will build a proof of concept device that will maximise the energy produced by a solar system. This concept relies on phototransistors positioned at 4 corners of a square to periodically check where the brightest direction is and use 2 servo motors to orient a solar panel in two dimensions toward that direction. It will also use a mobile metal plate that can create an electric field that will repel dust from the surface. Since this method requires a very large voltage to be applied in the order of KiloVolts, it might not be feasible to recreate in a lab. In that case, we will replace the metal plate with a brush or viper in order to do the cleaning. The routine in which the metal plate is used to clear the dust will be executed either when an RFID scan of a matching tag is registered or at a specified time interval.

To demonstrate the potential for solar panel use in infrastructure, we plan to use the solar panel to power an LED-based miniature traffic light. 

### Structure
The structure has been laser cut from 5mm wood. The laser cut STL desgin files can be found in this repostiory. 

### Solar Tracking
We have 4 photoresistors positioned in opposite corners of a rectangle and use the readings from each corner to determine which direction is receiving the most light. Each photoresistor is accompanied by a 10,000 ohms resistor.

We have 2 servos positioned such that they can move the solar panel to follow the direction with the most light. We used [fixed-rotation metal gear servos](https://www.amazon.com/dp/B07L6FZVT1?psc=1&ref=ppx_yo2ov_dt_b_product_details) in order for the structure to be able to handle the weihght of the panel and the celaning mechanism.

### Self-cleaning Mechanism
The mechanism was 3D printed, and the design files can be found in this repository. We used a fixed-rotation servo that was modified for continuous rotation. We wired this to run back-and-forth over the solar panel if a “clean” command was entered.

For more information, refer to the Project Dosumentation pdf. 

-------------------
*This project was made in collaboration with [Brooke Christiansen](https://www.linkedin.com/in/brooke-christiansen/).*
