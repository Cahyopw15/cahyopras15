# 🧠 Chronic Condition Prediction from Depression Data

This project focuses on predicting the risk of chronic medical conditions using depression-related data. By combining demographic, lifestyle, and health history information, we aim to identify high-risk individuals and design personalized intervention strategies.

## 📌 Project Overview

- 📂 Dataset Source: [Kaggle - Depression Dataset](https://www.kaggle.com/datasets/anthonytherrien/depression-dataset/data)

---

## 🎯 Project Goals

- Predict the likelihood of developing chronic medical conditions based on individual attributes.
- Design personalized preventive strategies for high-risk individuals.

---

## 🧠 Dataset Summary

- **Rows:** 413,768
- **Columns:** 16
- **Variable Types:**
  - Demographics: Name, Age, Marital Status, Education Level
  - Lifestyle: Alcohol Use, Smoking Status, Physical Activity, Diet, Sleep Patterns
  - Socioeconomic: Income, Employment Status, Number of Children
  - Health History: Mental Illness, Substance Abuse, Family Depression, Chronic Conditions

✅ No missing or duplicated data found.

---

## 🛠 Feature Engineering

- **Encoding:** Categorical features encoded using Label Encoder.
- **New Features:**
  - `age_category` → categorized into teens, adults, seniors.
  - `lifestyle_score` → sum of lifestyle-related variables.
  - `health_score` → sum of health history-related variables.
- **Multicollinearity Check:** `lifestyle_score` had VIF = 6.59 but retained due to predictive value.
- **Data Split:** 
  - Train: 80%
  - Validation: 10%
  - Test: 10%
- **Target Variable:** `chronic_medical_conditions`

---

## 📊 Exploratory Data Analysis (EDA)

- **Target Class Imbalance:**  
  - Class 0: 277,561  
  - Class 1: 136,207
- **Key Insights:**
  - Low-income individuals have higher risk of chronic conditions.
  - A `health_score` of 0 correlates with no chronic condition; a score of 4 correlates with full incidence.
  - Mixed risk for scores 1–3, requiring further investigation.

---

## 🤖 Machine Learning Models

Models Used:
- Random Forest
- Logistic Regression
- Decision Tree
- K-Nearest Neighbors (KNN)
- XGBoost

**Evaluation Techniques:**
- Threshold tuning
- Confusion matrix analysis
- Hyperparameter tuning
- Feature importance analysis

---

## 📈 Feature Importance

Top contributing features:
- **Income** → 66.30%
- **Health Score** → 26.70%
- **Lifestyle Score** → 2.97%

---

## ✅ Best Model

- **Random Forest** showed the highest performance overall.
- Balanced in accuracy, precision, recall, and F1-score.
- Robust in handling class imbalance and capturing nonlinear relationships.

---

## 📌 Recommendations

### 1. Target Low-Income Individuals
- Offer subsidized/free preventive healthcare.
- Provide regular health check-ups and education.

### 2. Improve Health Scores via Preventive Programs
- Personalized interventions for those with low health scores.
- Collaborate with gyms, dietitians, and health platforms.

### 3. Promote a Healthy Lifestyle
- Campaigns to reduce smoking/alcohol and increase physical activity.
- Organize health seminars and workshops for communities.

---

## 👤 Author

**Cahyo Prasetiyo Wibowo**

---

## 🙏 Thank You!
