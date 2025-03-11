# **MiniPIX Image Acquisition System**  

Automated image acquisition and device control for MiniPIX sensors using C++ and C#.

### **Overview**
This project provides an interface to control the MiniPIX radiation sensor using pxcore.dll. It enables automated single-frame acquisition, device status validation, and structured data organization. The system supports both standalone image acquisition and integration with external hardware (e.g., stepper motor-controlled rotation tables).

### **Features**
Hardware Connectivity Validation – Checks if the MiniPIX device is properly connected before performing any operation.
Automated Image Acquisition – Captures single frames upon request.
Dynamic Data Organization – Saves images and metadata in structured directories based on date and iteration count.
Error Handling and Logging – Detects and reports device failures or missing connections.
Flexible Integration – Available as a standalone C# console application and a DLL for third-party integration.


## **How It Works**
### **1. Device Initialization**
The system initializes the MiniPIX sensor by calling pxcInitialize().
It verifies whether a device is connected using pxcGetDevicesCount().
If no device is detected, an error message is displayed, and the program exits.
### **2. Image Acquisition Process**
The system retrieves device dimensions using pxcGetDeviceDimensions().
A single frame is measured using pxcMeasureSingleFrameTpx3().
The frame is saved in PNG format using pxcSaveMeasuredFrame().
Additional metadata (like ToA/ITot values) is stored in a text file.
### **3. Directory and File Naming System**
The system organizes acquired images by creating a folder for each date (DD-MM-YYYY).
If the folder already exists, images are saved inside it, with an incremental iteration number.
*Example:*

Copy
Edit
C:\Measurements  
├── 10-12-2024  
│   ├── frame_001.png  
│   ├── MeasuredFrame_001.txt  
│   ├── frame_002.png  
│   ├── MeasuredFrame_002.txt  

### **4. Error Handling and Safe Exits**
If device initialization fails, an error is logged.
If an image capture attempt fails, the program reports the error and does not overwrite previous data.
At the end of execution, pxcExit() ensures a clean shutdown of the MiniPIX sensor.

### **5. Integration with External Systems**
The program can be triggered externally (e.g., by a stepper motor control system).
When used as a DLL, external applications can call AcquireImage() to trigger an image capture after each motor rotation.


## **Usage**
### **Standalone Execution**
Run the executable to start the image acquisition process:

*MiniPIXApp.exe*
The program will automatically:
1. Check for the connected MiniPIX device.
2. Acquire a single frame.
3. Save the image and metadata in the respective directory.

### **DLL Integration**
The system provides a DLL (MiniPIXLibrary.dll) for use in other applications.
External programs can invoke:
csharp

_MiniPIXLibrary pix = new MiniPIXLibrary();
pix.InitializeDevice();
pix.AcquireImage();_

This allows automated image acquisition after events like stepper motor rotations.

## **Example Output**
### **Console Log Example:**

Initializing...  
Device detected: 1  
Using existing directory: C:\Measurements\10-12-2024  
Measuring a single frame...  
Frame measurement successful.  
Saved frame to C:\Measurements\10-12-2024\frame_003.png  
Frame data saved to C:\Measurements\10-12-2024\MeasuredFrame_003.txt  
Exiting...  

![Image](https://github.com/user-attachments/assets/742e6a2d-9cec-476f-8272-8bbdb45bc3d4)
![Image](https://github.com/user-attachments/assets/af446f1b-e546-4a13-b5ed-25ac734eb6f1)
