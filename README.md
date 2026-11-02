## About

# 🎮 Terminal-Based Tic-Tac-Toe in C

A clean, robust, and interactive implementation of the classic Tic-Tac-Toe game built entirely from scratch in **C**. Designed and coded to master low-level programming concepts, game loops, memory models, and Git workflow mechanics under the hood.

---

## 🚀 Features

* **Two Game Modes:**
  * **1. Multiplayer (Local):** Play head-to-head with a friend on the same machine (`Player 1: 'o'` vs `Player 2: 'x'`).
  * **2. Player vs AI:** Test your skills against an AI opponent (`You: 'o'` vs `AI: 'x'`).
* **Bulletproof Input Validation:** 
  * Prevents game crashes and infinite loops by handling character/string typing errors (`scanf` buffer clearing).
  * Restricts inputs strictly to slots `1` through `9`.
  * Blocks players and AI from overwriting already occupied positions.
* **Seamless Replay Loop:** Enjoy continuous gameplay with a dynamic post-game replay prompt without needing to restart the executable.
* **Dynamic Terminal Interface:** Real-time ASCII grid rendering utilizing ANSI/system screen clears for a smooth, app-like visual experience.

---

## 🛠️ Tech Stack & Requirements

* **Language:** C (C99 standard)
* **Compiler:** GCC / MinGW
* **Environment:** Visual Studio Code (Windows CMD / PowerShell)

---
