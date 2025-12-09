# 🥩 Steak-Cooker  
A tiny C++ program that helps you figure out **how long to cook your steak** based on:

- Cooking method (skillet / oven / grill)  
- Thickness (in inches)  
- Doneness (rare → medium)  

It’s simple, quick, and probably *still not as accurate as Gordon Ramsay screaming at you*, but hey—it works.

---

## 📌 Features

- Ask user how they’re cooking the steak  
- Ask for steak thickness  
- Ask for doneness level  
- Calculate a cook time using preset multipliers  
- Basic input validation  
- Outputs a clean summary

---

## 📸 How It Works

The program uses a few structs:

- **Cookware** → holds the available cooking methods  
- **Steak** → stores thickness, chosen method, doneness, and final cook time  

Then it runs through three interactive questions and calculates cooking time based on:

