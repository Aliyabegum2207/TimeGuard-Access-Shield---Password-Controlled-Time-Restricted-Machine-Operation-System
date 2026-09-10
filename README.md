
# TimeGuard Access Shield

### Password-Controlled Time-Restricted Machine Operation System

TimeGuard Access Shield is an embedded security system designed to control machine operation based on **user authentication and predefined working hours**. The system allows machine access only to authorized users who enter the correct password during the permitted time window. The machine is automatically restricted when the working time expires or when authentication fails, helping prevent unauthorized usage and improving operational safety.

---

## 📌 Project Overview

In many industrial and embedded applications, machines should operate only during authorized working hours and should not be accessible to unauthorized users.

TimeGuard Access Shield provides a simple embedded solution by combining:

* Password-based authentication
* Real-time clock monitoring
* Predefined machine working hours
* LCD-based user interface
* Keypad-based password entry
* Automatic access restriction

The system continuously checks both the **entered password** and the **current RTC time** before allowing machine operation.

---

## 🎯 Objectives

The main objectives of this project are:

1. To provide password-based machine access.
2. To allow machine operation only during predefined working hours.
3. To prevent unauthorized access.
4. To automatically restrict operation outside the permitted time.
5. To provide a simple user interface using LCD and keypad.
6. To use an RTC for accurate time-based access control.
7. To improve machine safety and prevent misuse.

---

## ⚙️ Hardware Used

| Component    | Purpose                         |
| ------------ | ------------------------------- |
| LPC2148      | Main microcontroller            |
| 16x2 LCD     | Displays system status and menu |
| 4x4 Keypad   | Password and menu input         |
| RTC          | Maintains current date and time |
| LED          | Indicates machine/access status |
| Power Supply | Provides required power         |

---

## 🔌 Interfaces Used

| Peripheral | LPC2148 Interface               |
| ---------- | ------------------------------- |
| LCD        | GPIO                            |
| 4x4 Keypad | GPIO                            |
| RTC        | GPIO / configured RTC interface |
| LED        | GPIO                            |


---

## 🧠 Main Features

### 1. Password Authentication

The system requires the user to enter a password before allowing machine access.

A default password is configured in the program.

Example:

```text
Default Password: 1234
```

The password can be changed through the password-management option.

---

### 2. Time-Based Access Control

The system checks the current RTC time against the configured machine working hours.

Example:

```text
Machine ON Time  : 09:15
Machine OFF Time : 20:15
```

The machine is permitted to operate only within the configured time period.

---

### 3. Unauthorized Access Prevention

If an incorrect password is entered, the system does not allow machine access.

The user can retry the authentication process according to the programmed security logic.

---

### 4. Automatic Time Restriction

When the configured working period expires, machine operation is automatically restricted.

This prevents the machine from continuing to operate outside the authorized time window.

---

### 5. LCD Interface

The LCD provides information such as:

```text
ENTER PASSWORD
ACCESS GRANTED
ACCESS DENIED
RTC
WORKING HOURS
PASSWORD
EXIT
```

---

### 6. Keypad Interface

The 4x4 keypad is used for:

* Password entry
* Menu navigation
* Password modification
* Entering configuration values
* Backspace/delete operations

---

## 🖥️ System Menu

The system provides a menu-based interface.

Example:

```text
1. RTC
2. WORKING HOURS
3. PASSWORD
4. EXIT
```

The user can select the required option through the keypad.

---

## 🔄 Working Principle

The basic working sequence is:

```text
                 START
                   |
                   ↓
          Initialize LPC2148
                   |
                   ↓
        Initialize LCD / Keypad
                   |
                   ↓
             Read RTC
                   |
                   ↓
       Check Current Time
                   |
             ┌─────┴─────┐
             ↓           ↓
        Within Time   Outside Time
             |           |
             ↓           ↓
      Ask Password    Access Denied
             |
             ↓
       Verify Password
             |
       ┌─────┴─────┐
       ↓           ↓
    Correct      Wrong
       |           |
       ↓           ↓
 Access Granted  Access Denied
       |
       ↓
 Machine Operation
       |
       ↓
 Continuously Monitor Time
       |
       ↓
 Time Expired?
       |
       ↓
 Restrict Machine
```

---

## 🔐 Access Control Logic

The system performs two major checks:

### Check 1 — Time

```text
Is current time within the permitted working hours?
```

If **NO**:

```text
Access Denied
```

If **YES**, the system proceeds to password verification.

### Check 2 — Password

```text
Is entered password equal to stored password?
```

If **YES**:

```text
Access Granted
```

If **NO**:

```text
Access Denied
```

