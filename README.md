# Arduino-Based Ultrasonic Distance Measurement and Analysis System

## 📌 Overview
This project implements a smart IoT-based distance measurement and monitoring system using **Arduino Uno**, **HC-SR04 ultrasonic sensor**, and **ESP32-CAM**.  
The system measures the distance of nearby objects, triggers alerts when they cross a threshold, and sends remote notifications via **Telegram Cloud**.  

Applications include:
- Smart parking assistance  
- Security surveillance  
- Obstacle detection in robotics  
- Industrial automation  


## 🎯 Objectives
- Design and implement a low-cost distance measurement system.  
- Accurately measure distances using ultrasonic waves.  
- Display readings in real time on an LCD.  
- Trigger alerts (buzzer + LEDs) when unsafe proximity is detected.  
- Enable remote monitoring via ESP32-CAM and Telegram bot.  


## ⚙️ Components Used
- **Arduino Uno** – main controller  
- **Ultrasonic Sensor (HC-SR04)** – distance measurement  
- **ESP32-CAM / ESP8266** – Wi-Fi + image capture  
- **16x2 LCD Display** – real-time readings  
- **Piezo Buzzer** – audible alerts  
- **LEDs** – visual indicators  
- **Telegram Bot** – cloud notifications  



## 🔄 Methodology
1. Ultrasonic sensor continuously measures distance.  
2. If distance < threshold (e.g., 20 cm):  
   - Buzzer + LEDs trigger locally.  
   - ESP32-CAM captures an image.  
   - Alert/image sent to Telegram bot.  
3. LCD displays live distance + servo angle.  



## 📊 Results
- Operational range: **2 cm – 400 cm**  
- Average error: **~1.3%**  
- Example accuracy:  
  - 10 cm → 10.2 cm (2% error)  
  - 100 cm → 99.5 cm (0.5% error)  
  - 200 cm → 198.6 cm (0.7% error)  


## ✅ Conclusion
- Accurate, reliable, low-cost measurement system.  
- Average error < 2%.  
- Suitable for robotics, parking assistance, tank level detection, and security systems.  


## 🔮 Future Scope
- Wireless communication (ESP8266, Bluetooth HC-05).  
- Temperature compensation (DHT11/LM35).  
- Multiple sensors for 3D mapping.  
- IoT dashboards for logging.  
- Touchscreen/mobile app interface.  

---

## 💻 Code
The full Arduino code is available in the repository under `ultrasonic_distance.ino`.


## 📷 Media

