# ⚙️ Mini-Project-BSI-TVETMARA-Ledang

## Things to do (Mark X if done documented)
- [x] Introduction to what youre gonna do
- [x] Components youre gonna use
- [x] Workflow Explanation (Library Preruisites)
- [x] Flowchart
- [x] Circuit diagram
- [x] Prototype setup
- [x] Source Code
- [x] Blynk Config (Both web and mobile)
- [ ] Design Sketches
- [x] Final Product
- [ ] Conclusion

### 💡 Introduction
In this project, Im doing the flame and smoke monitoring using ESP32. linked using Blynk. yeah its pretty easy. In this readme I will be giving rundown on how I made this project. So less yapping, lets get to it

### 🛠️ Components used
Links are given
1. ESP32 [Product Link](https://my.cytron.io/p-nodemcu-esp32-with-expansion-board)
2. OLED I2C 0.96Inch 128x64 Blue Display [Product Link](https://my.cytron.io/p-oled-rohs-i2c-0.96inch-128x64-blue-display)
3. Passive Buzzer [Product Link](https://my.cytron.io/p-buzzer-passive-with-jumper-housing)
4. MQ2 Smoke Sensor Module [Product Link](https://my.cytron.io/p-mq2-smoke-lpg-co-sensor-module)
5. Flame Sensor Module [Prodict Link](https://my.cytron.io/p-flame-sensor-module) 
6. Breadboard [Product Link](https://my.cytron.io/p-breadboard-mini-170-holes-35mmx42mm)
7. Jumper [Product Link](https://my.cytron.io/p-40-way-20cm-dupont-jumper-wire)

### 📝 Workflow 
1. In this project, there are few libraries that we need to install before the code can be working properly. Pictures are given below :
<img width="250" height="220" alt="image" src="https://github.com/user-attachments/assets/ebda3e45-8f67-4aa2-98c7-1a55c721897b" />
<img width="250" height="220" alt="image" src="https://github.com/user-attachments/assets/3c92f6e9-3e40-4f58-8569-779e333a33ea" />
<img width="250" height="220" alt="image" src="https://github.com/user-attachments/assets/98af5dc6-1067-4c03-b6f2-b7626d653c75" />

2. After installing the library, we first connect all the components into the breadboard to form a prototype circuit. The schematic and the physical setup picture can be seen on the Circuit Diagram and Prototype Setup.
> Connect the components together

3. After all the components hooked up, we can start by testing each components. Source code can be found in the Source Code section.
> Test each component

4. When the testing are completed and all the components are verified to be working as god intended, we can move on to combining all the coding into a singular system. You can open the file labelled "Mini_Project_BSI_V1".
> Combine all the code into one single file, check the file labelled V1 at the end for reference

5. When the system works, we can continue to configure our blynk server for IoT integration. The datastreams and dashboard are shown below :
<img width="1064" height="439" alt="Blynk Datastreams" src="https://github.com/user-attachments/assets/f8e5a5b3-6589-459e-acd3-9db45a85ea1d" />
<img width="1064" height="439" alt="Blynk Web Dashboard" src="https://github.com/user-attachments/assets/aa7d3217-e00e-4f05-905a-6f2a369e0e9c" />
<img width="439" height="1064" alt="Blynk Mobile App Dashboard" src="https://github.com/user-attachments/assets/43b5980d-bac8-4bcc-a43a-dbb078f72494" />

> configure Blynk on website and mobile application

6. Use the previous code, and just add your authentication token, template ID and name. Include your WiFi ssid and password too so that your ESP32 can be connected to internet and Blynk server. Open file labelled "Mini_Project_BSI_V2" for reference on what Im talking about.
>  Modify the previous code so that it can be integrated with Blynk

7. Now our coding session is over, we will be moving on to the design section. We start by doing sketches and build it. This time we dont 3D print it because budget is tight. Core ideas and concept can be viewed in the Design Sketches and Final Product section,
> Design and manfacture the casing of the project