Therefore:

```text
Access = Valid Time AND Correct Password
```

---

## 🕒 Configured Working Hours

The current configuration is:

```text
ON Time  : 09:15
OFF Time : 20:15
```

These values can be modified according to the application requirements.

---

## 🛠️ Software / Development Environment

The project was developed using embedded C for the LPC2148 microcontroller.

### Programming Language

* Embedded C

### Microcontroller

* NXP LPC2148 / ARM7TDMI-S

### Development Tools

* Keil µVision
* Embedded C
* LPC2148 development hardware

---

## 📁 Source Code

The source code is organized into separate modules for easier maintenance.

Example:

```text
src/
│
├── main.c
├── lcd.c
├── lcd.h
├── keypad.c
├── keypad.h
├── rtc.c
├── rtc.h
├── delay.c
├── delay.h
├── types.h
└── defines.h
```

### Module Description

| File         | Purpose                                  |
| ------------ | ---------------------------------------- |
| `main.c`     | Main application logic                   |
| `lcd.c/h`    | LCD initialization and display functions |
| `keypad.c/h` | Keypad scanning and input                |
| `rtc.c/h`    | RTC configuration and time handling      |
| `delay.c/h`  | Delay functions                          |
| `types.h`    | Data type definitions                    |
| `defines.h`  | Project constants/macros                 |

---

## 🧩 Technologies / Concepts Used

This project demonstrates knowledge of:

* Embedded C
* ARM7 architecture
* LPC2148 microcontroller
* GPIO programming
* LCD interfacing
* 4x4 keypad interfacing
* RTC
* Password authentication
* Time-based control
* Menu-driven embedded applications
* Hardware/software integration

---

## 🚀 How the System Works

### Step 1 — System Initialization

After power-on, the LPC2148 initializes the required peripherals.

```text
LPC2148
   |
   ├── LCD
   ├── Keypad
   ├── RTC
   └── LED
```

### Step 2 — Read Current Time

The RTC provides the current time.

The controller compares the current time with the configured ON and OFF times.

### Step 3 — Authenticate User

If the current time is valid, the system asks the user to enter the password.

### Step 4 — Verify Password

The entered password is compared with the configured password.

### Step 5 — Allow or Deny Operation

Correct password:

```text
ACCESS GRANTED
```

Incorrect password:

```text
ACCESS DENIED
```

### Step 6 — Monitor Working Time

Even after access is granted, the system monitors the RTC.

When the OFF time is reached, machine access is restricted.

---

## 🔒 Security Logic

The project provides multiple levels of access control:

```text
                User
                  |
                  ↓
          Check Working Time
                  |
          ┌───────┴───────┐
          ↓               ↓
       Valid            Invalid
          |               |
          ↓               ↓
    Ask Password      Access Denied
          |
     ┌────┴────┐
     ↓         ↓
 Correct     Wrong
     |         |
     ↓         ↓
  Allowed    Denied
```

---

## 💡 Applications

This concept can be extended to:

* Industrial machines
* Factory equipment
* Laboratory equipment
* Restricted electrical systems
* Automated production machines
* Office equipment
* School/college laboratory systems
* Access-controlled embedded systems

---

## 🔮 Future Enhancements

The project can be further improved by adding:

* RFID authentication
* Fingerprint authentication
* OTP-based authentication
* GSM alerts
* IoT/cloud monitoring
* Remote configuration
* Multiple user accounts
* Event logging
* EEPROM-based password storage
* Tamper detection
* Automatic machine shutdown relay control
* Mobile application integration

---

## 📊 Advantages

* Simple and low-cost implementation
* Password-based authentication
* Time-based machine access
* Prevents unauthorized operation
* Easy LCD/keypad interface
* Modular embedded software
* Can be extended for industrial applications

---

## ⚠️ Limitations

* Basic password authentication
* Single-controller architecture
* No remote monitoring in the current version
* Security depends on the implemented password mechanism
* Actual machine isolation requires appropriate external switching/protection hardware

---

## Block Diagram
<img width="658" height="436" alt="Screenshot (24)" src="https://github.com/user-attachments/assets/4f93706a-b2a1-4365-889d-8e9d8479875e" />




## 👩‍💻 Author

**Aliya Begum**

B.Tech Graduate
Embedded Systems / Embedded Software Enthusiast

---
---

## 📌 Keywords

```text
LPC2148
ARM7
Embedded C
Embedded Systems
GPIO
LCD Interfacing
Keypad Interfacing
RTC
Password Authentication
Access Control
Time-Based Control
Industrial Automation
Machine Safety
Embedded Software
```

---

