# OpenGL Gereja Taman Sari Salatiga

A simple OpenGL project that visualizes a traditional **Gereja Taman Sari** using C++ and the FreeGLUT library. This project was developed as part of a graphics programming assignment.

## 🖥️ Features

- 3D rendering of a traditional Bengkulu house  
- Camera controls using keyboard input  
- Textured surfaces with bitmap (.bmp) image support  
- Built using OpenGL (FreeGLUT) and C++  

## 🧱 Project Structure
├── imageloader.cpp # Bitmap image loader
├── imageloader.h # Header for image loader (required)
├── main.cpp # Main OpenGL rendering logic
├── Makefile # For building the project

## 🛠️ Requirements

- **Windows**  
- **MSYS2** environment (with MINGW64)  
- Packages:  
  - `mingw-w64-x86_64-gcc`  
  - `mingw-w64-x86_64-freeglut`  
  - `mingw-w64-x86_64-make`  

Install MSYS2 and the required packages:

```bash
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-freeglut mingw-w64-x86_64-make

make
./main.exe

g++ main.cpp imageloader.cpp -o main.exe -lglu32 -lopengl32 -lfreeglut
```

## 📖 Goal

This repository serves as a learning log, a reference for University Class Exam, and a contribution to the open-source learning community.

---

## 🧑‍💻 Author

**Aldyth Nahak**  
[LinkedIn](https://linkedin.com/in/aldythnahak) | [GitHub](https://github.com/AldythNahak)

---

## ⭐️ Contribute or Follow

Feel free to fork, clone, or star this repo if you find it helpful!
