Here's your **enhanced** and **visually appealing** `README.md` file for GitHub:  

---

# 🚀 **MiniPIX Image Acquisition System**  
![Build](https://img.shields.io/badge/build-passing-brightgreen)  
![Version](https://img.shields.io/badge/version-1.0-blue)  
![License](https://img.shields.io/badge/license-Apache%202.0-red)  

_Automated image acquisition and device control for **MiniPIX sensors** using C++ and C#._  

---

## 📖 **Table of Contents**
- [📌 Overview](#overview)  
- [⚡ Features](#features)  
- [🔧 How It Works](#how-it-works)  
- [🚀 Usage](#usage)  
- [📂 DLL Integration](#dll-integration)  
- [📊 Example Output](#example-output)  
- [📝 License](#license)  

---

## 📌 **Overview**  
The **MiniPIX Image Acquisition System** provides an interface to control the **MiniPIX radiation sensor** using `pxcore.dll`.  
It enables:  
✅ **Automated single-frame acquisition**  
✅ **Device status validation**  
✅ **Structured data organization**  

The system supports both **standalone image acquisition** and **integration with external hardware (e.g., stepper motor-controlled rotation tables).**  

---

## ⚡ **Features**
✔️ **Hardware Connectivity Validation** – Checks if the MiniPIX device is properly connected before performing any operation.  
✔️ **Automated Image Acquisition** – Captures **single frames** upon request.  
✔️ **Dynamic Data Organization** – Saves images and metadata in **structured directories** based on **date and iteration count**.  
✔️ **Error Handling and Logging** – Detects and reports **device failures or missing connections**.  
✔️ **Flexible Integration** – Available as a **standalone C# console application** and a **DLL** for **third-party integration**.  

---

## 🔧 **How It Works**  

### **1️⃣ Device Initialization**
- The system **initializes** the MiniPIX sensor using:
  ```csharp
  pxcInitialize();
  ```
- It **verifies connectivity** with:
  ```csharp
  pxcGetDevicesCount();
  ```
- If **no device is detected**, an error message is displayed, and the program **exits gracefully**.

### **2️⃣ Image Acquisition Process**
- The system retrieves device dimensions using:
  ```csharp
  pxcGetDeviceDimensions();
  ```
- A **single frame** is measured using:
  ```csharp
  pxcMeasureSingleFrameTpx3();
  ```
- The **frame is saved** as **PNG** using:
  ```csharp
  pxcSaveMeasuredFrame();
  ```
- **Metadata** (ToA/ITot values) is stored in a **text file**.

### **3️⃣ Directory and File Naming System**
- The system organizes acquired images by **creating a folder for each date (`DD-MM-YYYY`)**.  
- If the folder **already exists**, images are saved inside it with an **incremental iteration number**.

📁 **Example Directory Structure:**  
```
C:\Measurements
├── 10-12-2024
│   ├── frame_001.png
│   ├── MeasuredFrame_001.txt
│   ├── frame_002.png
│   ├── MeasuredFrame_002.txt
```

### **4️⃣ Error Handling and Safe Exits**
✔️ If **device initialization fails**, an error is logged.  
✔️ If an **image capture attempt fails**, the program **does not overwrite previous data**.  
✔️ At the end of execution, **`pxcExit()`** ensures a **clean shutdown** of the MiniPIX sensor.  

### **5️⃣ Integration with External Systems**
- The program can be **triggered externally** (e.g., by a **stepper motor control system**).  
- When used as a **DLL**, external applications can call:
  ```csharp
  AcquireImage();
  ```
  - This enables **automated image acquisition** after **each motor rotation**.

---

## 🚀 **Usage**  

### ✅ **Standalone Execution**  
Run the executable to start the image acquisition process:  
```
MiniPIXApp.exe
```
The program will automatically:  
1️⃣ **Check for the connected MiniPIX device**.  
2️⃣ **Acquire a single frame**.  
3️⃣ **Save the image and metadata** in the respective directory.  

---

## 📂 **DLL Integration**  
The system provides a **DLL (`MiniPIXLibrary.dll`)** for use in other applications.  

### **How to Call DLL Methods in External Programs**
```csharp
MiniPIXLibrary pix = new MiniPIXLibrary();
pix.InitializeDevice();
pix.AcquireImage();
```
✔️ This allows **automated image acquisition** after **stepper motor rotations**.  

---

## 📊 **Example Output**  
### **Console Log Example:**
```
Initializing...
Device detected: 1
Using existing directory: C:\Measurements\10-12-2024
Measuring a single frame...
Frame measurement successful.
Saved frame to C:\Measurements\10-12-2024\frame_003.png
Frame data saved to C:\Measurements\10-12-2024\MeasuredFrame_003.txt
Exiting...
```

📸 **Example Images:**  
![Frame Image](https://github.com/user-attachments/assets/742e6a2d-9cec-476f-8272-8bbdb45bc3d4)  
![Measurement Data](https://github.com/user-attachments/assets/af446f1b-e546-4a13-b5ed-25ac734eb6f1)  

---

## 📝 **License**  
This project is licensed under the **Apache License 2.0**.  

📜 Read more at: [Apache License 2.0](https://opensource.org/licenses/Apache-2.0)  

For issues, reach out at dattatreya.mdesai1996@gmail.com
