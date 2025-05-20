# 🔊 Monitoring Sound Level Meter

This project is part of a data science initiative aimed at monitoring and analyzing environmental sound levels using a sound level meter. The goal is to collect, process, and visualize sound data to assess noise pollution and its potential effects on health and comfort, particularly in workspaces or urban environments.

---

## 📌 Project Objectives

- Monitor noise levels over a period using a sound level meter.
- Identify patterns and peak noise intervals.
- Provide actionable insights for noise reduction strategies.
- Support data-driven decision making to improve environmental comfort.

---

## 🗃 Dataset Overview

The sound level data was collected from a physical sound level meter device capable of logging decibel readings over time. The dataset includes:

- **Timestamp**: Date and time of measurement
- **Sound Level (dB)**: Decibel value of noise level at a given moment

---

## 🧰 Tools & Technologies Used

- **Python** – Core programming language for data processing
- **pandas** – Data wrangling and cleaning
- **matplotlib** & **seaborn** – Data visualization
- **Jupyter Notebook** – Analysis and report generation
- **Sound Meter Device** – Hardware used for real-world data collection

---

## 📊 Data Analysis Process

### 🔹 Data Collection
- Sound levels were recorded over a defined period using a calibrated sound level meter.
- The data was exported to CSV format for analysis.

### 🔹 Data Cleaning
- Checked for missing values, duplicates, or anomalous readings.
- Converted timestamps into appropriate datetime formats.

### 🔹 Feature Engineering
- Extracted time-based features (hour, day, etc.).
- Calculated average, minimum, and maximum sound levels per period.

### 🔹 Exploratory Data Analysis (EDA)
- Plotted trends of sound levels across hours and days.
- Identified high-noise periods (e.g., work hours, rush hours).
- Assessed variations between weekdays and weekends.

---

## 📈 Sample Visualizations

- Line plots showing daily noise trends
- Heatmaps identifying noise intensity by hour and day
- Bar charts comparing average dB levels across different time intervals

---

## 💡 Key Insights

- Certain time intervals consistently showed high sound levels, indicating potential sources of environmental stress.
- Patterns suggest correlations between noise peaks and specific activities or external factors (e.g., traffic, machinery).
- The analysis helps inform recommendations to improve noise management strategies.

---

## 🚀 Getting Started

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Cahyopw15/CahyoPrasetiyoWibowo-Project-Portfolio.git

2. ```bash
   cd CahyoPrasetiyoWibowo-Project-Portfolio/Project Data Science/Monitoring Sound Level Meter
3. ```bash
   pip install -r requirements.txt
4. ```bash
   jupyter notebook monitoring_sound_level_analysis.ipynb
