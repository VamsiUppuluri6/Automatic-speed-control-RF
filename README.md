# 🚗 Automatic Speed Control in Restricted Areas using RF Modules

## 📌 Overview
This project demonstrates an **automatic vehicle speed regulation system** for restricted areas such as **school zones, hospitals, and pedestrian-heavy areas**. Using **RF transmitters and receivers**, the vehicle detects zone-specific speed limits and adjusts its motor speed automatically. A **notification unit (LCD + buzzer)** alerts the driver when entering such areas.

The system was implemented on a **prototype model car**, proving the feasibility of RF-based speed regulation.

---

## 🎯 Objectives
- Enforce speed control **automatically** without driver intervention.  
- Reduce road accidents in **sensitive zones**.  
- Provide **real-time driver notifications** about speed restrictions.  
- Create a **low-cost, scalable prototype** that can evolve into a real-world solution.  

---

## ⚙️ System Architecture
The system is divided into **two parts**:

1. **Transmitting Side (Zone Unit)**  
   - RF transmitter placed in restricted areas.  
   - Continuously broadcasts a unique code corresponding to the zone’s speed limit.  

2. **Receiving Side (Vehicle Unit)**  
   - RF receiver mounted on vehicle.  
   - Arduino Uno decodes the code.  
   - Motor driver (L293D) regulates motor speed accordingly.  
   - LCD + buzzer notify the driver about speed restrictions.  

---

## 🔧 Hardware Components
| Component           | Function |
|---------------------|----------|
| Arduino Uno         | Decodes signals and regulates motor speed |
| RF Transmitter 433 MHz | Placed in restricted zones, broadcasts unique codes |
| RF Receiver         | Captures transmitted code in the vehicle |
| Motor Driver (L293D)| Controls DC motor using PWM signals |
| DC Motor            | Represents vehicle propulsion |
| LCD Display (16x2)  | Displays zone and speed limit |
| Buzzer              | Alerts driver when entering a restricted zone |

---

## 📐 Diagrams
### Block Diagram  
![Block Diagram](diagrams/block_diagram.png)

### Flowchart  
![Flowchart](diagrams/flowchart.png)

---

## 💻 Working Principle
1. RF transmitters broadcast **zone-specific codes**.  
2. The RF receiver inside the vehicle **receives and decodes** these signals.  
3. Arduino compares the current speed with the **zone speed limit**.  
4. If overspeeding → **PWM is reduced gradually**, slowing down the motor.  
5. Driver receives alerts via **LCD + buzzer**.  
6. Upon **exiting the zone**, vehicle speed returns to normal.  

---

## 🛠️ Arduino Code
All Arduino sketches are inside the [Arduino](./Arduino) folder:
- `RF_Transmitter.ino` → Broadcasts zone code.  
- `Vehicle_Control.ino` → Receives code & regulates speed.  
- `Notification_Module.ino` → Alerts driver with LCD + buzzer.  

---

## 📊 Prototype Results
- A toy car model was used for demonstration.  
- Zones with **30 km/h and 40 km/h limits** were simulated.  
- The vehicle automatically slowed down when entering restricted zones.  
- LCD showed the limit and buzzer sounded on entry.  
- The system proved effective in **enforcing speed limits** at the prototype level.  

---

## 🚀 Future Improvements
- Replace RF with **GPS-based detection** for more reliable scaling.  
- Integrate with **CAN bus** for real automotive systems.  
- Enable **IoT/cloud logging** of compliance data.  
- Mobile app for parents/authorities to monitor compliance.  
- Add **braking system integration** for stronger enforcement.  

---

## 📑 Documentation
A detailed **project report** is included:  
- [📄 Project_Document.pdf](./Project_Document.pdf)  
- [📝 Project_Document.docx](./Project_Document.docx)  

---

## 🏁 Conclusion
This project provides a **proof-of-concept solution** for automatic speed control in restricted areas. While implemented on a small prototype, the design is scalable with GPS, IoT, and advanced automotive integration — potentially reducing overspeeding accidents and improving road safety in real-world environments.  
