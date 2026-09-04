# 🤖 13-DOF Humanoid Robot

A 13-DOF humanoid robot developed using servo motors, an ESP32 microcontroller, and a PCA9685 servo driver. The project focuses on controlling multiple joints to achieve humanoid robot movements, including standing and walking.

---

## 📌 Project Overview

This project involves the design and development of a 13-DOF humanoid robot capable of controlling multiple joints using servo motors.

The ESP32 acts as the main controller and communicates with the PCA9685 servo driver through I2C. The PCA9685 provides control for the multiple servo motors used throughout the robot's body.

The robot was developed with the goal of creating coordinated humanoid movements and demonstrating basic walking motion.

---

## 🎯 Objectives

- Build a functional 13-DOF humanoid robot.
- Control multiple servo motors simultaneously.
- Use ESP32 as the main microcontroller.
- Control the servos using a PCA9685 servo driver.
- Develop coordinated joint movements.
- Implement basic humanoid walking motion.
- Explore robot balance and motion control.

---

## 🦾 Degrees of Freedom

The robot contains 13 degrees of freedom:

| Joint | Number of Servos |
|---|---:|
| Head Pan | 1 |
| Head Tilt | 1 |
| Left Shoulder | 1 |
| Left Elbow | 1 |
| Right Shoulder | 1 |
| Right Elbow | 1 |
| Left Hip | 1 |
| Left Knee | 1 |
| Left Ankle | 1 |
| Right Hip | 1 |
| Right Knee | 1 |
| Right Ankle | 1 |
| Waist | 1 |
| **Total** | **13** |

---

## 🔧 Hardware Components

- ESP32 Development Board
- PCA9685 16-Channel PWM Servo Driver
- 13 × Servo Motors (MG996R / MG995 type)
- MPU6050 IMU Sensor
- Humanoid Robot Frame
- External Servo Power Supply
- Connecting Wires
- Battery / Power Source

---

## 🔌 System Architecture

```text
                 ┌─────────────────┐
                 │      ESP32      │
                 │  Main Controller│
                 └────────┬────────┘
                          │
                     I2C (SDA/SCL)
                          │
                          ▼
                 ┌─────────────────┐
                 │     PCA9685     │
                 │  Servo Driver   │
                 └────────┬────────┘
                          │
          ┌───────────────┼───────────────┐
          │               │               │
          ▼               ▼               ▼
       Servos          Servos          Servos
      Head/Arms         Legs           Waist
